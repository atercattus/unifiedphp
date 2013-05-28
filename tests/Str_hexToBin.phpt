--TEST--
UnifiedPHP\Str\hexToBin() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

error_reporting(0); // A warning is thrown if the input string is of odd length.

var_dump(Str\hexToBin('6578616d706c65206865782064617461'));
var_dump(Str\hexToBin('6578616d706c6520686578206461746'));
?>
--EXPECTF--
string(16) "example hex data"
bool(false)
