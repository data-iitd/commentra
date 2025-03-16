
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read the input and split it into an array of strings
    char input [ ] = ( char * ) malloc ( 1000 * sizeof ( char ) ) ;
    scanf ( "%s", input ) ;
    
    // Parse the required integers from the input
    int m = atoi ( strstr ( input, " " ) + 1 ) ;
    int s = atoi ( strstr ( input, " " ) + 2 ) ;
    int f = atoi ( strstr ( input, " " ) + 3 ) ;
    
    // Initialize the maximum time and a HashMap to store the intervals
    int maxT = - 1 ;
    int * map [ ] = ( int * ) malloc ( m * sizeof ( int ) ) ;
    
    // Read the intervals from the input and store them in the HashMap
    for ( int i = 0 ; i < m ; i ++ ) {
        scanf ( "%d", & map [ i ] ) ;
        maxT = ( map [ i ] > maxT )? map [ i ] : maxT ;
    }
    
    // Initialize a StringBuilder to build the sequence of actions
    char * actions = ( char * ) malloc ( 1000 * sizeof ( char ) ) ;
    
    // Determine the direction of movement and initialize the current position
    char M = ( s < f )? 'R' : 'L' ;
    int d = ( s < f )? + 1 : - 1 ;
    int cur = s ;
    
    // Variables to store the current interval's start and end
    int a = - 1 ;
    int b = - 1 ;
    
    // Build the sequence of actions based on the intervals and the current position
    for ( int t = 1 ; t <= maxT ; t ++ ) {
        if ( map [ t ]!= NULL ) {
            a = map [ t ] [ 0 ] ;
            b = map [ t ] [ 1 ] ;
        }
        if ( map [ t ]!= NULL && ( ( cur >= a && cur <= b ) || ( cur + d >= a && cur + d <= b ) ) ) {
            strcat ( actions, "X" ) ;
        } else {
            strcat ( actions, & M ) ;
            cur += d ;
        }
        if ( cur == f ) break ;
    }
    
    // Continue moving in the determined direction until reaching the final position
    while ( cur!= f ) {
        strcat ( actions, & M ) ;
        cur += d ;
    }
    
    // Print the sequence of actions
    printf ( "%s\n", actions ) ;
    
    return 0 ;
}

