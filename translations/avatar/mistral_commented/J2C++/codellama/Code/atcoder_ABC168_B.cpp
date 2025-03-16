
#include <iostream>

#include <string>

using namespace std ;

int main ( ) {

    int K ; // Declare an integer variable `K`

    string S ; // Declare a string variable `S`

    cin >> K >> S ; // Read the first integer `K` and the next token from the input, which is assumed to be a string `S`

    if ( S.length ( ) <= K ) { // Check if the length of the string `S` is less than or equal to the integer `K`

        cout << S << endl ; // If the condition is true, print the string `S` to the standard output

    } else { // If the condition is false

        cout << S.substr ( 0 , K ) << "..." << endl ; // Print the first `K` characters of the string `S` followed by "..." to the standard output

    }

    return 0 ; // Return 0 to indicate that the program has completed successfully

}

