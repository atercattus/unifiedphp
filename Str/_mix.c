#include "ext/standard/crc32.h"
#include "ext/standard/basic_functions.h"
#include "ext/standard/html.h"

/* {{{ proto bool startsWith(string $haystack, string $prefix)
 */
PHP_FUNCTION(startsWith)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(prefix)

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(prefix)) == FAILURE) {
        return;
    }

    if (haystack_len < prefix_len) {
        RETURN_FALSE;
    }

    RETURN_BOOL(!memcmp(haystack, prefix, prefix_len));
}
/* }}} */

/* {{{ proto bool endsWith(string $haystack, string $suffix)
 */
PHP_FUNCTION(endsWith)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(suffix)

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(suffix)) == FAILURE) {
        return;
    }

    if (haystack_len < suffix_len) {
        RETURN_FALSE;
    }

    RETURN_BOOL(!memcmp(&haystack[haystack_len-suffix_len], suffix, suffix_len));
}
/* }}} */

/* {{{ proto array|bool split(string $string, string $delimiter[, int $limit])
 */
PHP_FUNCTION(split)
{
    UNIFIEDPHP_STR_DEFINE(string)
    UNIFIEDPHP_STR_DEFINE(delimiter)
    long limit;
    int argc = ZEND_NUM_ARGS();

    if (zend_parse_parameters(argc TSRMLS_CC, "ss|l", UNIFIEDPHP_STR_CALLP(string), UNIFIEDPHP_STR_CALLP(delimiter), &limit) == FAILURE) {
        return;
    }

    char *func = "explode";

    int res;
    if (argc<3) {
        UNIFIEDPHP_CUF_START(func)
            UNIFIEDPHP_ZV_STR(delimiter),
            UNIFIEDPHP_ZV_STR(string)
        UNIFIEDPHP_CUF_END(res, 1)
    }
    else {
        UNIFIEDPHP_CUF_START(func)
            UNIFIEDPHP_ZV_STR(delimiter),
            UNIFIEDPHP_ZV_STR(string),
            unifiedphp_zv_long(limit)
        UNIFIEDPHP_CUF_END(res, 1)
    }

    if (res != SUCCESS) {
        RETURN_FALSE;
    }
}
/* }}} */

#if PHP_VERSION_ID<50400
/* {{{ php_hex2bin
    PHP_5_5/ext/standard/string.c
 */
static char *_unifiedphp_hex2bin(const unsigned char *old, const size_t oldlen, size_t *newlen)
{
    size_t target_length = oldlen >> 1;
    register unsigned char *str = (unsigned char *)safe_emalloc(target_length, sizeof(char), 1);
    size_t i, j;
    for (i = j = 0; i < target_length; i++) {
        char c = old[j++];
        if (c >= '0' && c <= '9') {
            str[i] = (c - '0') << 4;
        } else if (c >= 'a' && c <= 'f') {
            str[i] = (c - 'a' + 10) << 4;
        } else if (c >= 'A' && c <= 'F') {
            str[i] = (c - 'A' + 10) << 4;
        } else {
            efree(str);
            return NULL;
        }
        c = old[j++];
        if (c >= '0' && c <= '9') {
            str[i] |= c - '0';
        } else if (c >= 'a' && c <= 'f') {
            str[i] |= c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            str[i] |= c - 'A' + 10;
        } else {
            efree(str);
            return NULL;
        }
    }
    str[target_length] = '\0';

    if (newlen)
        *newlen = target_length;

    return (char *)str;
}
/* }}} */

/* {{{ proto string hexToBin(string $data)
   Converts the hex representation of data to binary
   PHP_5_5/ext/standard/string.c
*/
PHP_FUNCTION(hexToBin)
{
    UNIFIEDPHP_STR_DEFINE(str)
    char *result;
    size_t newlen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", UNIFIEDPHP_STR_CALLP(str)) == FAILURE) {
        return;
    }

    if (str_len % 2 != 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Hexadecimal input string must have an even length");
        RETURN_FALSE;
    }

    result = _unifiedphp_hex2bin((unsigned char *)str, str_len, &newlen);

    if (!result) {
        RETURN_FALSE;
    }

    RETURN_STRINGL(result, newlen, 0);
}
/* }}} */
#endif // PHP_VERSION_ID<50400

/* {{{ proto string crc32(string $data)
   Calculates the crc32 polynomial of a string
   PHP_5_5/ext/standard/crc32.c
*/
PHP_FUNCTION(crc32)
{
    UNIFIEDPHP_STR_DEFINE(s)
    php_uint32 crcinit = 0;
    register php_uint32 crc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", UNIFIEDPHP_STR_CALLP(s)) == FAILURE) {
        return;
    }

    crc = crcinit^0xFFFFFFFF;

    for (; s_len--; ++s) {
        crc = ((crc >> 8) & 0x00FFFFFF) ^ crc32tab[(crc ^ (*s)) & 0xFF];
    }

    char *buf = emalloc(12);
    sprintf(buf, "%u", (crc^0xFFFFFFFF));
    RETURN_STRING(buf, 0);
}
/* }}} */

/* {{{ proto string htmlSpecialCharsDecode(string $string[, int $flags = ENT_COMPAT|ENT_HTML401[, string $encoding = 'UTF-8']])
   Convert special HTML entities back to characters
*/
PHP_FUNCTION(htmlSpecialCharsDecode)
{
    UNIFIEDPHP_STR_DEFINE(str)
    long quote_style = ENT_COMPAT|ENT_HTML401;
    UNIFIEDPHP_STR_DEFINE(encoding)
    size_t new_len = 0;
    char *replaced;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|ls", UNIFIEDPHP_STR_CALLP(str), &quote_style, UNIFIEDPHP_STR_CALLP(encoding)) == FAILURE) {
        return;
    }

    replaced = php_unescape_html_entities(UNIFIEDPHP_STR_CALL(str), &new_len, 0 /*!all*/, quote_style, encoding TSRMLS_CC);
    if (replaced) {
        RETURN_STRINGL(replaced, (int)new_len, 0);
    }
    RETURN_FALSE;
}
/* }}} */
