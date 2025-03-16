#include <iostream>
#include <string>

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main method
    string str ; // Defining a string variable to store the input
    cin >> str ; // Reading the first line of input as a string
    char [ ] c = str.c_str ( ) ; // Converting the string to a character array
    long k ; // Defining a long integer variable to store the second line of input
    cin >> k ; // Reading the second line of input as a long integer
    int n = str.length ( ) ; // Finding the length of the string

    for ( int i = 0 ; i < k ; i ++ ) { // Starting a for loop to iterate through the character array up to the given limit 'k'
        if ( c [ i ] == '1' ) { // Checking if the current character is '1'
            if ( i == k - 1 ) { // Checking if the current index is the last index of the array
                cout << 1 << endl ; // If yes, print '1' and exit the method
                return 0 ;
            }
        } else {
            cout << c [ i ] << endl ; // If the current character is not '1', print it to the console
            return 0 ; // Exit the method as soon as a non-'1' character is found
        }
    }
}

