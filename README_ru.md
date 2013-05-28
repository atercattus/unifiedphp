unifiedphp
==========

[![Build Status](https://travis-ci.org/AterCattus/unifiedphp.png)](https://travis-ci.org/AterCattus/unifiedphp)

Расширение для PHP 5.3+, предоставляющее унифицированные по именам и параметрам базовые функции работы со строками и массивами.

## Причины появления

Существующая в PHP система именования фактически системой не является:

* разное положение 'str' части именования (или вообще его отсутствие): <b>str</b>len, sub<b>str</b>, ucfirst;
* случайное использование _ (подчеркивания): str_replace, strspn;
* смешение 2/to: nl<b>2</b>br, str<b>to</b>upper;
* различное указание case insensitive: str<b>case</b>cmp/str_<b>i</b>replace;
* нелогичное именование "парных" функций: parse_str/http_build_query или strstr/strrchr;
* или вообще отсутствие ожидаемой функции: strchr/strrchr => stristr/ ~~реализация отсутствует~~;
* разное именование схожих по функционалу функций: str_word_count/count_chars;
* близкие по реализации, но такие непохожие: chunk_split/wordwrap;
* и т.д.

Передача параметров так же не однородна:

* разная позиция передачи исходной строки: array_chunk(<b>array $input</b>, int ...) / array_search(mixed $needle, <b>array $haystack</b>...) или explode(string $delimiter, <b>string $string</b>...) / str_repeat(<b>string $input</b>, int...);
* разные параметры в "парных" функциях: strchr($haystack, $needle<b>[,$before_needle]</b>) / strrchr($haystack, $needle <b>?</b>).

Конечно, можно сделать всё на уровне чистого PHP (абстрактные примеры):
```php
function wordCount($str /*[, *$format=0[, $charlist]]*/)
{
    return \call_user_func_array("\\str_word_count", \func_get_args());
}

function padL($str, $pad_length, $pad_string=' ')
{
    return \str_pad($str, $pad_length, $pad_string, STR_PAD_LEFT);
}
```
Но падение производительности с таким подходом нивелирует удобство использования.

Решить проблему имен можно и через [runkit_function_copy](http://www.php.net/manual/en/function.runkit-function-copy.php), но в целом этого не достаточно, да и есть определенные проблемы.

## Что предлагается взамен

Реализация в соответствующих типам namespace'ах всего нужного функционала, например:
```php
use UnifiedPHP\Str;
use UnifiedPHP\Arr;

Str\len('foo');
Str\padL('bar', 20);
Str\findCase('hello world', 'WORLD');
Str\endsWith('UnifiedPHP', 'PHP');

Arr\filter(Arr\range(20), function($i){return $i%2;});
```
* Именование функций в camelCase (хоть это и не строго обязательно ввиду особенностей PHP);
* Целевая переменная (та, над которой выполняется операция) всегда передается первым параметром;
    * Исключения: Str\tok;
* Функции одной группы имеют общий префикс в имени: cmp*, find*, sub*, html*, queryString* и т.п. (подробнее ниже);
    * Исключения: Str\startsWith / Str\endsWith.

### Строковые функции

| Функция | PHP аналог |
|---------|------------|
| Сравнение строк | |
| int **Str\cmp**(string $str1, string $str2[, int $len=0[, bool $case_insens=false[, int $s1_offset=0]]]) | [strcmp](http://php.net/manual/en/function.strcmp.php), [strncmp](http://php.net/manual/en/function.strncmp.php), [strcasecmp](http://php.net/manual/en/function.strcasecmp.php), [substr_compare](http://php.net/manual/en/function.substr_compare.php) |
| int **Str\cmpN**(string $str1, string $str2, int $len)                                      | [strncmp](http://php.net/manual/en/function.strncmp.php)<br/>**Str\cmp**($str1, $str2, $len, false, 0) |
| int **Str\cmpCase**(string $str1, string $str2) | [strcasecmp](http://php.net/manual/en/function.strcasecmp.php)<br/>**Str\cmp**($str1, $str2, 0, true, 0) |
| int **Str\cmpNCase**(string $str1, string $str2, int $len) | [strncasecmp](http://php.net/manual/en/function.strncasecmp.php)<br/>**Str\cmp**($str1, $str2, $len, true, 0) |
| int **Str\cmpNat**(string $str1, string $str2, int $len=0, bool $case_insens=false) | [strnatcmp](http://php.net/manual/en/function.strnatcmp.php), [strnatcasecmp](http://php.net/manual/en/function.strnatcasecmp.php) с поддержкой $len |
| int **Str\cmpNatN**(string $str1, string $str2, int $len) | [strnatcmp](http://php.net/manual/en/function.strnatcmp.php) с поддержкой $len<br/>**Str\cmpNat**($str1, $str2, $len, false, 0) |
| int **Str\cmpNatCase**(string $str1, string $str2) | [strnatcasecmp](http://php.net/manual/en/function.strnatcasecmp.php)<br/>**Str\cmpNat**($str1, $str2, 0, true, 0) |
| int **Str\cmpNatNCase**(string $str1, string $str2, int $len) | [strnatcasecmp](http://php.net/manual/en/function.strnatcasecmp.php) с поддержкой $len<br/>**Str\cmpNat**($str1, $str2, $len, true, 0) |
| int **Str\cmpLocale**(string $str1, string $str2) | [strcoll](http://php.net/manual/en/function.strcoll.php) |
| bool **Str\startsWith**(string $haystack, string $prefix) | !\strncmp($haystack, $prefix, \strlen($prefix)) |
| bool **Str\endsWith**(string $haystack, string $suffix) | \substr($haystack, -\strlen($prefix)) == $prefix |
| Поиск позиции | |
| int&#124;bool **Str\pos**(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $last=false]]]) | [strpos](http://php.net/manual/en/function.strpos.php), [stripos](http://php.net/manual/en/function.stripos.php), [strrpos](http://php.net/manual/en/function.strrpos.php), [strripos](http://php.net/manual/en/function.strripos.php) |
| int&#124;bool **Str\posCase**(string $haystack, string $needle[, int $offset=0]) | [stripos](http://php.net/manual/en/function.stripos.php)<br/>**Str\pos**($haystack, $needle, $offset, true, false) |
| int&#124;bool **Str\posLast**(string $haystack, string $needle[, int $offset=0]) | [strrpos](http://php.net/manual/en/function.strrpos.php)<br/>**Str\pos**($haystack, $needle, $offset, false, true) |
| int&#124;bool **Str\posLastCase**(string $haystack, string $needle[, int $offset=0]) | [strripos](http://php.net/manual/en/function.strripos.php)<br/>**Str\pos**($haystack, $needle, $offset, true, true) |
| Поиск с выборкой подстроки | |
| str&#124;bool **Str\find**(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $last=false[, bool $before_needle=false]]]]) | [strstr/strchr](http://php.net/manual/en/function.strstr.php), [stristr](http://php.net/manual/en/function.stristr.php), [strrchr](http://php.net/manual/en/function.strrchr.php), несуществующая strristr |
| string&#124;bool **Str\findCase**(string $haystack, string $needle[, int $offset=0[, bool $last=false[, bool $before_needle=false]]]) | [stristr](http://php.net/manual/en/function.stristr.php)<br/>**Str\find**($haystack, $needle, $offset, true, $last, $before_needle) |
| string&#124;bool **Str\findLast**(string $haystack, string $needle[, int $offset=0[, bool $case_insens=false[, bool $before_needle=false]]]) | [strrchr](http://php.net/manual/en/function.strrchr.php)<br/>**Str\find**($haystack, $needle, $offset, $case_insens, true, $before_needle) |
| string&#124;bool **Str\findLastCase**(string $haystack, string $needle[, int $offset=0[, bool $before_needle=false]]) | **Str\find**($haystack, $needle, $offset, true, true, $before_needle) |
| string **Str\findByMask**(string $haystack, string $char_list) | [strpbrk](http://php.net/manual/en/function.strpbrk.php) |
| Обработка подстроки | |
| string **Str\sub**(string $string, int $start[, int $length]) | [substr](http://php.net/manual/en/function.substr.php) |
| string **Str\subCount**(string $haystack, string $needle[, int $offset=0[, int $length]]) | [substr_count](http://php.net/manual/en/function.substr-count.php) |
| string **Str\subReplace**(mixed $string, mixed $replacement, mixed $start[, mixed $length]) | [substr_replace](http://php.net/manual/en/function.substr-replace.php) |
| Замены | |
| mixed **Str\replace**(mixed $string, mixed $search, mixed $replace[, int &$count]) | [str_replace](http://php.net/manual/en/function.str-replace.php)<br/>$string идет первым параметром, а не третьим |
| mixed **Str\replaceCase**(mixed $string, mixed $search, mixed $replace[, int &$count]) | [str_ireplace](http://php.net/manual/en/function.str-ireplace.php)<br/>$string идет первым параметром, а не третьим |
| Статистика | |
| string **Str\len**(string $string) | [strlen](http://php.net/manual/en/function.strlen.php) |
| string **Str\wordsCount**(string $string[, int $format=0[, string $charlist]]) | [str_word_count](http://php.net/manual/en/function.str-word-count.php) |
| string **Str\charsCount**(string $string[, int $mode=0]) | [count_chars](http://php.net/manual/en/function.count-chars.php) |
| Конвертация между форматами | |
| string **Str\binToHex**(string $string) | [bin2hex](http://php.net/manual/en/function.bin2hex.php) |
| string **Str\hexToBin**(string $string) | [hex2bin](http://php.net/manual/en/function.hex2bin.php) |
| string **Str\uuEncode**(string $string) | [convert_uuencode](http://php.net/manual/en/function.convert-uuencode.php) |
| string **Str\uuDecode**(string $string) | [convert_uudecode](http://php.net/manual/en/function.convert-uudecode.php) |
| string **Str\NLToBR**(string $string[, bool $is_xhtml=true]) | [nl2br](http://php.net/manual/en/function.nl2br.php) |
| string **Str\base64Encode**(string $string) | [base64_encode](http://php.net/manual/en/function.base64-encode.php) |
| string **Str\base64Decode**(string $string[, bool $strict=false]) | [base64_decode](http://php.net/manual/en/function.base64-decode.php) |
| Хеширование и шифрование | |
| string **Str\rot13**(string $string) | [str_rot13](http://php.net/manual/en/function.str_rot13.php) |
| string **Str\crc32**(string $string) | [crc32](http://php.net/manual/en/function.crc32.php) |
| string **Str\md5**(string $string[, bool $raw_output=false]) | [md5](http://php.net/manual/en/function.md5.php) |
| string **Str\md5File**(string $filename[, bool $raw_output=false]) | [md5_file](http://php.net/manual/en/function.md5-file.php) |
| string **Str\sha1**(string $string[, bool $raw_output=false]) | [sha1](http://php.net/manual/en/function.sha1.php) |
| string **Str\sha1File**(string $filename[, bool $raw_output=false]) | [sha1_file](http://php.net/manual/en/function.sha1-file.php) |
| Форматирование строки | |
| string **Str\formatMoney**(float $number, string $format) | [money_format](http://php.net/manual/en/function.money-format.php)<br/>$number идет первым параметром |
| string **Str\formatNumber**(float $number[, int $decimals=0[, string $dec_point='.'[, string $thousands_sep=',']]]) | [number_format](http://php.net/manual/en/function.number-format.php) |
| string **Str\slashesCAdd**(string $string, string $charlist) | [addcslashes](http://php.net/manual/en/function.addcslashes.php) |
| string **Str\slashesCTrim**(string $string) | [stripcslashes](http://php.net/manual/en/function.stripcslashes.php) |
| string **Str\slashesAdd**(string $string) | [addslashes](http://php.net/manual/en/function.addslashes.php) |
| string **Str\slashesTrim**(string $string) | [stripslashes](http://php.net/manual/en/function.stripslashes.php) |
| string **Str\toLower**(string $string) | [strtolower](http://php.net/manual/en/function.strtolower.php) |
| string **Str\toUpper**(string $string) | [strtoupper](http://php.net/manual/en/function.strtoupper.php) |
| string **Str\firstCharCapital**(string $string) | [ucfirst](http://php.net/manual/en/function.ucfirst.php) |
| string **Str\firstCharLower**(string $string) | [lcfirst](http://php.net/manual/en/function.lcfirst.php) |
| string **Str\wordsCapital**(string $string) | [ucwords](http://php.net/manual/en/function.ucwords.php) |
| string **Str\pad**(string $string, int $pad_length[, string $pad_string=' '[, int $pad_type=STR_PAD_RIGHT]]) | [str_pad](http://php.net/manual/en/function.str-pad.php) |
| string **Str\padL**(string $string, int $pad_length[, string $pad_string=' ']) | Str\pad($input, $pad_length, $pad_string, STR_PAD_LEFT) |
| string **Str\padR**(string $string, int $pad_length[, string $pad_string=' ']) | Str\pad($input, $pad_length, $pad_string[, STR_PAD_RIGHT]) |
| string **Str\trim**(string $string[, string $charlist]) | [trim](http://php.net/manual/en/function.trim.php) |
| string **Str\trimL**(string $string[, string $charlist]) | [ltrim](http://php.net/manual/en/function.ltrim.php) |
| string **Str\trimR**(string $string[, string $charlist]) | [rtrim](http://php.net/manual/en/function.rtrim.php) |
| HTML | |
| string **Str\htmlStripTags**(string $string[, string $allowable_tags]) | [strip_tags](http://php.net/manual/en/function.strip-tags.php) |
| string **Str\htmlSpecialCharsEncode**(string $string[, int $flags=ENT_COMPAT&#124;ENT_HTML401[, string $encoding='UTF-8'[, bool $double_encode=true]]]) | [htmlspecialchars](http://php.net/manual/en/function.htmlspecialchars.php) |
| string **Str\htmlSpecialCharsDecode**(string $string[, int $flags=ENT_COMPAT&#124;ENT_HTML401]) | [htmlspecialchars_decode](http://php.net/manual/en/function.htmlspecialchars-decode.php) |
| string **Str\htmlEntitiesEncode**(string $string[, int $flags=ENT_COMPAT&#124;ENT_HTML401[, string $encoding='UTF-8'[, bool $double_encode=true]]]) | [htmlentities](http://php.net/manual/en/function.htmlentities.php) |
| string **Str\htmlEntitiesDecode**(string $string[, int $flags=ENT_COMPAT&#124;ENT_HTML401[, string $encoding='UTF-8']]) | [html_entity_decode](http://php.net/manual/en/function.html-entity-decode.php) |
| Работа с URL | |
| string **Str\queryStringParse**(string $string[, array &$arr]) | [parse_str](http://php.net/manual/en/function.parse-str.php) |
| string **Str\queryStringBuild**(mixed $query_data[, string $numeric_prefix[, string $arg_separator[, int $enc_type=PHP_QUERY_RFC1738]]]) | [http_build_query](http://php.net/manual/en/function.http-build-query.php) |
| string **Str\urlParse**(string $url[, int $component=-1]) | [parse_url](http://php.net/manual/en/function.parse-url.php) |
| ~~string **Str\urlBuild**([mixed $url[, mixed $parts[, int $flags=HTTP_URL_REPLACE[, array &$new_url]]]])~~ | [http_build_url](http://php.net/manual/en/function.http-build-url.php) |
| string **Str\urlEncode**(string $string) | [rawurlencode](http://php.net/manual/en/function.rawurlencode.php) |
| string **Str\urlDecode**(string $string) | [rawurldecode](http://php.net/manual/en/function.rawurldecode.php) |
| Вне категорий | |
| string **Str\getCSV**(string $string[, string $delimiter=','[, string $enclosure='"'[, string $escape='\\']]]) | [str_getcsv](http://php.net/manual/en/function.str-getcsv.php) |
| string **Str\repeat**(string $string, int $multiplier) | [str_repeat](http://php.net/manual/en/function.str-repeat.php) |
| string **Str\shuffle**(string $string) | [str_shuffle](http://php.net/manual/en/function.str-shuffle.php) |
| string **Str\split**(string $string, string $delimiter[, int $limit])~~ | [explode](http://php.net/manual/en/function.explode.php)<br/>$string идет первым параметром |
| string **Str\splitByLen**(string $string[, int $split_length=1]) | [str_split](http://php.net/manual/en/function.str-split.php) |
| string **Str\ord**(string $string) | [ord](http://php.net/manual/en/function.ord.php) |
| string **Str\chr**(int $ascii) | [chr](http://php.net/manual/en/function.chr.php) |
| string **Str\spn**(string $subject, string $mask[, int $start[, int $length]]) | [strspn](http://php.net/manual/en/function.strspn.php) |
| string **Str\spnInv**(string $subject, string $mask[, int $start[, int $length]] ) | [strcspn](http://php.net/manual/en/function.strcspn.php) |
| string **Str\tok**([string $string, ]string $token) | [strtok](http://php.net/manual/en/function.strtok.php) |
| string **Str\rev**(string $string) | [strrev](http://php.net/manual/en/function.strrev.php) |
| string **Str\tr**(string $string, string $from, string $to)<br/>string **Str\tr**(string $string, array $replace_pairs) | [strtr](http://php.net/manual/en/function.strtr.php) |
