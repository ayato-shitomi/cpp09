#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <cstdlib>

bool is_operator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int perform_operation(const std::string &op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}

std::vector<std::string> tokenize(const std::string &expr) {
    std::istringstream iss(expr);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::string input_expr(argv[1]);
    std::vector<std::string> tokens = tokenize(input_expr);
    std::stack<int> operands;

    for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        const std::string &token = *it;
        if (is_operator(token)) {
            if (operands.size() < 2) {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            int result = perform_operation(token, a, b);

            operands.push(result);
        } else {
            int number = std::atoi(token.c_str());

            if (number < 0 || number >= 10) {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            operands.push(number);
        }
    }

    if (operands.size() != 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << operands.top() << std::endl;
    return 0;
}