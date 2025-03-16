
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring an integer variable n to store the input from the user.
    scanf ( "%d" , &n ) ; // Reading the first integer input n from the user using the scanf() function.

    char s [ 100 ] = { '\0' } ; // Declaring a character array s to store the binary representation of the number n.

    int i = 0 ; // Initializing an integer variable i to 0 to use as a counter in the while loop.

    while ( n > 0 ) { // Starting a while loop that continues as long as n is greater than zero.
        int x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n /= 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s [ i ] = x + '0' ; // Appending the calculated bit to the string s.
        i ++ ; // Incrementing the value of i by 1.
    }

    int ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for ( i = 0 ; i < strlen ( s ) ; i ++ ) { // Starting a for loop that iterates through each character in the string s.
        if ( s [ i ] == '1' ) { // Checking if the current character is '1'.
            ans ++ ; // If the character is '1', incrementing the value of ans by 1.
        }
    }

    printf ( "%d\n" , ans ) ; // Printing the value of ans to the standard output stream using the printf() function.

    return 0 ; // Returning 0 to indicate that the program executed successfully.
}

