
#include <iostream>
#include <cmath>
#include <vector>

using namespace std ;

int main ( ) {
    long x ; // Declaring the variable x to store the first number
    vector < long > list ; // Declaring an empty vector to store the digits
    cin >> x ; // Reading the first number from the standard input stream and storing it in the variable x

    // The following while loop runs as long as the number x is greater than zero
    while ( x > 0 ) {
        long r = x % 10 ; // Storing the last digit of the number x in the variable r

        // The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if ( 9 - r < r ) {
            // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if ( x / 10 == 0 && 9 - r == 0 ) {
                list.push_back ( r ) ; // Adding the last digit r to the vector if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
            } else {
                list.push_back ( 9 - r ) ; // Adding the number 9 minus the last digit r to the vector if the difference between 9 and the last digit is greater than the last digit itself
            }
        } else {
            list.push_back ( r ) ; // Adding the last digit r to the vector if the difference between 9 and the last digit is less than or equal to the last digit itself
        }

        x = x / 10 ; // Dividing the number x by 10 to get the next digit
    }

    int pow = 0 ; // Initializing the variable pow to 0 to be used as the power of 10 in the calculation of the new number
    long newNumber = 0 ; // Initializing the variable newNumber to 0 to store the final number after calculating the digits in reverse order

    // The following for loop runs through each digit in the vector and calculates the new number by adding the digit multiplied by the power of 10 to the variable newNumber
    for ( int i = 0 ; i < list.size ( ) ; i ++ ) {
        newNumber = newNumber + list.at ( i ) * ( long ) pow ( 10 , pow ) ;
        pow ++ ;
    }

    cout << newNumber << endl ; // Printing the final number to the standard output stream

    return 0 ;
}

