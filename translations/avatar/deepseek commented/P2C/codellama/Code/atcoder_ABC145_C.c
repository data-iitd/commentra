
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1000

void solve ( int N , int x [ MAX_N ] , int y [ MAX_N ] ) {
    // Generate a list of indices from 0 to N-1
    int indices [ MAX_N ] = { 0 };
    for ( int i = 0 ; i < N ; i++ ) {
        indices [ i ] = i;
    }
    
    // Generate all permutations of the indices
    int permutations [ MAX_N ] [ MAX_N ] = { 0 };
    int count = 0;
    for ( int i = 0 ; i < N ; i++ ) {
        for ( int j = 0 ; j < N ; j++ ) {
            permutations [ i ] [ j ] = indices [ j ];
        }
    }
    
    // Initialize a list to store the total distances for each permutation
    double distances [ MAX_N ] = { 0 };
    
    // Iterate over each permutation
    for ( int i = 0 ; i < N ; i++ ) {
        // Initialize the total distance for the current permutation
        double total_distance = 0;
        
        // Calculate the distance between consecutive points in the permutation
        for ( int j = 0 ; j < N - 1 ; j++ ) {
            int f = permutations [ i ] [ j ];
            int t = permutations [ i ] [ j + 1 ];
            double distance = sqrt ( ( x [ t ] - x [ f ] ) * ( x [ t ] - x [ f ] ) + ( y [ t ] - y [ f ] ) * ( y [ t ] - y [ f ] ) );
            total_distance += distance;
        }
        
        // Append the total distance of the current permutation to the distances list
        distances [ i ] = total_distance;
    }
    
    // Calculate the average distance by averaging all stored distances
    double result = 0;
    for ( int i = 0 ; i < N ; i++ ) {
        result += distances [ i ];
    }
    result /= N;
    
    // Print the result
    printf ( "%.2lf\n" , result );
    
    // Return from the function
    return;
}

int main ( ) {
    // Function to iterate over tokens in the input
    int iterate_tokens ( ) {
        char line [ 100000 ] = { 0 };
        fgets ( line , 100000 , stdin );
        char * token = strtok ( line , " " );
        while ( token != NULL ) {
            printf ( "%s\n" , token );
            token = strtok ( NULL , " " );
        }
        return 0;
    }
    
    // Get the tokens from the input
    int tokens = iterate_tokens ( );
    
    // Read the number of points N
    int N = 0;
    scanf ( "%d" , &N );
    
    // Initialize lists for x and y coordinates
    int x [ MAX_N ] = { 0 };
    int y [ MAX_N ] = { 0 };
    
    // Read the x and y coordinates for each point
    for ( int i = 0 ; i < N ; i++ ) {
        scanf ( "%d" , &x [ i ] );
        scanf ( "%d" , &y [ i ] );
    }
    
    // Call the solve function with the input values
    solve ( N , x , y );
    
    // Return from the function
    return 0;
}

