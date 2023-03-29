
clear

# 通常のパターン
./PmergeMe 1 2 3

sleep 2 && clear

# エラーになりうるパターン
./PmergeMe 1 2 a
./PmergeMe 1 2 0

sleep 2 && clear

# 重複ありの1から100の数3000個
ARG=`python3 -c "import random; print('\n'.join(str(random.randint(1, 100)) for _ in range(3000)))"` && ./PmergeMe $ARG

sleep 2 && clear

# 重複なしの1から1万の数3000個
ARG=`python3 -c "import random; print(*random.sample(range(1, 10001), 3000))"` && ./PmergeMe $ARG