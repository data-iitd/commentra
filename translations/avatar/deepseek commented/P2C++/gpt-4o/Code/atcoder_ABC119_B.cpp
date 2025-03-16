#include <iostream>
#include <string>
#include <sstream>
#include <vector>

double evaluateExpression(const std::string& input) {
    std::string modifiedInput = input;
    // Replace 'JPY' with '1.0' and 'BTC' with '380000.0'
    size_t pos;
    while ((pos = modifiedInput.find("JPY")) != std::string::npos) {
        modifiedInput.replace(pos, 3, "1.0");
    }
    while ((pos = modifiedInput.find("BTC")) != std::string::npos) {
        modifiedInput.replace(pos, 3, "380000.0");
    }
    
    // Use a stringstream to evaluate the expression
    std::istringstream iss(modifiedInput);
    double value;
    iss >> value; // Read the first number
    char op;
    while (iss >> op) { // Read the operator and the next number
        double nextValue;
        iss >> nextValue;
        if (op == '+') {
            value += nextValue;
        } else if (op == '-') {
            value -= nextValue;
        } else if (op == '*') {
            value *= nextValue;
        } else if (op == '/') {
            value /= nextValue;
        }
    }
    return value;
}

int main() {
    int N;
    std::cin >> N; // Take an integer input N
    std::cin.ignore(); // Ignore the newline character after the integer input

    std::vector<double> x;
    for (int i = 0; i < N; ++i) {
        std::string input;
        std::getline(std::cin, input); // Read the entire line of input
        x.push_back(evaluateExpression(input)); // Evaluate and store the result
    }

    double total = 0.0;
    for (double value : x) {
        total += value; // Calculate the sum
    }

    std::cout << total << std::endl; // Print the sum
    return 0;
}

// <END-OF-CODE>
