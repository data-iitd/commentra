
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    // Take a string as input from the user
    char S [ 100001 ];
    scanf ( "%s", S );

    // Create a dictionary c to store the frequency of each character in the string S
    int c [ 256 ] = { 0 };
    for ( int i = 0; S [ i ]!= '\0'; i ++ ) {
        c [ S [ i ] ] ++;
    }

    // Create a set Sa from the dictionary c
    int Sa [ 256 ] = { 0 };
    for ( int i = 0; i < 256; i ++ ) {
        if ( c [ i ] == 2 ) {
            Sa [ i ] = 1;
        }
    }

    // Check if the sum of the elements in the set Sa is equal to 2
    int sum = 0;
    for ( int i = 0; i < 256; i ++ ) {
        sum += Sa [ i ];
    }

    // If the sum is not equal to 2, print "No" and exit the program
    if ( sum!= 2 ) {
        printf ( "No\n" );
        return 0;
    }

    // Print "Yes" to indicate that the string satisfies the condition
    printf ( "Yes\n" );

    return 0;
}
