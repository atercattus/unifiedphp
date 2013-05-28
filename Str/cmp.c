static int _unifiedphp_cmp(UNIFIEDPHP_STR_PARAM(s1), UNIFIEDPHP_STR_PARAM(s2), long len, zend_bool case_insens, long s1_offset, INTERNAL_FUNCTION_PARAMETERS)
{
    if (len<0)
    {
        RETURN_FALSE;
    }
    else if (!len)
    {
        len = MAX(s1_len, s2_len);
        if (!len) {
            RETURN_LONG(1);
        }
    }

    int res;
    UNIFIEDPHP_CUF_START("substr_compare")
        UNIFIEDPHP_ZV_STR(s1),
        UNIFIEDPHP_ZV_STR(s2),
        unifiedphp_zv_long(s1_offset),
        unifiedphp_zv_long(len),
        unifiedphp_zv_bool(case_insens)
    UNIFIEDPHP_CUF_END(res, 1)

    if (res != SUCCESS) {
        RETURN_FALSE;
    }
}

/* {{{ proto int cmp(string $str1, string $str2[, int $len=0[, bool $case_insens=false[, int $s1_offset]]])
 */
PHP_FUNCTION(cmp)
{
    UNIFIEDPHP_STR_DEFINE(s1)
    UNIFIEDPHP_STR_DEFINE(s2)
    long len = 0;
    zend_bool case_insens = 0;
    long s1_offset = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lbl", UNIFIEDPHP_STR_CALLP(s1), UNIFIEDPHP_STR_CALLP(s2), &len, &case_insens, &s1_offset) == FAILURE) {
        return;
    }

    _unifiedphp_cmp(UNIFIEDPHP_STR_CALL(s1), UNIFIEDPHP_STR_CALL(s2), len, case_insens, s1_offset, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

static void _unifiedphp_cmpNat(UNIFIEDPHP_STR_PARAM(s1), UNIFIEDPHP_STR_PARAM(s2), long len, zend_bool case_insens, INTERNAL_FUNCTION_PARAMETERS)
{
    if (len > 0) {
        s1_len = MIN(s1_len, len);
        s2_len = MIN(s2_len, len);
    }

    int res;
    UNIFIEDPHP_CUF_START((case_insens?"strnatcasecmp":"strnatcmp"))
        unifiedphp_zv_strl(UNIFIEDPHP_STR_CALL(s1)),
        unifiedphp_zv_strl(UNIFIEDPHP_STR_CALL(s2))
    UNIFIEDPHP_CUF_END(res, 1)

    if (res != SUCCESS) {
        RETURN_FALSE;
    }
}

/* {{{ proto int cmpNat(string $str1, string $str2, int $len=0, bool $case_insens=false)
 */
PHP_FUNCTION(cmpNat)
{
    UNIFIEDPHP_STR_DEFINE(s1)
    UNIFIEDPHP_STR_DEFINE(s2)
    long len = 0;
    zend_bool case_insens = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|lb", UNIFIEDPHP_STR_CALLP(s1), UNIFIEDPHP_STR_CALLP(s2), &len, &case_insens) == FAILURE) {
        return;
    }

    _unifiedphp_cmpNat(UNIFIEDPHP_STR_CALL(s1), UNIFIEDPHP_STR_CALL(s2), len, case_insens, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

#define UNIFIEDPHP_PHP_FUNCTION_cmpNatNX(case_insens) \
    UNIFIEDPHP_STR_DEFINE(s1) \
    UNIFIEDPHP_STR_DEFINE(s2) \
    long len = 0; \
    \
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ssl", UNIFIEDPHP_STR_CALLP(s1), UNIFIEDPHP_STR_CALLP(s2), &len) == FAILURE) { \
        return; \
    } \
    \
    _unifiedphp_cmpNat(UNIFIEDPHP_STR_CALL(s1), UNIFIEDPHP_STR_CALL(s2), len, (case_insens), INTERNAL_FUNCTION_PARAM_PASSTHRU);

/* {{{ proto int cmpNatN(string $str1, string $str2, int $len)
 */
PHP_FUNCTION(cmpNatN)
{
    UNIFIEDPHP_PHP_FUNCTION_cmpNatNX(0)
}
/* }}} */

/* {{{ proto int cmpNatNCase(string $str1, string $str2, int $len)
 */
PHP_FUNCTION(cmpNatNCase)
{
    UNIFIEDPHP_PHP_FUNCTION_cmpNatNX(1)
}
/* }}} */
