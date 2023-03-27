# ex01

# subject 

> You must create a program with these constraints:
The program name is RPN.
Your program must take an inverted Polish mathematical expression as an argument.
The numbers used in this operation will always be less than 10.
Your program must process this expression and output the correct result on the standard output.
If an error occurs during the execution of the program an error message should be displayed on the standard output.
Your program must be able to handle operations with these tokens: "+ - / *".

> このような制約のあるプログラムを作成する必要があります：
プログラム名はRPNである。
プログラムは、ポーランド語の反転した数式を引数として受け取る必要があります。
この演算で使われる数値は常に10未満である。
あなたのプログラムはこの式を処理し、正しい結果を標準出力に出力しなければならない。
プログラムの実行中にエラーが発生した場合は、標準出力にエラーメッセージを表示する必要があります。
あなたのプログラムは、これらのトークンを使った演算を処理できなければならない： "+ - / *".

> You must use at least one container in your code to validate this exercise.

> この演習を検証するために、コード内で少なくとも1つのコンテナを使用する必要があります。

> You don’t need to manage the brackets or decimal numbers.

> 括弧や小数点以下の数字を管理する必要はありません。

> Here is an example of a standard use:

> 以下、標準的な使用例を示します：

```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "(1 + 1)"
Error
$>
```

> Warning: The container(s) you used in the previous exercise are forbidden here. The container(s) you used to validate this exercise will not be usable for the rest of this module.

> 警告 前の演習で使用したコンテナは、ここでは禁止されています。この演習の検証に使用したコンテナは、このモジュールの残りの部分で使用できなくなります。
