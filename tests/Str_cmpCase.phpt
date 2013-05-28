--TEST--
UnifiedPHP\Str\cmpCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'abc';

var_dump(0 === Str\cmpCase($haystack, ''));
var_dump(0 === Str\cmpCase($haystack, 'abc'));
var_dump(0 === Str\cmpCase($haystack, 'abC'));
var_dump(0 === Str\cmpCase($haystack, 'abZ'));
?>
--EXPECTF--
bool(false)
bool(true)
bool(true)
bool(false)
