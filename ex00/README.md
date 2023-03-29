
# ex00

## about

与えられたCSV形式のデータベースには、時間経過とともにビットコインの価格が格納されています。
日付と価格のペアが入力ファイルに与えられ、プログラムは指定された日付のビットコインの価格を検索して、入力価格と掛け算して標準出力に表示する必要があります。
プログラム名は「btc」で、コンテナを使用してエラーを適切に処理する必要があります。
入力ファイルは、各行が「日付|価格」の形式である必要があります。
日付は常に「年-月-日」の形式であり、価格は0から1000までの正の整数または浮動小数点数でなければなりません。

## subject

> You have to create a program which outputs the value of a certain amount of bitcoin on a certain date.
This program must use a database in csv format which will represent bitcoin price over time. This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates to evaluate.

> ある日のある量のビットコインの価値を出力するプログラムを作成する必要があります。
このプログラムでは、ビットコインの価格を時系列で表したcsv形式のデータベースを使用する必要があります。このデータベースは、本課題で提供される。
このプログラムは、評価するために異なる価格/日付を格納した2番目のデータベースを入力として受け取ります。

> Your program must respect these rules:
The program name is btc.
Your program must take a file as argument.
Each line in this file must use the following format: "date | value".
A valid date will always be in the following format: Year-Month-Day.
A valid value must be either a float or a positive integer between 0 and 1000.

> あなたのプログラムは、これらのルールを尊重しなければなりません：
プログラム名はbtcとする。
あなたのプログラムは、引数としてファイルを受け取らなければならない。
このファイルの各行は、次の形式を使用しなければならない： "日付｜値"。
有効な日付は、常に次の形式である： 年-月-日。
有効な値は、浮動小数点数または0〜1000の正の整数でなければなりません。

> You must use at least one container in your code to validate this exercise. You should handle possible errors with an appropriate error message.

> この検証を行うには、コード内で少なくとも1つのコンテナを使用する必要があります。の演習を行います。起こりうるエラーは、適切な のエラーメッセージが表示されます。

> Here is an example of an input.txt file:

> 以下は、input.txtファイルの例です：

```
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
```


> Your program will use the value in your input file and the associated date.
Your program must display on the standard output the result of the value multiplied by the exchange rate according to the date indicated in your database.
The following is an example of the program’s use.

> あなたのプログラムは、入力ファイルの値と関連する日付を使用します。
あなたのプログラムは、値にデータベースに示された日付に応じた為替レートを掛けた結果を標準出力に表示しなければなりません。
以下は、プログラムの使用例である。

```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```

> Warning: The container(s) you use to validate this exercise will no longer be usable for the rest of this module.

> 警告 この演習を検証するために使用したコンテナは、このモジュールの残りの部分で使用できなくなります。

## review

- キーとバリューを保持できるからmapを使った