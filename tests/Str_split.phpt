--TEST--
UnifiedPHP\Str\split() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$str = 'a|b|c|d|e';

var_dump(implode(' ', Str\split($str, '|')));
var_dump(implode(' ', Str\split($str, '|', 3)));
var_dump(implode(' ', Str\split($str, '_')));
var_dump(implode(' ', Str\split($str, '|', -3)));
var_dump(implode(' ', Str\split($str, '|', 1)));
var_dump(implode(' ', Str\split($str, '|', 0)));
var_dump(@Str\split($str, ''));
var_dump(implode(' ', Str\split($str, '_', -1)));
?>
--EXPECTF--
string(9) "a b c d e"
string(9) "a b c|d|e"
string(9) "a|b|c|d|e"
string(3) "a b"
string(9) "a|b|c|d|e"
string(9) "a|b|c|d|e"
bool(false)
string(0) ""
