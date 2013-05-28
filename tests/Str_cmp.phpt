--TEST--
UnifiedPHP\Str\cmp() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(0 === Str\cmp('hello', 'world'));
var_dump(0 === Str\cmp('foo', 'foo'));
var_dump(0 === Str\cmp('foo', 'fOO'));
var_dump(0 === Str\cmp('foo', 'fOO', 1)); // only first char
var_dump(0 === Str\cmp('foo', 'fOO', 0, true)); // case insensitive
var_dump(0 === Str\cmp('foo', 'fOO', -1)); // negative len
var_dump(0 === Str\cmp('', ''));
?>
--EXPECTF--
bool(false)
bool(true)
bool(false)
bool(true)
bool(true)
bool(false)
bool(false)
