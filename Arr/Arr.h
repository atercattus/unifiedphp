#ifndef UNIFIEDPHP_ARR_ARR_H
#define UNIFIEDPHP_ARR_ARR_H

#include "php.h"
#include "unifiedphp.h"

#define UNIFIEDPHP_NS_ARR   UNIFIEDPHP_NS"\\Arr"

/* {{{ Block for PHP_FUNCTION proto's
*/
#define UNIFIEDPHP_ARR_PROTO        \
    PHP_FUNCTION(map);              \
    PHP_FUNCTION(filter);           \
// #define UNIFIEDPHP_ARR_PROTO
/* }}} */

/* {{{ Block for const zend_function_entry unifiedphp_functions[]
*/
#define UNIFIEDPHP_ARR_FUNCTION_ENTRY                               \
    ZEND_NS_FE(UNIFIEDPHP_NS_ARR, map, NULL)                        \
    ZEND_NS_FE(UNIFIEDPHP_NS_ARR, filter, NULL)                     \
// #define UNIFIEDPHP_ARR_FUNCTION_ENTRY
/* }}} */

/* {{{ Block for PHP_RINIT_FUNCTION(unifiedphp)
*/
#define UNIFIEDPHP_ARR_PHP_RINIT_FUNCTION                           \
// #define UNIFIEDPHP_ARR_PHP_RINIT_FUNCTION
/* }}} */

#endif // UNIFIEDPHP_ARR_ARR_H
