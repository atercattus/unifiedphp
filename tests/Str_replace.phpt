--TEST--
UnifiedPHP\Str\replace() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$str = 'Hello World';

// str, str, str
var_dump(Str\replace($str, 'World', 'PHP'));
var_dump(Str\replace($str, 'world', 'PHP'));

$c = 0;
var_dump(Str\replace($str, 'o', '', $c));
var_dump($c);

// str, array, str
$vowels = array('a', 'e', 'i', 'o', 'u');
var_dump(Str\replace($str, $vowels, ''));

// str, array(N), array(1)
$repl = array('X');
var_dump(Str\replace($str, $vowels, $repl));

// str, array(N), array(N)
$repl = array_fill(0, count($vowels), '_');
var_dump(Str\replace($str, $vowels, $repl));

// str, array(1), array(N)
var_dump(Str\replace($str, array('o'), $repl));

// str, array(N), array(M)
$repl = array_fill(0, 2, '_');
var_dump(Str\replace($str, $vowels, $repl));

// array, ...
var_dump(implode('|', Str\replace(array('foo', 'bar', 'spam'), $vowels, '_')));
?>
--EXPECTF--
string(9) "Hello PHP"
string(11) "Hello World"
string(9) "Hell Wrld"
int(2)
string(8) "Hll Wrld"
string(8) "Hll Wrld"
string(11) "H_ll_ W_rld"
string(11) "Hell_ W_rld"
string(9) "H_ll Wrld"
string(12) "f__|b_r|sp_m"
