--TEST--
UnifiedPHP\Str\findCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

// case insensitive
var_dump(Str\findCase($haystack, 't'));
var_dump(Str\findCase($haystack, 'T'));
?>
--EXPECTF--
string(9) "tyuiopeTP"
string(9) "tyuiopeTP"
