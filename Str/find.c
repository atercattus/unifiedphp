#define UNIFIEDPHP_PHP_FUNCTION_findX(case_insens, last, before_needle) \
    int pos = _unifiedphp_pos(UNIFIEDPHP_STR_CALL(haystack), UNIFIEDPHP_STR_CALL(needle), offset, (case_insens), (last), INTERNAL_FUNCTION_PARAM_PASSTHRU); \
    if (pos<0) { \
        RETURN_FALSE; \
    } \
    else { \
        long offs = (before_needle) ? 0 : pos; \
        long len = (before_needle) ? pos : haystack_len-pos; \
        \
        RETURN_STRINGL(&haystack[offs], len, 1); \
    }

/* {{{ proto str|bool find(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $last=false[, bool $before_needle=false]]]])
 */
PHP_FUNCTION(find)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(needle)
    long offset = 0;
    zend_bool case_insens = 0;
    zend_bool last = 0;
    zend_bool before_needle = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lbbb", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset, &case_insens, &last, &before_needle) == FAILURE) {
        return;
    }

    UNIFIEDPHP_PHP_FUNCTION_findX(case_insens, last, before_needle)
}
/* }}} */

/* {{{ proto str|bool findLast(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $before_needle=false]]])
    Equals: find($haystack, $needle, $offset, $case_insens, true, $before_needle)
 */
PHP_FUNCTION(findLast)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(needle)
    long offset = 0;
    zend_bool case_insens = 0;
    zend_bool before_needle = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lbb", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset, &case_insens, &before_needle) == FAILURE) {
        return;
    }

    UNIFIEDPHP_PHP_FUNCTION_findX(case_insens, 1, before_needle)
}
/* }}} */

/* {{{ proto str|bool findCase(string $haystack, string $needle[, int $offset=0[, bool $last=false[, bool $before_needle=false]]])
    Equals: find($haystack, $needle, $offset, true, $last, $before_needle)
 */
PHP_FUNCTION(findCase)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(needle)
    long offset = 0;
    zend_bool last = 0;
    zend_bool before_needle = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lbb", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset, &last, &before_needle) == FAILURE) {
        return;
    }

    UNIFIEDPHP_PHP_FUNCTION_findX(1, last, before_needle)
}
/* }}} */

/* {{{ proto str|bool findLastCase(string $haystack, string $needle[, int $offset=0[, bool $before_needle=false]])
    Equals: find($haystack, $needle, $offset, true, true, $before_needle)
 */
PHP_FUNCTION(findLastCase)
{
    UNIFIEDPHP_STR_DEFINE(haystack)
    UNIFIEDPHP_STR_DEFINE(needle)
    long offset = 0;
    zend_bool before_needle = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lb", UNIFIEDPHP_STR_CALLP(haystack), UNIFIEDPHP_STR_CALLP(needle), &offset, &before_needle) == FAILURE) {
        return;
    }

    UNIFIEDPHP_PHP_FUNCTION_findX(1, 1, before_needle)
}
/* }}} */
