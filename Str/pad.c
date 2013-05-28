// from ext/standard/string.c
#define STR_PAD_LEFT            0
#define STR_PAD_RIGHT           1
#define STR_PAD_BOTH            2

static void _unifiedphp_pad(UNIFIEDPHP_STR_PARAM(s), long pad_len, UNIFIEDPHP_STR_PARAM(s_pad), long pad_type, INTERNAL_FUNCTION_PARAMETERS)
{
    int res;
    if (s_pad_len) {
        UNIFIEDPHP_CUF_START("str_pad")
            unifiedphp_zv_strl(UNIFIEDPHP_STR_CALL(s)),
            unifiedphp_zv_long(pad_len),
            unifiedphp_zv_strl(UNIFIEDPHP_STR_CALL(s_pad)),
            unifiedphp_zv_long(pad_type)
        UNIFIEDPHP_CUF_END(res, 1)
    }
    else {
        UNIFIEDPHP_CUF_START("str_pad")
            unifiedphp_zv_strl(UNIFIEDPHP_STR_CALL(s)),
            unifiedphp_zv_long(pad_len)
        UNIFIEDPHP_CUF_END(res, 1)
    }

    if (res != SUCCESS) {
        RETURN_FALSE;
    }
}

#define UNIFIEDPHP_PHP_FUNCTION_padX(pad_type) \
    UNIFIEDPHP_STR_DEFINE(s) \
    long pad_len; \
    char *s_pad = " "; long s_pad_len=1; \
    \
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl|s", UNIFIEDPHP_STR_CALLP(s), &pad_len, UNIFIEDPHP_STR_CALLP(s_pad)) == FAILURE) { \
        return; \
    } \
    \
    _unifiedphp_pad(UNIFIEDPHP_STR_CALL(s), pad_len, UNIFIEDPHP_STR_CALL(s_pad), (pad_type), INTERNAL_FUNCTION_PARAM_PASSTHRU);

/* {{{ proto string padL(string $str, int $pad_length[, string $pad_string=' '])
 */
PHP_FUNCTION(padL)
{
    UNIFIEDPHP_PHP_FUNCTION_padX(STR_PAD_LEFT)
}
/* }}} */

/* {{{ proto string padR(string $str, int $pad_length[, string $pad_string=' '])
 */
PHP_FUNCTION(padR)
{
    UNIFIEDPHP_PHP_FUNCTION_padX(STR_PAD_RIGHT)
}
/* }}} */
