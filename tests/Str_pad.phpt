--TEST--
UnifiedPHP\Str\pad() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(Str\pad('foo', 3) === 'foo');
var_dump(Str\pad('foo', 5, ' ', STR_PAD_RIGHT) === Str\pad('foo', 5, ' '));
var_dump(Str\pad('foo', 10, 'Zz') === 'fooZzZzZzZ');
var_dump(Str\pad('foo', 10, 'Zz', STR_PAD_LEFT) === 'ZzZzZzZfoo');
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
