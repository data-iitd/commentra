
#include <iostream>
#include <string>
#include <sstream>

using namespace std ;

int main ( ) {
    string str ; // Declaring a string to store the input
    int h, a, num ; // Declaring integers to store the height, amount to subtract, and the number of subtractions

    // Reading input and storing it in 'str'
    getline ( cin, str ) ;

    // Creating a stringstream object to parse the input
    stringstream ss ( str ) ;

    // Parsing the first element to an integer representing the height
    ss >> h ;

    // Parsing the second element to an integer representing the amount to subtract
    ss >> a ;

    // Initializing the counter to keep track of the number of subtractions
    num = 0 ;

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    for ( int i = 1 ; h > 0 ; i ++ ) {
        h = h - a ; // Subtracting 'a' from 'h'
        num ++ ; // Incrementing the counter
    }

    // Printing the result, which is the number of subtractions
    cout << num << endl ;

    return 0 ;
}

