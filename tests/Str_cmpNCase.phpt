--TEST--
UnifiedPHP\Str\cmpNCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'abcdef';

var_dump(0 === Str\cmpNCase($haystack, '',    0));
var_dump(0 === Str\cmpNCase($haystack, 'abc', 3));
var_dump(0 === Str\cmpNCase($haystack, 'abC', 3));
var_dump(0 === Str\cmpNCase($haystack, 'abZ', 2));
var_dump(0 === Str\cmpNCase($haystack, 'abZ', 3));
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
bool(false)
