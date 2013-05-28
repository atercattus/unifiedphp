--TEST--
UnifiedPHP\Str\findLast() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\findLast($haystack, 'e'));
var_dump(Str\findLast($haystack, 't', 0, true)); // insensitive
?>
--EXPECTF--
string(3) "eTP"
string(2) "TP"
