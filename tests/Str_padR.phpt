--TEST--
UnifiedPHP\Str\padR() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(Str\padR('foo', 3) === 'foo');
var_dump(Str\padR('foo', 4) === 'foo ');
var_dump(Str\padR('foo', 5, 'Z') === 'fooZZ');
var_dump(Str\padR('foo', 10, 'Zz') === 'fooZzZzZzZ');
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
