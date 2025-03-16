
#include <bits/stdc++.h> // Include the C++ standard library

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function
    string str ; // Declare a string variable to store the input String
    cin >> str ; // Read the first line of input as a String and store it in the'str' variable
    long long k ; // Declare a long long variable to store the second line of input
    cin >> k ; // Read the second line of input as a long long integer and store it in the 'k' variable
    int n = str.length ( ) ; // Find the length of the String

    for ( int i = 0 ; i < k ; i ++ ) { // Starting a for loop to iterate through the String up to the given limit 'k'
        if ( str [ i ] == '1' ) { // Checking if the current character is '1'
            if ( i == k - 1 ) { // Checking if the current index is the last index of the String
                cout << 1 << endl ; // If yes, print '1' and exit the function
                return 0 ; // Return 0 to indicate successful execution
            }
        } else {
            cout << str [ i ] << endl ; // If the current character is not '1', print it to the console
            return 0 ; // Return 0 to indicate successful execution
        }
    }
}

