--TEST--
UnifiedPHP\Str\cmpNatCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(0 === Str\cmpNatCase('a10001b', 'A10001B'));
var_dump(0 === Str\cmpNatCase('a10001b', 'A10002b'));
var_dump(0 >=  Str\cmpNatCase('a10001b', 'A10002b'));
var_dump(0 <=  Str\cmpNatCase('a10002b', 'A10001b'));
?>
--EXPECTF--
bool(true)
bool(false)
bool(true)
bool(true)
