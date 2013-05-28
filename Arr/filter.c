/* {{{ proto array filter(array $array[, callable $callback=''])
 */
PHP_FUNCTION(filter)
{
    zval *arr,
         *cb=NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|z!", &arr, &cb) == FAILURE) {
        return;
    }

    if (cb) {
        char *error;
        zend_bool is_cb = zend_is_callable_ex(cb, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
        if (!is_cb) {
            zend_error(E_WARNING, "%s", error);
            efree(error);
            RETURN_NULL()
        }
    }

    char *func_name = "array_filter";

    int res;
    if (cb) {
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0),
            unifiedphp_zv_zval_p(cb, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }
    else {
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }
}
/* }}} */
