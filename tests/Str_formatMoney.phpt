--TEST--
UnifiedPHP\Str\formatMoney() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

setlocale(LC_MONETARY, 'en_US');

var_dump(Str\formatMoney(42, '%i'));
var_dump(@Str\formatMoney('', '%i'));
var_dump(@Str\formatMoney(42, ''));
var_dump(@Str\formatMoney(42, 420));
?>
--EXPECTF--
string(5) "42.00"
NULL
string(0) ""
string(3) "420"
