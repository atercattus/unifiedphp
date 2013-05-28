--TEST--
UnifiedPHP\Arr\filter() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Arr;

function d($i)
{
    return $i & 1;
}

$a = range(1, 10);

var_dump(implode(' ', Arr\filter($a, 'd')));
var_dump(implode(' ', Arr\filter($a, function($i){return !($i % 3);})));
var_dump(implode(' ', Arr\filter(array(0, 1, 2, false, 4, '', 6, null, 8, array()))));
?>
--EXPECTF--
string(9) "1 3 5 7 9"
string(5) "3 6 9"
string(9) "1 2 4 6 8"
