#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

// Global stack to hold integers
stack<int> S;

// Function to push an integer onto the stack
void push(int x) {
    S.push(x); // Push the value onto the stack
}

// Function to pop an integer from the stack
int pop() {
    int topValue = S.top(); // Get the top value
    S.pop(); // Remove the top value from the stack
    return topValue; // Return the top value
}

int main() {
    int a, b; // Variables to hold the operands for operations
    string s; // String to hold the input

    // Read input until EOF
    while (cin >> s) {
        // Check for addition operation
        if (s[0] == '+') {
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a + b); // Push the result of addition back onto the stack
        }
        // Check for subtraction operation
        else if (s[0] == '-') {
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a - b); // Push the result of subtraction back onto the stack
        }
        // Check for multiplication operation
        else if (s[0] == '*') {
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a * b); // Push the result of multiplication back onto the stack
        }
        // If the input is a number, convert it and push onto the stack
        else {
            push(stoi(s)); // Convert string to integer and push onto the stack
        }
    }

    // Print the final result which is the last remaining value in the stack
    cout << pop() << endl;
    return 0; // Exit the program
}

// <END-OF-CODE>
