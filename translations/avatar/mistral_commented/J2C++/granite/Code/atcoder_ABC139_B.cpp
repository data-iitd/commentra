
// Importing necessary header files for input and output
#include <iostream>
#include <cstdio>

// Main method is the entry point of the C++ application
int main ( ) {
    // Initialize variables for storing input and result
    int A, B, amari, result ;

    // Read first integer input A from user
    std::cin >> A ;

    // Read second integer input B from user
    std::cin >> B ;

    // Calculate the result by dividing B by A - 1 and storing the quotient
    result = ( B - 1 ) / ( A - 1 ) ;

    // Calculate the remainder of B divided by A - 1 and store it in amari
    amari = ( B - 1 ) % ( A - 1 ) ;

    // Check if the remainder is not zero
    if ( amari!= 0 ) {
        // If the remainder is not zero, increment the result by 1
        result += 1 ;
    }

    // Write the result to the standard output
    std::cout << result << std::endl ;

    // Return 0 to indicate successful execution of the program
    return 0 ;
}
