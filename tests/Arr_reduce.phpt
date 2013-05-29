--TEST--
UnifiedPHP\Arr\reduce() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Arr;

function d($res, $item)
{
    return $res + $item;
}

$arr = range(1, 9);

var_dump(Arr\reduce($arr, 'd'));
var_dump(Arr\reduce($arr, function($res, $item){return $res*$item;}, 1));
?>
--EXPECTF--
int(45)
int(362880)
