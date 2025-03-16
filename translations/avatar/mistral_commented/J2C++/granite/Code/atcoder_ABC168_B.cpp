

#include <iostream> // Include the necessary header file for input/output operations

using namespace std ; // Define the "using namespace std" directive to avoid prefixing standard library identifiers with "std::"

int main ( ) { // Define the main function as the entry point of the program

    int K ; // Declare an integer variable `K` to store the input value

    string S ; // Declare a string variable `S` to store the input value

    cin >> K ; // Read the first integer `K` from the standard input stream

    cin >> S ; // Read the next token from the standard input stream, which is assumed to be a string `S`

    if ( S.length ( ) <= K ) { // Check if the length of the string `S` is less than or equal to the integer `K`

        cout << S << endl ; // If the condition is true, print the string `S` to the standard output stream

    } else { // If the condition is false

        cout << S.substr ( 0, K ) << "..." << endl ; // Print the first `K` characters of the string `S` followed by "..." to the standard output stream

    }

    return 0 ; // Return 0 to indicate successful execution of the program

}

