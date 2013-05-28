static void _unifiedphp_replace_common(int case_insens, INTERNAL_FUNCTION_PARAMETERS)
{
    zval **string, **search, **replace, **subject_entry, **count = NULL;

    int argc_glob = ZEND_NUM_ARGS();

    if (zend_parse_parameters(argc_glob TSRMLS_CC, "ZZZ|Z", &string, &search, &replace, &count) == FAILURE) {
        return;
    }

    char *func = case_insens?"str_ireplace":"str_replace";

    int res;
    if (argc_glob>3) {
        UNIFIEDPHP_CUF_START(func)
            *search,
            *replace,
            *string,
            *count
        UNIFIEDPHP_CUF_END(res, 0)
    }
    else {
        UNIFIEDPHP_CUF_START(func)
            *search,
            *replace,
            *string
        UNIFIEDPHP_CUF_END(res, 0)
    }

    if (res != SUCCESS) {
        RETURN_FALSE;
    }
}

/* {{{ proto mixed replace(mixed $string, mixed $search, mixed $replace[, int &$replace_count])
 */
PHP_FUNCTION(replace)
{
    _unifiedphp_replace_common(0, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ proto mixed replaceCase(mixed $string, mixed $search, mixed $replace[, int &$replace_count])
 */
PHP_FUNCTION(replaceCase)
{
    _unifiedphp_replace_common(1, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */
