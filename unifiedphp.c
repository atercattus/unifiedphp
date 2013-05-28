#include "unifiedphp.h"
#include "php.h"
#include "php_unifiedphp.h"

// \Str\*
PHP_FUNCTION(cmp);
PHP_FUNCTION(cmpNat);
PHP_FUNCTION(cmpNatN);
PHP_FUNCTION(cmpNatNCase);

PHP_FUNCTION(padL);
PHP_FUNCTION(padR);

PHP_FUNCTION(pos);
PHP_FUNCTION(posCase);
PHP_FUNCTION(posLast);
PHP_FUNCTION(posLastCase);

PHP_FUNCTION(find);
PHP_FUNCTION(findCase);
PHP_FUNCTION(findLast);
PHP_FUNCTION(findLastCase);

PHP_FUNCTION(replace);
PHP_FUNCTION(replaceCase);

PHP_FUNCTION(startsWith);
PHP_FUNCTION(endsWith);

PHP_FUNCTION(formatMoney);
PHP_FUNCTION(split);

#if PHP_VERSION_ID<50400
    PHP_FUNCTION(hexToBin);
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_replace, 0, 0, 3)
    ZEND_ARG_INFO(0, string)
    ZEND_ARG_INFO(0, search)
    ZEND_ARG_INFO(0, replace)
    ZEND_ARG_INFO(1, replace_count)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_replaceCase, 0, 0, 3)
    ZEND_ARG_INFO(0, string)
    ZEND_ARG_INFO(0, search)
    ZEND_ARG_INFO(0, replace)
    ZEND_ARG_INFO(1, replace_count)
ZEND_END_ARG_INFO()

// \Arr\*
PHP_FUNCTION(map);
PHP_FUNCTION(filter);

const zend_function_entry unifiedphp_functions[] = {
    // \Str\*
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmp, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNat, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNatN, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNatNCase, NULL)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, padL, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, padR, NULL)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, pos, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posCase, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posLast, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posLastCase, NULL)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, find, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findCase, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findLast, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findLastCase, NULL)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, replace, arginfo_replace)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, replaceCase, arginfo_replaceCase)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, startsWith, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, endsWith, NULL)

    ZEND_NS_FE(UNIFIEDPHP_NS_STR, formatMoney, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, split, NULL)

#if PHP_VERSION_ID<50400
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, hexToBin, NULL)
#endif

    // \Arr\*
    ZEND_NS_FE(UNIFIEDPHP_NS_ARR, map, NULL)
    ZEND_NS_FE(UNIFIEDPHP_NS_ARR, filter, NULL)

    ZEND_FE_END
};

PHP_RINIT_FUNCTION(unifiedphp);

zend_module_entry unifiedphp_module_entry = {
    STANDARD_MODULE_HEADER,
    UNIFIEDPHP_NAME,
    unifiedphp_functions,
    NULL,
    NULL,
    PHP_RINIT(unifiedphp),
    NULL,
    NULL,
    UNIFIEDPHP_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(unifiedphp)


#define UNIFIEDPHP_SLASH                    "\\"
#define UNIFIEDPHP_FALIAS_STR(t, f)         UNIFIEDPHP_FALIAS(UNIFIEDPHP_NS_STR UNIFIEDPHP_SLASH t, f)

#define UNIFIEDPHP_ZVAL_ARR_LEN(p)          (sizeof(p)/sizeof(zval*))

#define UNIFIEDPHP_ZVAL_STR(p,s)            zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_STRING(&zv_##p, s, 1);
#define UNIFIEDPHP_ZVAL_STR_L(p,s)          zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_STRINGL(&zv_##p, s, s##_len, 1);
#define UNIFIEDPHP_ZVAL_STR_DL(p)           UNIFIEDPHP_ZVAL_STR_L(p,p)

#define UNIFIEDPHP_ZVAL_LONG(p,v)           zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_LONG(&zv_##p, v);
#define UNIFIEDPHP_ZVAL_LONG_D(p)           UNIFIEDPHP_ZVAL_LONG(p,p)


PHP_RINIT_FUNCTION(unifiedphp)
{
    // comparing
    // PHP_FUNCTION(cmp);
    UNIFIEDPHP_FALIAS_STR("cmpN", "strncmp");
    UNIFIEDPHP_FALIAS_STR("cmpCase", "strcasecmp");
    UNIFIEDPHP_FALIAS_STR("cmpNCase", "strncasecmp");
    // PHP_FUNCTION(cmpNat);
    UNIFIEDPHP_FALIAS_STR("cmpNatCase", "strnatcasecmp");
    // PHP_FUNCTION(cmpNatN);
    // PHP_FUNCTION(cmpNatNCase);
    UNIFIEDPHP_FALIAS_STR("cmpLocale", "strcoll");
    // PHP_FUNCTION(startsWith);
    // PHP_FUNCTION(endsWith);

    // find position
    // PHP_FUNCTION(pos);
    // PHP_FUNCTION(posCase);
    // PHP_FUNCTION(posLast);
    // PHP_FUNCTION(posLastCase);

    // find substring
    // PHP_FUNCTION(find);
    // PHP_FUNCTION(findCase);
    // PHP_FUNCTION(findLast);
    // PHP_FUNCTION(findLastCase);

    // fetch substring
    UNIFIEDPHP_FALIAS_STR("sub", "substr");
    UNIFIEDPHP_FALIAS_STR("subCount", "substr_count");
    UNIFIEDPHP_FALIAS_STR("subReplace", "substr_replace");

    // replacing
    // PHP_FUNCTION(replace);
    // PHP_FUNCTION(replaceCase);

    // statistics
    UNIFIEDPHP_FALIAS_STR("len", "strlen");
    UNIFIEDPHP_FALIAS_STR("wordsCount", "str_word_count");
    UNIFIEDPHP_FALIAS_STR("charsCount", "count_chars");

    // convert between formats
    UNIFIEDPHP_FALIAS_STR("binToHex", "bin2hex");
#if PHP_VERSION_ID>=50400
    UNIFIEDPHP_FALIAS_STR("hexToBin", "hex2bin");
#else
    // PHP_FUNCTION(hexToBin);
#endif
    UNIFIEDPHP_FALIAS_STR("uuEncode", "convert_uuencode");
    UNIFIEDPHP_FALIAS_STR("uuDecode", "convert_uudecode");
    UNIFIEDPHP_FALIAS_STR("NLToBR", "nl2br");
    UNIFIEDPHP_FALIAS_STR("base64Encode", "base64_encode");
    UNIFIEDPHP_FALIAS_STR("base64Decode", "base64_decode");
    // ToDo: br2nl via pcre?

    // hashing & crypting
    UNIFIEDPHP_FALIAS_STR("rot13", "str_rot13");
    UNIFIEDPHP_FALIAS_STR("crc32", "crc32"); // ToDo: to return a string
    UNIFIEDPHP_FALIAS_STR("md5", "md5");
    UNIFIEDPHP_FALIAS_STR("md5File", "md5_file");
    UNIFIEDPHP_FALIAS_STR("sha1", "sha1");
    UNIFIEDPHP_FALIAS_STR("sha1File", "sha1_file");
    // ToDo: all from crypt() http://www.php.net/manual/en/function.crypt.php

    // formatting
    // PHP_FUNCTION(formatMoney);
    UNIFIEDPHP_FALIAS_STR("formatNumber", "number_format");
    //x UNIFIEDPHP_FALIAS_STR("sprintf", "sprintf");
    //x UNIFIEDPHP_FALIAS_STR("pack", "pack");
    //x UNIFIEDPHP_FALIAS_STR("unpack", "unpack"); // there is no common prefix pack/unpack
    UNIFIEDPHP_FALIAS_STR("slashesCAdd", "addcslashes");
    UNIFIEDPHP_FALIAS_STR("slashesCTrim", "stripcslashes");
    UNIFIEDPHP_FALIAS_STR("slashesAdd", "addslashes");
    UNIFIEDPHP_FALIAS_STR("slashesTrim", "stripslashes");
    UNIFIEDPHP_FALIAS_STR("toLower", "strtolower");
    UNIFIEDPHP_FALIAS_STR("toUpper", "strtoupper");
    UNIFIEDPHP_FALIAS_STR("firstCharCapital", "ucfirst");
    UNIFIEDPHP_FALIAS_STR("firstCharLower", "lcfirst");
    UNIFIEDPHP_FALIAS_STR("wordsCapital", "ucwords");
    // ToDo: lcwords ?
    UNIFIEDPHP_FALIAS_STR("pad", "str_pad");
    // PHP_FUNCTION(padL);
    // PHP_FUNCTION(padR);
    UNIFIEDPHP_FALIAS_STR("trim", "trim");
    UNIFIEDPHP_FALIAS_STR("trimL", "ltrim");
    UNIFIEDPHP_FALIAS_STR("trimR", "rtrim");

    // html
    UNIFIEDPHP_FALIAS_STR("htmlStripTags", "strip_tags");
    UNIFIEDPHP_FALIAS_STR("htmlSpecialCharsEncode", "htmlspecialchars");
    UNIFIEDPHP_FALIAS_STR("htmlSpecialCharsDecode", "htmlspecialchars_decode"); // ToDo: where is parameter $encoding?
    UNIFIEDPHP_FALIAS_STR("htmlEntitiesEncode", "htmlentities");
    UNIFIEDPHP_FALIAS_STR("htmlEntitiesDecode", "html_entity_decode");

    // URL managment (?)
    UNIFIEDPHP_FALIAS_STR("queryStringParse", "parse_str");
    UNIFIEDPHP_FALIAS_STR("queryStringBuild", "http_build_query");
    UNIFIEDPHP_FALIAS_STR("urlParse", "parse_url");
    //UNIFIEDPHP_FALIAS_STR("urlBuild", "http_build_url"); // ToDo: (PECL pecl_http >= 0.21.0) implement itself
    UNIFIEDPHP_FALIAS_STR("urlEncode", "rawurlencode");
    UNIFIEDPHP_FALIAS_STR("urlDecode", "rawurldecode");

    // mix
    UNIFIEDPHP_FALIAS_STR("getCSV", "str_getcsv");
    UNIFIEDPHP_FALIAS_STR("repeat", "str_repeat");
    UNIFIEDPHP_FALIAS_STR("shuffle", "str_shuffle");
    UNIFIEDPHP_FALIAS_STR("splitByLen", "str_split");
    // ToDo: combine "chunk_split" and "wordwrap" to one function
    // PHP_FUNCTION(split);
    UNIFIEDPHP_FALIAS_STR("ord", "ord");
    UNIFIEDPHP_FALIAS_STR("chr", "chr");
    UNIFIEDPHP_FALIAS_STR("spn", "strspn");
    UNIFIEDPHP_FALIAS_STR("spnInv", "strcspn");
    UNIFIEDPHP_FALIAS_STR("tok", "strtok");
    UNIFIEDPHP_FALIAS_STR("rev", "strrev");
    UNIFIEDPHP_FALIAS_STR("tr", "strtr");
    UNIFIEDPHP_FALIAS_STR("findByMask", "strpbrk"); // ugly name

    return SUCCESS;
}

#include "Str/cmp.c"
#include "Str/pad.c"
#include "Str/pos.c"
#include "Str/find.c" // uses pos.c
#include "Str/replace.c"
#include "Str/format.c"
#include "Str/_mix.c"

#include "Arr/map.c"
#include "Arr/filter.c"
