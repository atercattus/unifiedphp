--TEST--
UnifiedPHP\Str\cmpNatNCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(0 === Str\cmpNatNCase('a10001b', 'A10002b', 3));
var_dump(0 >=  Str\cmpNatNCase('a10001b', 'A10002b', 7));
var_dump(0 <=  Str\cmpNatNCase('a10002b', 'A10001b', 7));
var_dump(0 <=  Str\cmpNatNCase('a10002b', 'A10001b', 0));
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
