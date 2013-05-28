/* {{{ proto array map(array $array, callable $callback)
 */
PHP_FUNCTION(map)
{
    zval *arr,
         *cb;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "az", &arr, &cb) == FAILURE) {
        return;
    }

    char *error;
    zend_bool is_cb = zend_is_callable_ex(cb, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
    if (!is_cb) {
        zend_error(E_WARNING, "%s", error);
        efree(error);
        RETURN_NULL()
    }

    int res;
    UNIFIEDPHP_CUF_START("array_map")
        unifiedphp_zv_zval_p(cb, 0, 0),
        unifiedphp_zv_zval_p(arr, 0, 0)
    UNIFIEDPHP_CUF_END(res, 1)
}
/* }}} */

