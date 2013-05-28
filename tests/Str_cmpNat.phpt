--TEST--
UnifiedPHP\Str\cmpNat() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$a = array('a1b', 'a2b', 'a10b', 'a11b', 'a3b');

sort($a);
echo implode(' ', $a),"\n";

usort($a, function($x, $y){return Str\cmpNat($x, $y);});
echo implode(' ', $a),"\n";
?>
--EXPECTF--
a10b a11b a1b a2b a3b
a1b a2b a3b a10b a11b
