--TEST--
UnifiedPHP\Str\posCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\posCase($haystack, 'T'));
var_dump(Str\posCase($haystack, 't', 5));
?>
--EXPECTF--
int(4)
int(11)
