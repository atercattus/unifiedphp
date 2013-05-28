--TEST--
UnifiedPHP\Str\findLastCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\findLastCase($haystack, 't'));
var_dump(Str\findLastCase($haystack, 'T'));
var_dump(Str\findLastCase($haystack, 'Y'));
?>
--EXPECTF--
string(2) "TP"
string(2) "TP"
string(8) "yuiopeTP"
