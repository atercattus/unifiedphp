--TEST--
UnifiedPHP. checking module namespaces
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
var_dump(\UnifiedPHP\Str\trim("x"));
?>
--EXPECTF--
string(1) "x"
