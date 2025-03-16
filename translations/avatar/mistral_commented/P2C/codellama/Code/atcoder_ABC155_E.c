#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define helper function to read input as a list of integers
int *IN ( int *n ) {
    char *s = malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s", s );
    int i = 0;
    int j = 0;
    while ( s [ i ] != '\0' ) {
        if ( s [ i ] != ' ' ) {
            s [ j ] = s [ i ];
            j++;
        }
        i++;
    }
    s [ j ] = '\0';
    int *l = malloc ( j * sizeof ( int ) );
    i = 0;
    j = 0;
    while ( s [ i ] != '\0' ) {
        if ( s [ i ] != ' ' ) {
            l [ j ] = s [ i ] - '0';
            j++;
        }
        i++;
    }
    *n = j;
    return l;
}

// Define modulus constant
const int mod = 1000000007;

// Define main function 'main_b'
int main_b ( ) {
    // Read input string 's'
    char *s = malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s", s );

    // Initialize variables 'pp' and 'na'
    int pp = 0;
    int na = 0;

    // Iterate through each character in the input string 's'
    for ( int i = strlen ( s ) - 1; i >= 0; i-- ) {
        // Calculate current character value 'cc'
        int cc = na + s [ i ] - '0';
        na = 0;

        // Update 'pp' based on the current character value 'cc'
        if ( cc <= 4 ) {
            pp += cc;
        } else {
            // If current character is the last character, add 1 to 'pp'
            if ( i == strlen ( s ) - 1 ) {
                pp += 1;
            }
            // Otherwise, add 10 - 'cc' to 'pp'
            pp += 10 - cc;
        }
    }

    // Print the result 'pp'
    printf ( "%d\n", pp );

    // Return the result 'pp'
    return pp;
}

// Define main function 'main'
int main ( ) {
    // Read input string 's'
    char *s = malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s", s );

    // Initialize variables 'pmin' and 'mmin' with large initial values
    int pmin = 1000;
    int mmin = 0;

    // Add a leading zero to the input string 's'
    char *t = malloc ( 1000000 * sizeof ( char ) );
    t [ 0 ] = '0';
    strcpy ( t + 1, s );
    s = t;

    // Iterate through each character in the input string 's'
    for ( int i = strlen ( s ) - 1; i >= 0; i-- ) {
        // Calculate new minimum values 'npmin' and 'nmmin' based on current character value 'v' and previous minimum values 'pmin' and 'mmin'
        int npmin = min ( pmin + 10 - ( s [ i ] - '0' + 1 ) , mmin + 10 - ( s [ i ] - '0' ) );
        int nmmin = min ( pmin + ( s [ i ] - '0' ) + 1 , mmin + ( s [ i ] - '0' ) );

        // Update 'pmin' and 'mmin' with the new minimum values
        pmin = npmin;
        mmin = nmmin;
    }

    // Return the minimum value between 'pmin' and 'mmin'
    return min ( pmin , mmin );
}

// Define a helper function 'pa' to print values during testing
void pa ( int v ) {
    if ( isTest ) {
        printf ( "%d\n", v );
    }
}

// Define function to read input from clipboard
char *input_clipboard ( ) {
    char *input_text = malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s", input_text );
    return input_text;
}

// Main program execution starts here
int main ( ) {
    // Check current platform and set input method accordingly
    if ( sys.platform == 'ios' ) {
        if ( input_method == input_methods [ 0 ] ) {
            char *ic = input_clipboard ( );
            input = lambda : ic.__next__ ( );
        } else if ( input_method == input_methods [ 1 ] ) {
            sys.stdin = open ( 'inputFile.txt' );
        } else {
            pass
        }
        isTest = True;
    } else {
        pass
    }

    // Call main function and print result
    int ret = main ( );
    if ( ret is not None ) {
        printf ( "%d\n", ret );
    }

    // End with comment "