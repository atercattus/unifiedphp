--TEST--
UnifiedPHP\Str\cmpLocale() function
--SKIPIF--
<?php require_once(__DIR__.'/skipif.inc'); ?>

<?php
// CP1251 locale is required
$ru_RU_cp1251 = 'ru_RU.CP1251';
if (false === stripos(@exec('locale -a|grep -i '.$ru_RU_cp1251), $ru_RU_cp1251)) echo "skip";

// CP1251 locale is required:
// echo -e "\nru_RU.CP1251 CP1251" >> /var/lib/locales/supported.d/ru
// locale-gen
?>
--FILE--
<?php
use \UnifiedPHP\Str;

function uw($s)
{
    return iconv('utf-8', 'CP1251', $s);
}

function wu($s)
{
    return iconv('CP1251', 'utf-8', $s);
}

function convsort($a)
{
    $a = array_map('uw', $a);
    usort($a, 'strcoll');
    $a = array_map('wu', $a);
    var_dump(implode(' ', $a));
}

$a = array('а', 'А', 'я', 'Я', 'ё', 'Ё'); // cyrillic UTF-8

var_dump(implode(' ', $a));

setlocale(LC_COLLATE, 'C');
convsort($a);

setlocale(LC_COLLATE, 'ru_RU.CP1251');
convsort($a);
?>
--EXPECTF--
string(17) "а А я Я ё Ё"
string(17) "Ё ё А Я а я"
string(17) "а А ё Ё я Я"
