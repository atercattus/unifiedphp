/* {{{ proto string|null formatMoney(float $number, string $format)
 */
PHP_FUNCTION(formatMoney)
{
    double number;
    UNIFIEDPHP_STR_DEFINE(format)

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ds", &number, UNIFIEDPHP_STR_CALLP(format)) == FAILURE) {
        return;
    }

    int res;
    UNIFIEDPHP_CUF_START("money_format")
        UNIFIEDPHP_ZV_STR(format),
        unifiedphp_zv_double(number)
    UNIFIEDPHP_CUF_END(res, 1)

    if (res != SUCCESS) {
        RETURN_NULL();
    }
}
/* }}} */
