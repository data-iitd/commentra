#include<iostream>
#include<cstdlib>

// Global variables
int top, S[10000]; // Stack to hold integers and a variable to track the top index

// Function to push an integer onto the stack
void push(int x){
    S[++top] = x; // Increment top and assign the value to the stack
}

// Function to pop an integer from the stack
int pop(){
    return S[top--]; // Return the top value and decrement the top index
}

int main(){
    int a, b; // Variables to hold the operands for operations
    char s[200]; // Array to hold the input string
    top = 0; // Initialize the stack top index

    // Read input until EOF
    while(std::cin >> s){
        // Check for addition operation
        if(s[0] == '+'){
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a + b); // Push the result of addition back onto the stack
        }
        // Check for subtraction operation
        else if(s[0] == '-'){
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a - b); // Push the result of subtraction back onto the stack
        }
        // Check for multiplication operation
        else if(s[0] == '*'){
            b = pop(); // Pop the top two values from the stack
            a = pop();
            push(a * b); // Push the result of multiplication back onto the stack
        }
        // If the input is a number, convert it and push onto the stack
        else{
            push(atoi(s)); // Convert string to integer and push onto the stack
        }
    }
    
    // Print the final result which is the last remaining value in the stack
    std::cout << pop() << std::endl;
    return 0; // Exit the program
}

