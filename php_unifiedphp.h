#ifndef PHP_UNIFIEDPHP_H
#define PHP_UNIFIEDPHP_H

#include "php.h"

#ifndef ZEND_FE_END
    #define ZEND_FE_END     { NULL, NULL, NULL, 0, 0 }
#endif

#define UNIFIEDPHP_STR_DEFINE(p)        char *p=NULL; int p##_len=0;
#define UNIFIEDPHP_STR_PARAM(p)         char *p, int p##_len
#define UNIFIEDPHP_STR_CALL(p)          p, p##_len
#define UNIFIEDPHP_STR_CALLP(p)         &p, &p##_len

#define UNIFIEDPHP_ZV_STR(s) unifiedphp_zv_strl((s), strlen(s))

#define UNIFIEDPHP_ZV_FREE(zv) FREE_ZVAL(zv)

zval *unifiedphp_zv_strl(const char *s, int s_len);
zval *unifiedphp_zv_long(long l);
zval *unifiedphp_zv_bool(zend_bool b);
zval *unifiedphp_zv_double(double d);
zval *unifiedphp_zv_zval_p(zval *zv, zend_bool copy, zend_bool dtor);

int unifiedphp_copy_function(UNIFIEDPHP_STR_PARAM(fname), UNIFIEDPHP_STR_PARAM(dname) TSRMLS_DC);

#define UNIFIEDPHP_FALIAS(t, f)         unifiedphp_copy_function((f), strlen((f)), (t), strlen((t)) TSRMLS_CC)

#define UNIFIEDPHP_CUF_START(f) \
    do { \
        zval *__func_name = unifiedphp_zv_strl((f), strlen(f)); \
        zval* __argv[] = {

#define UNIFIEDPHP_CUF_END(int_res, free_mem) \
        }; \
        int __argc = sizeof(__argv)/sizeof(zval*); \
        int_res = call_user_function(CG(function_table), NULL, __func_name, return_value, __argc, __argv TSRMLS_CC); \
        if (free_mem) {int i; for (i=0; i<__argc; ++i){ UNIFIEDPHP_ZV_FREE(__argv[i]); }} \
        UNIFIEDPHP_ZV_FREE(__func_name); \
    } while(0);

#endif // PHP_UNIFIEDPHP_H
