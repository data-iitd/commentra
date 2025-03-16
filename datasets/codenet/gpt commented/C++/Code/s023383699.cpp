#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main() { // Main function where the program execution begins
    int x; // Declare an integer variable 'x' to store user input
    cin >> x; // Read an integer value from the user and store it in 'x'
    
    // Calculate the cube of 'x' and print the result
    cout << x * x * x << endl; // Output the cube of 'x' followed by a newline

    return 0; // Return 0 to indicate that the program ended successfully
}
