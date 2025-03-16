#include <iostream> // Include the iostream library for input and output operations

using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main() // Main function where the execution of the program begins
{
    int a; // Declare an integer variable 'a' to store user input

    // Prompt the user to enter a value for 'a'
    cout << "Enter a number: "; 
    cin >> a; // Read the input value from the user and store it in 'a'

    // Calculate the expression a + a^2 + a^3 and output the result
    cout << (a + (a * a) + (a * a * a)) << endl;

    return 0; // Return 0 to indicate that the program finished successfully
}

