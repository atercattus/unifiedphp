--TEST--
UnifiedPHP\Str\posLastCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

var_dump(Str\posLastCase($haystack, 't'));
var_dump(Str\posLastCase($haystack, 'T'));
var_dump(Str\posLastCase($haystack, 't', 6));
var_dump(Str\posLastCase($haystack, 'Q'));
var_dump(Str\posLastCase($haystack, '@'));

?>
--EXPECTF--
int(11)
int(11)
int(11)
int(0)
bool(false)
