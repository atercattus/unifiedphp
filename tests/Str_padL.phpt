--TEST--
UnifiedPHP\Str\padL() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

var_dump(Str\padL('foo', 3) === 'foo');
var_dump(Str\padL('foo', 4) === ' foo');
var_dump(Str\padL('foo', 5, 'Z') === 'ZZfoo');
var_dump(Str\padL('foo', 10, 'Zz') === 'ZzZzZzZfoo');
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(true)
