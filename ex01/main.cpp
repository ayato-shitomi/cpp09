/*
void overflow_handler(int signal) {
    if (signal == SIGABRT) {
        std::cerr << "Error: Integer overflow detected." << std::endl;
    } else {
        std::cerr << "Error: Some error." << std::endl;
    }
    std::exit(1);
}

    // check for overflow
    std::signal(SIGABRT, overflow_handler);
*/

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>
#include <csignal>

void overflow_handler(int signal) {
    if (signal == SIGABRT) {
        std::cerr << "Error: Integer overflow detected." << std::endl;
    } else {
        std::cerr << "Error: Some error." << std::endl;
    }
    std::exit(1);
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int perform_operation(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("ERROR");
            }
            return a / b;
        default:
            throw std::runtime_error("ERROR");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR" << std::endl;
        return 1;
    }
    std::signal(SIGABRT, overflow_handler);
    std::istringstream iss(argv[1]);
    std::string token;
    std::stack<int> operands;

    while (iss >> token) {
        if (is_operator(token[0])) {
            if (operands.size() < 2) {
                std::cerr << "ERROR" << std::endl;
                return 1;
            }
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            int result = perform_operation(token[0], a, b);
            operands.push(result);
        } else {
            int num = std::atoi(token.c_str());
            if (num < 0 || num >= 10) {
                std::cerr << "ERROR" << std::endl;
                return 1;
            }
            operands.push(num);
        }
    }

    if (operands.size() != 1) {
        std::cerr << "ERROR" << std::endl;
        return 1;
    }

    std::cout << operands.top() << std::endl;
    return 0;
}