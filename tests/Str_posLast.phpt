--TEST--
UnifiedPHP\Str\posLast() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\posLast($haystack, 't'));
var_dump(Str\posLast($haystack, 'T'));
var_dump(Str\posLast($haystack, 't', 6));
?>
--EXPECTF--
int(4)
int(11)
bool(false)
