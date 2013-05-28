#include "php.h"
#include "php_unifiedphp.h"

zval *unifiedphp_zv_strl(const char *s, int s_len)
{
    zval *res;
    MAKE_STD_ZVAL(res);
    ZVAL_STRINGL(res, s, s_len, 1);
    return res;
}

zval *unifiedphp_zv_long(long l)
{
    zval *res;
    MAKE_STD_ZVAL(res);
    ZVAL_LONG(res, l);
    return res;
}

zval *unifiedphp_zv_bool(zend_bool b)
{
    zval *res;
    MAKE_STD_ZVAL(res);
    ZVAL_BOOL(res, b);
    return res;
}

zval *unifiedphp_zv_double(double d)
{
    zval *res;
    MAKE_STD_ZVAL(res);
    ZVAL_DOUBLE(res, d);
    return res;
}

zval *unifiedphp_zv_zval_p(zval *zv, zend_bool copy, zend_bool dtor)
{
    zval *res;
    MAKE_STD_ZVAL(res);
    ZVAL_ZVAL(res, zv, copy, dtor);
    return res;
}

char *_unifiedphp_strtolower(UNIFIEDPHP_STR_PARAM(s))
{
    char *d = emalloc(s_len+1);
    memcpy(d, s, s_len+1);
    php_strtolower(d, s_len);
    return d;
}

int _unifiedphp_fetch_function(UNIFIEDPHP_STR_PARAM(fname), zend_function **pfe TSRMLS_DC)
{
    zend_function *fe;

    fname = _unifiedphp_strtolower(UNIFIEDPHP_STR_CALL(fname));

    if (zend_hash_find(EG(function_table), fname, fname_len + 1, (void**)&fe) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s() not found", fname);
        efree(fname);
        return FAILURE;
    }

    if ((fe->type != ZEND_USER_FUNCTION) && (fe->type != ZEND_INTERNAL_FUNCTION)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s() is not a user or normal internal function", fname);
        efree(fname);
        return FAILURE;
    }

    if (pfe) {
        *pfe = fe;
    }

    efree(fname);

    return SUCCESS;
}

int unifiedphp_copy_function(UNIFIEDPHP_STR_PARAM(fname), UNIFIEDPHP_STR_PARAM(dname) TSRMLS_DC)
{
    zend_function *fe;

    dname = _unifiedphp_strtolower(UNIFIEDPHP_STR_CALL(dname));

    if (zend_hash_exists(EG(function_table), dname, dname_len+1)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "%s() already exists", dname);
        efree(dname);
        return FAILURE;
    }

    if (_unifiedphp_fetch_function(UNIFIEDPHP_STR_CALL(fname), &fe TSRMLS_CC) == FAILURE) {
        efree(dname);
        return FAILURE;
    }

    if (fe->type == ZEND_USER_FUNCTION) {
        function_add_ref(fe);
    }
    //else {}

    if (zend_hash_add(EG(function_table), dname, dname_len + 1, fe, sizeof(zend_function), NULL) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unable to add reference to new function name %s()", dname);
        zend_function_dtor(fe);
        efree(dname);
        return FAILURE;
    }

    efree(dname);

    return SUCCESS;
}
