#ifndef UNIFIEDPHP_STR_STR_H
#define UNIFIEDPHP_STR_STR_H

#include "php.h"
#include "unifiedphp.h"

#define UNIFIEDPHP_NS_STR   UNIFIEDPHP_NS"\\Str"

/* {{{ Block for PHP_FUNCTION proto's
*/
#if PHP_VERSION_ID<50400
    #define UNIFIEDPHP_STR_PROTO_HEXTOBIN PHP_FUNCTION(hexToBin);
#else
    #define UNIFIEDPHP_STR_PROTO_HEXTOBIN
#endif

#define UNIFIEDPHP_STR_PROTO                \
    PHP_FUNCTION(cmp);                      \
    PHP_FUNCTION(cmpNat);                   \
    PHP_FUNCTION(cmpNatN);                  \
    PHP_FUNCTION(cmpNatNCase);              \
                                            \
    PHP_FUNCTION(padL);                     \
    PHP_FUNCTION(padR);                     \
                                            \
    PHP_FUNCTION(pos);                      \
    PHP_FUNCTION(posCase);                  \
    PHP_FUNCTION(posLast);                  \
    PHP_FUNCTION(posLastCase);              \
                                            \
    PHP_FUNCTION(find);                     \
    PHP_FUNCTION(findCase);                 \
    PHP_FUNCTION(findLast);                 \
    PHP_FUNCTION(findLastCase);             \
                                            \
    PHP_FUNCTION(replace);                  \
    PHP_FUNCTION(replaceCase);              \
                                            \
    PHP_FUNCTION(startsWith);               \
    PHP_FUNCTION(endsWith);                 \
                                            \
    PHP_FUNCTION(formatMoney);              \
    PHP_FUNCTION(split);                    \
    PHP_FUNCTION(crc32);                    \
    PHP_FUNCTION(htmlSpecialCharsDecode);   \
                                            \
    UNIFIEDPHP_STR_PROTO_HEXTOBIN           \
// #define UNIFIEDPHP_STR_PROTO
/* }}} */

/* {{{ Block for const zend_function_entry unifiedphp_functions[]
*/
#if PHP_VERSION_ID<50400
    #define UNIFIEDPHP_STR_FUNCTION_ENTRY_HEXTOBIN ZEND_NS_FE(UNIFIEDPHP_NS_STR, hexToBin, NULL)
#else
    #define UNIFIEDPHP_STR_FUNCTION_ENTRY_HEXTOBIN
#endif

#define UNIFIEDPHP_STR_FUNCTION_ENTRY                               \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmp, NULL)                        \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNat, NULL)                     \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNatN, NULL)                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, cmpNatNCase, NULL)                \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, padL, NULL)                       \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, padR, NULL)                       \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, pos, NULL)                        \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posCase, NULL)                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posLast, NULL)                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, posLastCase, NULL)                \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, find, NULL)                       \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findCase, NULL)                   \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findLast, NULL)                   \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, findLastCase, NULL)               \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, replace, arginfo_4_0001)          \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, replaceCase, arginfo_4_0001)      \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, startsWith, NULL)                 \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, endsWith, NULL)                   \
                                                                    \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, formatMoney, NULL)                \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, split, NULL)                      \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, crc32, NULL)                      \
    ZEND_NS_FE(UNIFIEDPHP_NS_STR, htmlSpecialCharsDecode, NULL)     \
                                                                    \
    UNIFIEDPHP_STR_FUNCTION_ENTRY_HEXTOBIN                          \
// #define UNIFIEDPHP_STR_FUNCTION_ENTRY
/* }}} */

/* {{{ Block for PHP_RINIT_FUNCTION(unifiedphp)
*/
#if PHP_VERSION_ID>=50400
    #define UNIFIEDPHP_STR_PHP_RINIT_FUNCTION_HEXTOBIN UNIFIEDPHP_FALIAS_STR("hexToBin", "hex2bin");
#else
    #define UNIFIEDPHP_STR_PHP_RINIT_FUNCTION_HEXTOBIN
#endif

#define UNIFIEDPHP_STR_PHP_RINIT_FUNCTION                                       \
    /* comparing */                                                             \
    /* PHP_FUNCTION(cmp); */                                                    \
    UNIFIEDPHP_FALIAS_STR("cmpN", "strncmp");                                   \
    UNIFIEDPHP_FALIAS_STR("cmpCase", "strcasecmp");                             \
    UNIFIEDPHP_FALIAS_STR("cmpNCase", "strncasecmp");                           \
    /* PHP_FUNCTION(cmpNat); */                                                 \
    UNIFIEDPHP_FALIAS_STR("cmpNatCase", "strnatcasecmp");                       \
    /* PHP_FUNCTION(cmpNatN); */                                                \
    /* PHP_FUNCTION(cmpNatNCase); */                                            \
    UNIFIEDPHP_FALIAS_STR("cmpLocale", "strcoll");                              \
    /* PHP_FUNCTION(startsWith); */                                             \
    /* PHP_FUNCTION(endsWith); */                                               \
                                                                                \
    /* find position */                                                         \
    /* PHP_FUNCTION(pos); */                                                    \
    /* PHP_FUNCTION(posCase); */                                                \
    /* PHP_FUNCTION(posLast); */                                                \
    /* PHP_FUNCTION(posLastCase); */                                            \
                                                                                \
    /* find substring */                                                        \
    /* PHP_FUNCTION(find); */                                                   \
    /* PHP_FUNCTION(findCase); */                                               \
    /* PHP_FUNCTION(findLast); */                                               \
    /* PHP_FUNCTION(findLastCase); */                                           \
                                                                                \
    /* fetch substring */                                                       \
    UNIFIEDPHP_FALIAS_STR("sub", "substr");                                     \
    UNIFIEDPHP_FALIAS_STR("subCount", "substr_count");                          \
    UNIFIEDPHP_FALIAS_STR("subReplace", "substr_replace");                      \
                                                                                \
    /* replacing */                                                             \
    /* PHP_FUNCTION(replace); */                                                \
    /* PHP_FUNCTION(replaceCase); */                                            \
                                                                                \
    /* statistics */                                                            \
    UNIFIEDPHP_FALIAS_STR("len", "strlen");                                     \
    UNIFIEDPHP_FALIAS_STR("wordsCount", "str_word_count");                      \
    UNIFIEDPHP_FALIAS_STR("charsCount", "count_chars");                         \
                                                                                \
    /* convert between formats */                                               \
    UNIFIEDPHP_FALIAS_STR("binToHex", "bin2hex");                               \
    UNIFIEDPHP_STR_PHP_RINIT_FUNCTION_HEXTOBIN                                  \
    UNIFIEDPHP_FALIAS_STR("uuEncode", "convert_uuencode");                      \
    UNIFIEDPHP_FALIAS_STR("uuDecode", "convert_uudecode");                      \
    UNIFIEDPHP_FALIAS_STR("NLToBR", "nl2br");                                   \
    UNIFIEDPHP_FALIAS_STR("base64Encode", "base64_encode");                     \
    UNIFIEDPHP_FALIAS_STR("base64Decode", "base64_decode");                     \
                                                                                \
    /* hashing & crypting */                                                    \
    UNIFIEDPHP_FALIAS_STR("rot13", "str_rot13");                                \
    /* PHP_FUNCTION(crc32); */                                                  \
    UNIFIEDPHP_FALIAS_STR("md5", "md5");                                        \
    UNIFIEDPHP_FALIAS_STR("md5File", "md5_file");                               \
    UNIFIEDPHP_FALIAS_STR("sha1", "sha1");                                      \
    UNIFIEDPHP_FALIAS_STR("sha1File", "sha1_file");                             \
                                                                                \
    /* formatting */                                                            \
    /* PHP_FUNCTION(formatMoney); */                                            \
    UNIFIEDPHP_FALIAS_STR("formatNumber", "number_format");                     \
    /*x UNIFIEDPHP_FALIAS_STR("sprintf", "sprintf"); */                         \
    /*x UNIFIEDPHP_FALIAS_STR("pack", "pack"); */                               \
    /*x UNIFIEDPHP_FALIAS_STR("unpack", "unpack"); */                           \
    UNIFIEDPHP_FALIAS_STR("slashesCAdd", "addcslashes");                        \
    UNIFIEDPHP_FALIAS_STR("slashesCTrim", "stripcslashes");                     \
    UNIFIEDPHP_FALIAS_STR("slashesAdd", "addslashes");                          \
    UNIFIEDPHP_FALIAS_STR("slashesTrim", "stripslashes");                       \
    UNIFIEDPHP_FALIAS_STR("toLower", "strtolower");                             \
    UNIFIEDPHP_FALIAS_STR("toUpper", "strtoupper");                             \
    UNIFIEDPHP_FALIAS_STR("firstCharCapital", "ucfirst");                       \
    UNIFIEDPHP_FALIAS_STR("firstCharLower", "lcfirst");                         \
    UNIFIEDPHP_FALIAS_STR("wordsCapital", "ucwords");                           \
    UNIFIEDPHP_FALIAS_STR("pad", "str_pad");                                    \
    /* PHP_FUNCTION(padL); */                                                   \
    /* PHP_FUNCTION(padR); */                                                   \
    UNIFIEDPHP_FALIAS_STR("trim", "trim");                                      \
    UNIFIEDPHP_FALIAS_STR("trimL", "ltrim");                                    \
    UNIFIEDPHP_FALIAS_STR("trimR", "rtrim");                                    \
                                                                                \
    /* html */                                                                  \
    UNIFIEDPHP_FALIAS_STR("htmlStripTags", "strip_tags");                       \
    UNIFIEDPHP_FALIAS_STR("htmlSpecialCharsEncode", "htmlspecialchars");        \
    /* PHP_FUNCTION(htmlSpecialCharsDecode); */                                 \
    UNIFIEDPHP_FALIAS_STR("htmlEntitiesEncode", "htmlentities");                \
    UNIFIEDPHP_FALIAS_STR("htmlEntitiesDecode", "html_entity_decode");          \
                                                                                \
    /* URL managment */                                                         \
    UNIFIEDPHP_FALIAS_STR("queryStringParse", "parse_str");                     \
    UNIFIEDPHP_FALIAS_STR("queryStringBuild", "http_build_query");              \
    UNIFIEDPHP_FALIAS_STR("urlParse", "parse_url");                             \
    /* ToDo: UNIFIEDPHP_FALIAS_STR("urlBuild", "http_build_url"); */            \
    UNIFIEDPHP_FALIAS_STR("urlEncode", "rawurlencode");                         \
    UNIFIEDPHP_FALIAS_STR("urlDecode", "rawurldecode");                         \
                                                                                \
    /* mix */                                                                   \
    UNIFIEDPHP_FALIAS_STR("getCSV", "str_getcsv");                              \
    UNIFIEDPHP_FALIAS_STR("repeat", "str_repeat");                              \
    UNIFIEDPHP_FALIAS_STR("shuffle", "str_shuffle");                            \
    UNIFIEDPHP_FALIAS_STR("splitByLen", "str_split");                           \
    /* PHP_FUNCTION(split); */                                                  \
    UNIFIEDPHP_FALIAS_STR("ord", "ord");                                        \
    UNIFIEDPHP_FALIAS_STR("chr", "chr");                                        \
    UNIFIEDPHP_FALIAS_STR("spn", "strspn");                                     \
    UNIFIEDPHP_FALIAS_STR("spnInv", "strcspn");                                 \
    UNIFIEDPHP_FALIAS_STR("tok", "strtok");                                     \
    UNIFIEDPHP_FALIAS_STR("rev", "strrev");                                     \
    UNIFIEDPHP_FALIAS_STR("tr", "strtr");                                       \
    UNIFIEDPHP_FALIAS_STR("findByMask", "strpbrk");                             \
// #define UNIFIEDPHP_STR_PHP_RINIT_FUNCTION
/* }}} */

#endif // UNIFIEDPHP_STR_STR_H
