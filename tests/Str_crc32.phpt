--TEST--
UnifiedPHP\Str\crc32() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(Str\crc32(''));
var_dump(Str\crc32('The quick brown fox jumped over the lazy dog'));
?>
--EXPECTF--
string(1) "0"
string(10) "2765681502"
