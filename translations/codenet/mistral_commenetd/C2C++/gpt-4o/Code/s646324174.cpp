#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

int main() {
    // Initialize a stack to hold integers
    std::stack<int> S;

    // Initialize variables
    int a, b;
    std::string s;

    // Read input until end of file
    while (std::cin >> s) {
        // Check if the input is an operator or a number
        if (s[0] == '+' || s[0] == '-' || s[0] == '*') {
            // Pop the top two elements from the stack
            b = S.top(); S.pop();
            a = S.top(); S.pop();

            // Perform the operation and push the result back onto the stack
            if (s[0] == '+') {
                S.push(a + b);
            } else if (s[0] == '-') {
                S.push(a - b);
            } else { // s[0] == '*'
                S.push(a * b);
            }
        } else { // Input is a number
            // Push the number directly onto the stack
            S.push(std::atoi(s.c_str()));
        }
    }

    // Print the final result
    std::cout << S.top() << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
