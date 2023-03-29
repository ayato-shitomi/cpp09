#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <climits>

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


bool chkNumbers(int num, std::stack<std::string> tokens) {
	std::string str = tokens.top();
	tokens.pop();

	std::cout << "num:	" << num << std::endl;
	std::cout << "str:	" << str << std::endl;

    // 数値を文字列に変換
    std::string numStr = "";
    while (num > 0) {
        char c = '0' + num % 10;
        numStr = c + numStr;
        num /= 10;
    }
    // 文字列と1文字ずつ比較
    for (size_t i = 0; i < numStr.length(); i++) {
        if (i >= str.length() || numStr[i] != str[i]) {
            return false;
        }
    }
    // 文字列の長さもチェック
    return numStr.length() == str.length();
}

int main(int ac, char* av[]) {
	// check if the argument is valid
	if (ac != 2)
		putError("invalid arguments");

	std::stack<int> numbers;
	std::istringstream arg(av[1]);
	std::istringstream chkArg(av[1]);
	std::string token;

	// std::cout << (av[1]) << std::endl;
	
	size_t n = 0;
	size_t spaceCount = 1;
	
	while (av[1][n] != '\0') {
		if (av[1][n] == ' ')
			spaceCount++;
		n++;
	}
	size_t count = 0;
	std::string tokenTmp;
	std::stack<std::string> tokens;
	std::cout << "====" << std::endl;
	while (chkArg >> token) {
		std::cout << "token:	" << token << std::endl;
		tokenTmp += token + " ";
		if (isNumeric(token))
			tokens.push(token);
		count++;
	}

	std::cout << "====" << std::endl;
	while (!tokens.empty()) {
        std::cout << "stacks:	" << tokens.top() << std::endl;
        tokens.pop();
    }
	std::cout << "token tmp :	" << tokenTmp << std::endl;
	std::cout << "argment   :	" << av[1] << std::endl;
	std::cout << "token count: " << count << "\n" << "space count: " << spaceCount << std::endl;
	if (count != spaceCount)
		putError("Over or under flow detected.");
	// get the tokens from the argument
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	while (arg >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			
			// check if there are enough operands
			if (numbers.size() < 2)
				putError("Insufficient operands for '" + token + "' operator.");
			
			std::cout << "second:	" << numbers.top() << std::endl;
			int secondNum = numbers.top(); numbers.pop();
			if (!(chkNumbers(secondNum, tokens)))
				putError("Over or under flow detected with stack cast. 2nd");
			std::cout << "first:	" << numbers.top() << std::endl;
			int firstNum = numbers.top(); numbers.pop();
			if (!(chkNumbers(firstNum, tokens)))
				putError("Over or under flow detected with stack cast. 1st");
			int res;
			if (secondNum < 0 || firstNum < 0)
				putError("Bad number was given.");

			std::cout << "firstNum: " << firstNum << std::endl;
			std::cout << "secondNum: " << secondNum << std::endl;

			// check the operator and calculate
			if (token == "+") {
				if (secondNum > 0 && firstNum > INT_MAX - secondNum)
					putFlow(firstNum, secondNum, token);
				else if (secondNum < 0 && firstNum < INT_MIN - secondNum)
					putFlow(firstNum, secondNum, token);
				res = firstNum + secondNum;
			}
			else if (token == "-")
				res = firstNum - secondNum;
			else if (token == "*")
				res = firstNum * secondNum;
			else if (token == "/") {
				// check if the second number is zero
				if (secondNum == 0)
					putError("Division by zero.");
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