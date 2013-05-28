--TEST--
UnifiedPHP\Str\replaceCase() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$str = 'Hello WORLD';

// str, str, str
var_dump(Str\replaceCase($str, 'World', 'PHP'));
var_dump(Str\replaceCase($str, 'world', 'PHP'));

$c = 0;
var_dump(Str\replaceCase($str, 'o', '', $c));
var_dump($c);

// str, array, str
$vowels = array('a', 'e', 'i', 'o', 'u');
var_dump(Str\replaceCase($str, $vowels, ''));

// str, array(N), array(1)
$repl = array('X');
var_dump(Str\replaceCase($str, $vowels, $repl));

// str, array(N), array(N)
$repl = array_fill(0, count($vowels), '_');
var_dump(Str\replaceCase($str, $vowels, $repl));

// str, array(1), array(N)
var_dump(Str\replaceCase($str, array('o'), $repl));

// str, array(N), array(M)
$repl = array_fill(0, 2, '_');
var_dump(Str\replaceCase($str, $vowels, $repl));

// array, ...
var_dump(implode('|', Str\replaceCase(array('FOO', 'BAR', 'SPAM'), $vowels, '_')));
?>
--EXPECTF--
string(9) "Hello PHP"
string(9) "Hello PHP"
string(9) "Hell WRLD"
int(2)
string(8) "Hll WRLD"
string(8) "Hll WRLD"
string(11) "H_ll_ W_RLD"
string(11) "Hell_ W_RLD"
string(9) "H_ll WRLD"
string(12) "F__|B_R|SP_M"
