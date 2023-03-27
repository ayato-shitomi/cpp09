# ex02 

## subject

> You must create a program with these constraints:
The name of the program is PmergeMe.
Your program must be able to use a positive integer sequence as argument.
Your program must use a merge-insert sort algorithm to sort the positive integer sequence.
If an error occurs during program execution, an error message should be displayed on the standard output.

> この制約の中でプログラムを作成する必要があります：
プログラムの名前はPmergeMeとする。
プログラムは正整数列を引数として使用できなければならない。
プログラムは、正整数列をソートするためにマージインサートソートアルゴリズムを使用する必要があります。
プログラム実行中にエラーが発生した場合、標準出力にエラーメッセージが表示されること。

> You must use at least two different containers in your code to validate this exercise. Your program must be able to handle at least 3000 different integers.

> この演習を検証するために、あなたのコードで少なくとも2つの異なるコンテナを使用する必要があります。あなたのプログラムは、少なくとも3000種類の整数を扱うことができなければなりません。

> It is strongly advised to implement your algorithm for each container and thus to avoid using a generic function.

> コンテナごとにアルゴリズムを実装し、汎用関数を使用しないことを強くお勧めします。

> Here are some additional guidelines on the information you should display line by line on the standard output
On the first line you must display an explicit text followed by the unsorted positive integer sequence.
On the second line you must display an explicit text followed by the sorted positive integer sequence.
On the third line you must display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the positive integer sequence.
On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.


> 標準出力に一行ずつ表示すべき情報についての追加ガイドラインを以下に示します。
1行目には、明示的なテキストと、ソートされていない正整数列を表示する必要があります。
2行目には、ソートされた正整数列の後に、明示的なテキストを表示しなければなりません。
3行目には、正整数列のソートに使用した最初のコンテナを指定し、アルゴリズムが使用した時間を示す明示的なテキストを表示しなければなりません。
最後の行には、正整数列のソートに使用される2番目のコンテナを指定して、アルゴリズムが使用した時間を示す明示的なテキストを表示する必要があります。

> The format for the display of the time used to carry out your sorting is free but the precision chosen must allow to clearly see the difference between the two containers used.

> ソートの実行に使用された時間の表示形式は自由ですが、選択された精度は、使用された2つのコンテナの違いを明確に見ることができるものでなければなりません。

> Here is an example of a standard use:

```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$>
```

> Warning: The container(s) you used in the previous exercises are forbidden here.

> 警告： 警告：前の練習で使用した容器は、ここでは禁止されています。

> The management of errors related to duplicates is left to your discretion.

> 重複に関するエラーの管理は、あなたの裁量に任されています。

# tests

```bash
# 通常のパターン
./PmergeMe 1 2 3

# エラーになりうるパターン
./PmergeMe 1 2 a
./PmergeMe 1 2 0

# 重複ありの1から100の数3000個
ARG=`python3 -c "import random; print('\n'.join(str(random.randint(1, 100)) for _ in range(3000)))"` && ./PmergeMe $ARG

# 重複なしの1から1万の数3000個
python -c "import random; print(*random.sample(range(1, 10001), 3000))"
```