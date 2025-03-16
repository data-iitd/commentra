#include<iostream> // Include the standard input-output library
using namespace std; // Use the standard namespace
int main(){ // Define the main function, the entry point of the program
    int a, b, c; // Declare three integer variables to store the operands and the result
    char op; // Declare a character variable to store the operator
    cin >> a >> op >> b; // Read two integers and an operator from the user
    while( 1 ){ // Start an infinite loop
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
        cin >> a >> op >> b; // Read the next set of operands and operator
    }
    return 0; // Return 0 to indicate successful execution
}
