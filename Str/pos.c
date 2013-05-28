static long _unifiedphp_pos(UNIFIEDPHP_STR_PARAM(haystack), UNIFIEDPHP_STR_PARAM(needle), long offset, zend_bool case_insens, zend_bool last, INTERNAL_FUNCTION_PARAMETERS)
{
    char *func_names[] = {"strpos", "stripos", "strrpos", "strripos"};
    int idx = (int)!!case_insens + ((int)!!last << 1);
    int pos = -1;

    int res;
    UNIFIEDPHP_CUF_START(func_names[idx])
        UNIFIEDPHP_ZV_STR(haystack),
        UNIFIEDPHP_ZV_STR(needle),
        unifiedphp_zv_long(offset)
    UNIFIEDPHP_CUF_END(res, 1)

    if (res == SUCCESS) {
        if (Z_TYPE_P(return_value) == IS_LONG) {
            pos = Z_LVAL_P(return_value);
        }
        else if (Z_TYPE_P(return_value) == IS_BOOL) {
            // do nothing
        }
        else {
            php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unexpected return_value type for %s", func_names[idx]);
        }
    }
    // else {} // already pos = -1

    RETVAL_NULL();

    return pos;
}

#define UNIFIEDPHP_PHP_FUNCTION_pos_call(case_insens, last) \
    int pos = _unifiedphp_pos(UNIFIEDPHP_STR_CALL(haystack), UNIFIEDPHP_STR_CALL(needle), offset, (case_insens), (last), INTERNAL_FUNCTION_PARAM_PASSTHRU); \
    if (pos<0) { \
        RETURN_FALSE; \
    } \
    else { \
        RETURN_LONG(pos); \
    }

/* {{{ proto int|bool pos(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $last=false]]])
 */
PHP_FUNCTION(pos)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(needle)
    long offset = 0;
    zend_bool case_insens = 0;
    zend_bool last = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lbb", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset, &case_insens, &last) == FAILURE) {
        return;
    }

    UNIFIEDPHP_PHP_FUNCTION_pos_call(case_insens, last)
}
/* }}} */

#define UNIFIEDPHP_PHP_FUNCTION_posSmth(case_insens, last) \
    UNIFIEDPHP_STR_DEFINE(haystack) \
    UNIFIEDPHP_STR_DEFINE(needle) \
    long offset = 0; \
    \
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|l", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset) == FAILURE) { \
        return; \
    } \
    \
    UNIFIEDPHP_PHP_FUNCTION_pos_call((case_insens), (last))

/* {{{ proto int|bool posCase(string $haystack, string $needle[, int $offset=0])
    Equals: pos($haystack, $needle[, int $offset=0], true, false)
 */
PHP_FUNCTION(posCase)
{
    UNIFIEDPHP_PHP_FUNCTION_posSmth(1, 0)
}
/* }}} */

/* {{{ proto int|bool posLast(string $haystack, string $needle[, int $offset=0])
    Equals: pos($haystack, $needle[, int $offset=0], false, true)
 */
PHP_FUNCTION(posLast)
{
    UNIFIEDPHP_PHP_FUNCTION_posSmth(0, 1)
}
/* }}} */

/* {{{ proto int|bool posLastCase(string $haystack, string $needle[, int $offset=0])
    Equals: pos($haystack, $needle[, int $offset=0], true, true)
 */
PHP_FUNCTION(posLastCase)
{
    UNIFIEDPHP_PHP_FUNCTION_posSmth(1, 1)
}
/* }}} */
