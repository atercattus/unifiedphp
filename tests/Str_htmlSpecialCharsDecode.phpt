--TEST--
UnifiedPHP\Str\htmlSpecialCharsDecode() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>
--FILE--
<?php
use \UnifiedPHP\Str;

$text = <<<'END'
latin &amp;'&quot;&lt;&gt; кириллица utf8
END;

var_dump(Str\htmlSpecialCharsDecode($text));
?>
--EXPECTF--
string(35) "latin &'"<> кириллица utf8"
