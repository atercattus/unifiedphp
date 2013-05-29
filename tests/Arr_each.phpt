--TEST--
UnifiedPHP\Arr\each() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Arr;

function d(&$item, $key)
{
    $item += $key;
}

$a = range(1, 10);

var_dump(implode(' ', Arr\each($a, 'd')));
var_dump(implode(' ', $a));
var_dump(implode(' ', Arr\each($a, function(&$item, $key, $mul){$item *= $mul;}, 7)));
var_dump(implode(' ', $a));
?>
--EXPECTF--
string(24) "1 3 5 7 9 11 13 15 17 19"
string(20) "1 2 3 4 5 6 7 8 9 10"
string(28) "7 14 21 28 35 42 49 56 63 70"
string(20) "1 2 3 4 5 6 7 8 9 10"
