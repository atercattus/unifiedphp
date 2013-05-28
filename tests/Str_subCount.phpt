--TEST--
UnifiedPHP\Str\subCount() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'abcXdXXeX';

// base
var_dump(Str\subCount($haystack, 'X'));
var_dump(Str\subCount($haystack, 'a'));
var_dump(Str\subCount($haystack, 'Z'));
var_dump(Str\subCount($haystack, 'XX'));
var_dump(@Str\subCount($haystack, ''));
// offset
var_dump(Str\subCount($haystack, 'X', 5));
var_dump(@Str\subCount($haystack, 'X', -2));
// length
var_dump(Str\subCount($haystack, 'X', 0, 6));
?>
--EXPECTF--
int(4)
int(1)
int(0)
int(1)
bool(false)
int(3)
bool(false)
int(2)
