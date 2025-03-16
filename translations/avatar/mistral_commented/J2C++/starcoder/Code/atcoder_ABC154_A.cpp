#######
// Importing necessary C++ libraries
#######
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std ;

#######
// Main method is the entry point of the C++ application
#######
int main ( ) {

    // Creating a vector of strings to store the input
    vector < string > str ;

    // Taking the first line of input as a string
    string s ;
    cin >> s ;

    // Splitting the string into a vector of strings
    str = split ( s, " " ) ;

    // Taking the second line of input as a string
    string s1 ;
    cin >> s1 ;

    // Splitting the string into a vector of strings
    vector < string > str1 = split ( s1, " " ) ;

    // Converting the first two integers from the vector of strings to integers
    int a = stoi ( str1 [ 0 ] ) ;
    int b = stoi ( str1 [ 1 ] ) ;

    // Taking the third line of input as a string
    string s2 ;
    cin >> s2 ;

    // Checking if the first string from the first line matches with the given string 'u'
    if ( s.compare ( str [ 0 ] ) == 0 ) {

        // If the condition is true, then print the result as (a-1) and b
        cout << ( a - 1 ) << " " << b << endl ;

    } else {

        // If the condition is false, then print the result as a and (b-1)
        cout << a << " " << ( b - 1 ) << endl ;
    }

    // Returning from the main method
    return 0 ;
}

