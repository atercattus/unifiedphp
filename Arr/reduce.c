/* {{{ proto mixed reduce(array $array, callable $callback[, mixed $initial = NULL])
 */
PHP_FUNCTION(reduce)
{
    int argc = ZEND_NUM_ARGS();
    zval *arr,
         *cb,
         *initial;

    if (zend_parse_parameters(argc TSRMLS_CC, "az|z", &arr, &cb, &initial) == FAILURE) {
        return;
    }

    char *error;
    zend_bool is_cb = zend_is_callable_ex(cb, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
    if (!is_cb) {
        zend_error(E_WARNING, "%s", error);
        efree(error);
        RETURN_NULL()
    }

    char *func_name = "array_reduce";

    if (argc < 3) {
        int res;
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0),
            unifiedphp_zv_zval_p(cb, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }
    else {
        int res;
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0),
            unifiedphp_zv_zval_p(cb, 0, 0),
            unifiedphp_zv_zval_p(initial, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }
}
/* }}} */
