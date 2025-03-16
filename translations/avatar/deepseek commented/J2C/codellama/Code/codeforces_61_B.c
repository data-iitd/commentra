
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( ) { 
    // Initialize Scanner for input operations
    char word1 [ 100 ] , word2 [ 100 ] , word3 [ 100 ] ; 
    char testCase [ 100 ] ; 
    int students ; 

    // Read and process the three input words
    scanf ( "%s %s %s" , word1 , word2 , word3 ) ; 

    // Generate all possible permutations of the three words
    char perm1 [ 100 ] = { 0 } , perm2 [ 100 ] = { 0 } , perm3 [ 100 ] = { 0 } , perm4 [ 100 ] = { 0 } , perm5 [ 100 ] = { 0 } , perm6 [ 100 ] = { 0 } ; 
    strcpy ( perm1 , word1 ) ; 
    strcat ( perm1 , word2 ) ; 
    strcat ( perm1 , word3 ) ; 
    strcpy ( perm2 , word1 ) ; 
    strcat ( perm2 , word3 ) ; 
    strcat ( perm2 , word2 ) ; 
    strcpy ( perm3 , word2 ) ; 
    strcat ( perm3 , word1 ) ; 
    strcat ( perm3 , word3 ) ; 
    strcpy ( perm4 , word2 ) ; 
    strcat ( perm4 , word3 ) ; 
    strcat ( perm4 , word1 ) ; 
    strcpy ( perm5 , word3 ) ; 
    strcat ( perm5 , word2 ) ; 
    strcat ( perm5 , word1 ) ; 
    strcpy ( perm6 , word3 ) ; 
    strcat ( perm6 , word1 ) ; 
    strcat ( perm6 , word2 ) ; 

    // Read the number of test cases
    scanf ( "%d" , &students ) ; 

    // Process each test case
    for ( int i = 0 ; i < students ; i ++ ) { 
        scanf ( "%s" , testCase ) ; 
        // Check if the test case matches any of the generated permutations
        if ( strcmp ( testCase , perm1 ) == 0 || strcmp ( testCase , perm2 ) == 0 || strcmp ( testCase , perm3 ) == 0 || 
             strcmp ( testCase , perm4 ) == 0 || strcmp ( testCase , perm5 ) == 0 || strcmp ( testCase , perm6 ) == 0 ) { 
            printf ( "ACC\n" ) ; // Print "ACC" if a match is found
        } else { 
            printf ( "WA\n" ) ; // Print "WA" if no match is found
        } 
    } 

    return 0 ; 
}

