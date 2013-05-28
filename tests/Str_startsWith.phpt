--TEST--
UnifiedPHP\Str\startsWith() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\startsWith('', ''));
var_dump(Str\startsWith($haystack, 'qwe'));
var_dump(Str\startsWith($haystack, 'QWE'));
var_dump(Str\startsWith($haystack, 'qwz'));
var_dump(Str\startsWith($haystack, ''));
?>
--EXPECTF--
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)
