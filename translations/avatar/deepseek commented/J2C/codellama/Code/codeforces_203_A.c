#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    // Reading the number of test cases (t) and other required values
    int x, t, a, b, da, db ; 
    scanf ( "%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db ) ; 
    
    // Variables to store calculated values
    int first, second ; 
    
    // Flag to determine if a solution is found
    int ok = 0 ; 
    
    // Nested loop to calculate possible values of first and second
    for ( int i = 0 ; i < t ; i ++ ) { 
        first = a - ( da * i ) ; // Calculate first value
        for ( int j = 0 ; j < t ; j ++ ) { 
            second = b - ( db * j ) ; // Calculate second value
            if ( second + first == x || second == x || first == x || x == 0 ) { 
                // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                ok = 1 ; 
                break ; 
            } 
        } 
        if ( ok ) break ; // Exit the outer loop if a solution is found
    } 
    
    // Print the result based on the flag
    if ( ok ) printf ( "YES" ) ; 
    else printf ( "NO" ) ; 
    
    return 0 ; 
}

