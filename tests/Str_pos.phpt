--TEST--
UnifiedPHP\Str\pos() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$haystack = 'qwertyuiopeTP';

// base
var_dump(Str\pos($haystack, 'e'));
var_dump(Str\pos($haystack, 'TP'));
var_dump(Str\pos($haystack, 'O'));
// offset
var_dump(Str\pos($haystack, 'e', 4));
// case insensitive
var_dump(Str\pos($haystack, 'T', 0, true));
var_dump(Str\pos($haystack, 't', 5, true));
// last
var_dump(Str\pos($haystack, 'e', 0, false, true));
?>
--EXPECTF--
int(2)
int(11)
bool(false)
int(10)
int(4)
int(11)
int(10)
