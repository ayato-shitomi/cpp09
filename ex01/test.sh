#!/bin/bash

# define test cases
test_cases=(
    # basic tests
    "2 3 +"                # 5
    "3 2 -"                # 1
    "4 3 *"                # 12
    "6 2 /"                # 3
    "9"                    # 9
    "0"                    # 0
    # invalid input tests
    "+"                    # ERROR
    "1 +"                  # ERROR
    "1 2 +"                # ERROR
    "1 a +"                # ERROR
    "10 +"                 # ERROR
    "11"                   # ERROR
    "1 2 3 +"              # ERROR
    "1 2 +"                # ERROR
    "1 + 2"                # ERROR
    ""                     # ERROR
    # overflow tests
    "2147483647 1 +"       # ERROR
    "-2147483648 -1 -"     # ERROR
    "1073741824 2 *"       # ERROR
    "-1073741824 -2 *"     # ERROR
    "1073741824 1073741824 +"  # ERROR
    "-1073741824 -1073741824 -"  # ERROR
    "1073741824 -1073741824 -"  # 2147483648
    "-1073741824 1073741824 +"  # 0
    "1000000000 1000000000 +"  # ERROR
    "500000000 500000000 *"    # ERROR
)

# run test cases
for i in "${!test_cases[@]}"; do
    # print test case
    echo "Test Case $((i+1)):	'" "${test_cases[$i]}'"
    # run program and print result
    ./RPN " ${test_cases[$i]} "
    echo ""
done
