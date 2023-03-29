#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>

// print the error and exit
void	putError(std::string msg) {
	std::cout << "\033[31m" << "[*] ERROR: " << msg << "\033[0m" << std::endl;
	exit(1);
}

void	putFlow(int firstNum, int secondNum, std::string token) {
	std::cout << "\033[31m" << "[*] ERROR: " << "Overflow or Under flow detected: " << firstNum << token << secondNum << "\033[0m" << std::endl;
	exit(1);
}

bool isNumeric(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            return false;
        }
    }
    return true;
}

bool chkNumbers(int num, std::string str) {
	/*
	std::cout << "num:	" << num << std::endl;
	std::cout << "str:	" << str << std::endl;
	*/

    // convert int to string
    std::string numStr = "";
    while (num > 0) {
        char c = '0' + num % 10;
        numStr = c + numStr;
        num /= 10;
    }
    // compare the strings
    for (size_t i = 0; i < numStr.length(); i++) {
        if (i >= str.length() || numStr[i] != str[i])
            return false;
    }
    // check if the string is longer than the number
    return numStr.length() == str.length();
}

void removeExtraSpaces(char *str) {
    int i, j;
    int n = strlen(str);

    // 先頭のスペースを除く
    i = 0;
    while (str[i] == ' ') {
        i++;
    }

    // 末尾のスペースを除く
    j = n - 1;
    while (j >= 0 && str[j] == ' ') {
        j--;
    }

    // スペースを1つにまとめる
    int k = 0;
    for (; i <= j; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            continue;
        }
        str[k++] = str[i];
    }
    str[k] = '\0';
}

int main(int ac, char* av[]) {
	// check if the argument is valid
	if (ac != 2)
		putError("invalid arguments");

	std::stack<int> numbers;
	std::istringstream arg(av[1]);
	std::istringstream chkArg(av[1]);
	std::string token;
	
	size_t n = 0;
	size_t spaceCount = 1;
	char *removeSpace = av[1];
	removeExtraSpaces(av[1]);
	while (removeSpace[n] != '\0') {
		if (removeSpace[n] == ' ')
			spaceCount++;
		n++;
	}
	size_t count = 0;
	std::string tokenTmp;
	std::stack<std::string> tokens;
	// std::cout << "====" << std::endl;
	while (chkArg >> token) {
		// std::cout << "token:	" << token << std::endl;
		tokenTmp += token + " ";
		if (isNumeric(token))
			tokens.push(token);
		count++;
	}

	///*
	std::cout << "====" << std::endl;
	
	std::stack<std::string> tokensCopy(tokens);
	while (!tokensCopy.empty()) {
        std::cout << "stacks:	" << tokensCopy.top() << std::endl;
        tokensCopy.pop();
    }
	std::cout << "====" << std::endl;

	//*/
	
	/*
	std::cout << "token tmp :	" << tokenTmp << std::endl;
	std::cout << "argment   :	" << av[1] << std::endl;
	std::cout << "token count: " << count << "\n" << "space count: " << spaceCount << std::endl;
	*/
	if (count != spaceCount)
		putError("Over or under flow detected.");
	// get the tokens from the argument
	// std::cout << "" << std::endl;
	// std::cout << "" << std::endl;
	while (arg >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			
			// check if there are enough operands
			//if (numbers.size() < 2)
			//	putError("Insufficient operands for '" + token + "' operator.");
			
			std::cout << "second:	" << numbers.top() << " and ";
			int secondNum = numbers.top(); numbers.pop();
			std::cout  << secondNum << std::endl;
			if (!(chkNumbers(secondNum, tokens.top())))
				putError("Over or under flow detected: " + tokens.top());
			tokens.pop();
			std::cout << "first:	" << numbers.top() << " and ";
			int firstNum = numbers.top(); numbers.pop();
			std::cout  << firstNum << std::endl;
			if (!(chkNumbers(firstNum, tokens.top())))
				putError("Over or under flow detected: " + tokens.top());
			tokens.pop();
			int res;
			if (secondNum < 0 || firstNum < 0)
				putError("Bad number was given.");

			// std::cout << "firstNum: " << firstNum << std::endl;
			// std::cout << "secondNum: " << secondNum << std::endl;

			// check the operator and calculate
			if (token == "+") {
				// check if the result is overflow or underflow
				if (secondNum > 0 && firstNum > INT_MAX - secondNum)
					putFlow(firstNum, secondNum, token);
				else if (secondNum < 0 && firstNum < INT_MIN - secondNum)
					putFlow(firstNum, secondNum, token);
				res = firstNum + secondNum;
			} else if (token == "-") {
				// check if the result is overflow or underflow
				if (secondNum > 0 && firstNum < INT_MIN + secondNum)
					putFlow(firstNum, secondNum, token);
				else if (secondNum < 0 && firstNum > INT_MAX + secondNum)
					putFlow(firstNum, secondNum, token);
				res = firstNum - secondNum;
			} else if (token == "*") {
				// check if the result is overflow or underflow
				if (secondNum > 0 && firstNum > INT_MAX / secondNum)
					putFlow(firstNum, secondNum, token);
				else if (secondNum < 0 && firstNum < INT_MIN / secondNum)
					putFlow(firstNum, secondNum, token);
				res = firstNum * secondNum;
			} else if (token == "/") {
				// check if the second number is zero
				if (secondNum == 0)
					putError("Division by zero.");
				// check if the result is overflow or underflow
				if (secondNum == -1 && firstNum == INT_MIN)
					putFlow(firstNum, secondNum, token);
				res = firstNum / secondNum;
			}
			// push the result to the stack
			numbers.push(res);
		} else {
			// check if the token is a number
			for(int i=0; token[i] !='\0'; i++) {
				if(token[i] < 48 || token[i] > 57)
					putError("Bad input was given.");
			}
			// convert the string to int
			// push the number to the stack
			numbers.push(atoi(token.c_str()));
		}
	}
	// check if the stack has only one number
	if (numbers.size() != 1) {
		putError("Invalid expression.");
	}
	// put the result
	std::cout << numbers.top() << std::endl;
	return 0;
}