/* {{{ proto array each(array $array, callable $callback[, mixed $userdata = NULL])
 */
PHP_FUNCTION(each)
{
    int argc = ZEND_NUM_ARGS();
    zval *arr,
         *cb,
         *userdata = NULL;

    if (zend_parse_parameters(argc TSRMLS_CC, "A/z|z", &arr, &cb, &userdata) == FAILURE) {
        return;
    }

    char *error;
    zend_bool is_cb = zend_is_callable_ex(cb, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
    if (!is_cb) {
        zend_error(E_WARNING, "%s", error);
        efree(error);
        RETURN_NULL()
    }

    char *func_name = "array_walk";

    int res;
    if (argc < 3) {
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0),
            unifiedphp_zv_zval_p(cb, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }
    else {
        UNIFIEDPHP_CUF_START(func_name)
            unifiedphp_zv_zval_p(arr, 0, 0),
            unifiedphp_zv_zval_p(cb, 0, 0),
            unifiedphp_zv_zval_p(userdata, 0, 0)
        UNIFIEDPHP_CUF_END(res, 1)
    }

    if (res != SUCCESS) {
        RETURN_NULL();
    }
    else {
        RETURN_ZVAL(arr, 1, 0);
    }
}
/* }}} */

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
