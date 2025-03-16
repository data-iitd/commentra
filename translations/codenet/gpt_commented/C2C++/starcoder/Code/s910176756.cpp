#include<iostream>

using namespace std;

int main() {
    // Declare variables for two integers and one character operator
    int a, b, c;
    char op;

    // Read input values: two integers and an operator
    cin >> a >> op >> b;

    // Start an infinite loop to continuously process operations
    while(1) {
        // Check if the operator is addition
        if (op == '+') {
            c = a + b; // Perform addition
            cout << c << endl; // Output the result
        } 
        // Check if the operator is subtraction
        else if (op == '-') {
            c = a - b; // Perform subtraction
            cout << c << endl; // Output the result
        } 
        // Check if the operator is multiplication
        else if (op == '*') {
            c = a * b; // Perform multiplication
            cout << c << endl; // Output the result
        } 
        // Check if the operator is division
        else if (op == '/') {
            c = a / b; // Perform division
            cout << c << endl; // Output the result
        } 
        // If the operator is not recognized, exit the loop
        else {
            break; // Exit the loop if an invalid operator is provided
        }

        // Read the next set of inputs: two integers and an operator
        cin >> a >> op >> b;
    }

    return 0; // Return 0 to indicate successful completion of the program
}
