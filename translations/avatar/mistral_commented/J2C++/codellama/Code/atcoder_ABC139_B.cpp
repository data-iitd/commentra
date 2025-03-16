// Including necessary headers for input and output
#include <iostream>
#include <cstdlib>

// Declaring namespace std to avoid using std:: prefix
using namespace std ;

// Main function is the entry point of the C++ application
int main ( ) {
    // Declaring variables for storing input and result
    int A, B, amari, result ;

    // Reading first integer input A from user
    cin >> A ;

    // Reading second integer input B from user
    cin >> B ;

    // Calculating the result by dividing B by A - 1 and storing the quotient
    result = ( B - 1 ) / ( A - 1 ) ;

    // Calculating the remainder of B divided by A - 1 and storing it in amari
    amari = ( B - 1 ) % ( A - 1 ) ;

    // Checking if the remainder is not zero
    if ( amari != 0 ) {
        // If the remainder is not zero, increment the result by 1
        result += 1 ;
    }

    // Writing the result to the standard output
    cout << result << endl ;

    // Ending the program
    return 0 ;
}

