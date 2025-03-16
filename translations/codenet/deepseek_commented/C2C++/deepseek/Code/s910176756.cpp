#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace

int main(){ // Define the main function, the entry point of the program
    int a, b, c; // Declare three integer variables to store the operands and the result
    char op; // Declare a character variable to store the operator
    while( true ){ // Start a loop that runs indefinitely
        cin >> a >> op >> b; // Read two integers and an operator from the user
        if ( op == '+' ){ // Check if the operator is addition
            c = a + b; // Perform the addition operation
            cout << c << endl; // Print the result
        } 
        else if ( op == '-' ){ // Check if the operator is subtraction
            c = a - b; // Perform the subtraction operation
            cout << c << endl; // Print the result
        } 
        else if ( op == '*' ){ // Check if the operator is multiplication
            c = a * b; // Perform the multiplication operation
            cout << c << endl; // Print the result
        } 
        else if ( op == '/' ){ // Check if the operator is division
            c = a / b; // Perform the division operation
            cout << c << endl; // Print the result
        } 
        else { // If the operator is not recognized
            break; // Exit the loop and end the program
        }
    }
    return 0; // Return 0 to indicate successful execution
}
