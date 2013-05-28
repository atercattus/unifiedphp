--TEST--
UnifiedPHP\Str\find() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

// base
var_dump(Str\find($haystack, 't'));
var_dump(Str\find($haystack, 'T'));
// offset
var_dump(Str\find($haystack, 't', 5));
// case insensitive
var_dump(Str\find($haystack, 't', 5, true));
var_dump(Str\find($haystack, 'T', 0, true));
// last
var_dump(Str\find($haystack, 'e', 0, false));
var_dump(Str\find($haystack, 'e', 0, false, true));
// before_needle
var_dump(Str\find($haystack, 't', 0, false, false, false));
var_dump(Str\find($haystack, 't', 0, false, false, true));
?>
--EXPECTF--
string(9) "tyuiopeTP"
string(2) "TP"
bool(false)
string(2) "TP"
string(9) "tyuiopeTP"
string(11) "ertyuiopeTP"
string(3) "eTP"
string(9) "tyuiopeTP"
string(4) "qwer"
