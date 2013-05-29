#include "unifiedphp.h"
#include "php.h"
#include "php_unifiedphp.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_4_0001, 0, 0, 3)
    ZEND_ARG_INFO(0, arg0)
    ZEND_ARG_INFO(0, arg1)
    ZEND_ARG_INFO(0, arg2)
    ZEND_ARG_INFO(1, arg3)
ZEND_END_ARG_INFO()

#include "Str/Str.h"
#include "Arr/Arr.h"

UNIFIEDPHP_STR_PROTO
UNIFIEDPHP_ARR_PROTO

const zend_function_entry unifiedphp_functions[] = {
    UNIFIEDPHP_STR_FUNCTION_ENTRY
    UNIFIEDPHP_ARR_FUNCTION_ENTRY

    ZEND_FE_END
};

PHP_RINIT_FUNCTION(unifiedphp);

zend_module_entry unifiedphp_module_entry = {
    STANDARD_MODULE_HEADER,
    UNIFIEDPHP_NAME,
    unifiedphp_functions,
    NULL,
    NULL,
    PHP_RINIT(unifiedphp),
    NULL,
    NULL,
    UNIFIEDPHP_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(unifiedphp)


#define UNIFIEDPHP_SLASH                    "\\"
#define UNIFIEDPHP_FALIAS_STR(t, f)         UNIFIEDPHP_FALIAS(UNIFIEDPHP_NS_STR UNIFIEDPHP_SLASH t, f)

#define UNIFIEDPHP_ZVAL_ARR_LEN(p)          (sizeof(p)/sizeof(zval*))

#define UNIFIEDPHP_ZVAL_STR(p,s)            zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_STRING(&zv_##p, s, 1);
#define UNIFIEDPHP_ZVAL_STR_L(p,s)          zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_STRINGL(&zv_##p, s, s##_len, 1);
#define UNIFIEDPHP_ZVAL_STR_DL(p)           UNIFIEDPHP_ZVAL_STR_L(p,p)

#define UNIFIEDPHP_ZVAL_LONG(p,v)           zval zv_##p; INIT_ZVAL(zv_##p); ZVAL_LONG(&zv_##p, v);
#define UNIFIEDPHP_ZVAL_LONG_D(p)           UNIFIEDPHP_ZVAL_LONG(p,p)

PHP_RINIT_FUNCTION(unifiedphp)
{
    UNIFIEDPHP_STR_PHP_RINIT_FUNCTION
    UNIFIEDPHP_ARR_PHP_RINIT_FUNCTION

    return SUCCESS;
}

#include "Str/Str.c"
#include "Arr/Arr.c"
