PHP_ARG_ENABLE(unifiedphp, Enable UnifiedPHP)

if test "$PHP_UNIFIEDPHP" = "yes"; then
    AC_DEFINE(HAVE_UNIFIEDPHP, 1, [You have UnifiedPHP extension])

    unifiedphp_sources="php_unifiedphp.c unifiedphp.c"

    PHP_NEW_EXTENSION(unifiedphp, $unifiedphp_sources, $ext_shared)
fi
