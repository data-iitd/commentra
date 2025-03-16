

#include <stdio.h> // Including the necessary header files for using printf and scanf functions.

int main ( void ) { // Starting the main method, which is the entry point of the program.
    int n ; // Declaring an integer variable n to store the input number.
    scanf ( "%d", & n ) ; // Reading the first integer input n from the user using the scanf function.

    int s = 0 ; // Initializing an integer variable s to store the binary representation of the number n.

    while ( n > 0 ) { // Starting a while loop that continues as long as n is greater than zero.
        int x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n /= 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s = s * 10 + x ; // Appending the calculated bit to the integer s by multiplying s by 10 and adding x.
    }

    int ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    while ( s > 0 ) { // Starting a while loop that continues as long as s is greater than zero.
        int x = s % 10 ; // Calculating the last digit of the integer s by finding the remainder of s divided by 10.
        s /= 10 ; // Updating the value of s by dividing it by 10 to get the next digit of the integer s.
        if ( x == 1 ) { // Checking if the current digit is 1.
            ans ++ ; // If the digit is 1, incrementing the value of ans by 1.
        }
    }

    printf ( "%d", ans ) ; // Printing the value of ans to the standard output stream using the printf function.

    return 0 ; // Returning 0 to indicate successful execution of the program.
}

Translate the above C code to Python and end with comment "