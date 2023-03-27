#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

// print the error and exit
void	putError(std::string msg) {
	std::cout << "\033[31m" << "[*] ERROR: " << msg << "\033[0m" << std::endl;
	exit(1);
}

int main(int ac, char* av[]) {
	// check if the argument is valid
	if (ac != 2)
		putError("invalid arguments");

	std::stack<int> numbers;
	std::istringstream arg(av[1]);
	std::string token;

	// get the tokens from the argument
	while (arg >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			
			// check if there are enough operands
			if (numbers.size() < 2)
				putError("Insufficient operands for '" + token + "' operator.");
			
			int secondNum = numbers.top(); numbers.pop();
			int firstNum = numbers.top(); numbers.pop();
			int res;

			// check the operator and calculate
			if (token == "+")
				res = firstNum + secondNum;
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