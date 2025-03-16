// Importing necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a main function
int main ( ) {
    // Initializing a variable to store the number of students
    int students ;

    // Reading the number of students
    scanf ( "%d" , &students ) ;
    // This block of code reads an integer value from the user input.
    // The number of students is stored in the 'students' variable.

    // Looping through each student's test case
    for ( int i = 0 ; i < students ; i ++ ) {
        // Reading a test case from the user input
        char testCase [ 100 ] ;
        scanf ( "%s" , testCase ) ;
        // This block of code reads a line from the user input.
        // The resulting string is stored in the 'testCase' variable.

        // Creating six permutations of the given words
        char perm1 [ 100 ] = "abc" ;
        char perm2 [ 100 ] = "acb" ;
        char perm3 [ 100 ] = "bac" ;
        char perm4 [ 100 ] = "bca" ;
        char perm5 [ 100 ] = "cab" ;
        char perm6 [ 100 ] = "cba" ;

        // Checking if the test case matches any of the permutations
        if ( strcmp ( testCase , perm1 ) == 0 || strcmp ( testCase , perm2 ) == 0 || strcmp ( testCase , perm3 ) == 0 || strcmp ( testCase , perm4 ) == 0 || strcmp ( testCase , perm5 ) == 0 || strcmp ( testCase , perm6 ) == 0 ) {
            // Printing 'ACC' if the test case matches any of the permutations
            printf ( "ACC\n" ) ;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            printf ( "WA\n" ) ;
        }
    }

    // Ending the program
    return 0 ;
}

