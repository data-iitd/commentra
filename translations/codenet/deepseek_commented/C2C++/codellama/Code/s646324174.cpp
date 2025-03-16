#include<iostream>
#include<cstdlib>

// Define the stack array and top variable
int top, S[10000];

// Function to push an element onto the stack
void push(int x) {
    S[++top] = x;
}

// Function to pop an element from the stack
int pop() {
    return S[top--];
}

// Main function to read input, perform operations, and print the result
int main() {
    int a, b;
    char s[200];
    top = 0; // Initialize the top of the stack

    // Read input until end of file
    while (std::cin >> s) {
        if (s[0] == '+') {
            // Pop two elements, add them, and push the result
            b = pop();
            a = pop();
            push(a + b);
        } else if (s[0] == '-') {
            // Pop two elements, subtract the top element from the bottom element, and push the result
            b = pop();
            a = pop();
            push(a - b);
        } else if (s[0] == '*') {
            // Pop two elements, multiply them, and push the result
            b = pop();
            a = pop();
            push(a * b);
        } else {
            // Convert the input string to an integer and push it onto the stack
            push(atoi(s));
        }
    }
    // Print the final result from the stack
    std::cout << pop() << std::endl;
    return 0;
}

