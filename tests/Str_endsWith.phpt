--TEST--
UnifiedPHP\Str\endsWith() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\endsWith('', ''));
var_dump(Str\endsWith($haystack, 'TP'));
var_dump(Str\endsWith($haystack, 'tp'));
var_dump(Str\endsWith($haystack, 'ETP'));
var_dump(Str\endsWith($haystack, ''));
?>
--EXPECTF--
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)
