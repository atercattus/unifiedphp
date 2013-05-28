--TEST--
UnifiedPHP\Str\cmpNatN() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(0 === Str\cmpNatN('a10001b', 'a10002b', 3));
var_dump(0 >=  Str\cmpNatN('a10001b', 'a10002b', 7));
var_dump(0 <=  Str\cmpNatN('a10002b', 'a10001b', 7));
var_dump(0 <=  Str\cmpNatN('a10002b', 'a10001b', 0));
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
