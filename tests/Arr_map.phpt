--TEST--
UnifiedPHP\Arr\map() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Arr;

function d($i)
{
    return 2*$i;
}

$a = range(1, 3);

var_dump(implode(' ', Arr\map($a, 'd')));
var_dump(implode(' ', Arr\map($a, function($i){return 10*$i;})));
?>
--EXPECTF--
string(5) "2 4 6"
string(8) "10 20 30"
