#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main() { // Beginning of the main function
    int x; // Declare an integer variable named x

    cin >> x; // Read an integer value from the standard input and store it in variable x

    if (x >= 1200) { // Beginning of the if statement block
        cout << "ARC" << endl; // Output the string "ARC" to the standard output if the condition is true
    }
    else { // Beginning of the else statement block
        cout << "ABC" << endl; // Output the string "ABC" to the standard output if the condition is false
    }

    return 0; // Indicate successful execution of the program and return control to the operating system
}
