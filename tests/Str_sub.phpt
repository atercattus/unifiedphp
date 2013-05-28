--TEST--
UnifiedPHP\Str\sub() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = '0123456789';

var_dump(Str\sub($haystack, 7));
var_dump(Str\sub($haystack, -3));
var_dump(Str\sub($haystack, 7, 0));
var_dump(Str\sub($haystack, 7, 2));
var_dump(Str\sub($haystack, -5, 2));
var_dump(Str\sub($haystack, 20));
var_dump(Str\sub($haystack, -3, 5));
var_dump(Str\sub($haystack, -3, -5));
?>
--EXPECTF--
string(3) "789"
string(3) "789"
string(0) ""
string(2) "78"
string(2) "56"
bool(false)
string(3) "789"
string(0) ""
