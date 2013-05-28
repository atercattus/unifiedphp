--TEST--
UnifiedPHP\Str\cmpN() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'abcdef';

var_dump(0 === Str\cmpN($haystack, '', 0));
var_dump(0 === Str\cmpN($haystack, '', 1));
var_dump(0 === Str\cmpN($haystack, 'abC', 2));
var_dump(0 === Str\cmpN($haystack, 'abC', 3));
?>
--EXPECTF--
bool(true)
bool(false)
bool(true)
bool(false)
