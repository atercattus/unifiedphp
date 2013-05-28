--TEST--
UnifiedPHP\Str\subReplace() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

// base
var_dump(Str\subReplace('hello php', 'C', 6));
var_dump(Str\subReplace('0123456789', 'abc', 4));
// length
var_dump(Str\subReplace('0123456789', 'abc', 4, 3));
?>
--EXPECTF--
string(7) "hello C"
string(7) "0123abc"
string(10) "0123abc789"
