

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve ( int N, int * x, int * y ) {
    // Generate a list of indices from 0 to N-1
    int * indices = ( int * ) malloc ( N * sizeof ( int ) ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        indices [ i ] = i ;
    }
    
    // Generate all permutations of the indices
    int * permutation = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int * temp = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int * result = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int count = 0 ;
    while ( 1 ) {
        for ( int i = 0 ; i < N ; i ++ ) {
            permutation [ i ] = indices [ i ] ;
        }
        for ( int i = 0 ; i < N ; i ++ ) {
            result [ i ] = permutation [ i ] ;
        }
        count ++ ;
        yield ( result, count ) ;
        if (! next_permutation ( indices, temp ) ) {
            break ;
        }
    }
    
    // Initialize a list to store the total distances for each permutation
    double * distances = ( double * ) malloc ( count * sizeof ( double ) ) ;
    
    // Iterate over each permutation
    for ( int i = 0 ; i < count ; i ++ ) {
        // Initialize the total distance for the current permutation
        double total_distance = 0 ;
        
        // Calculate the distance between consecutive points in the permutation
        for ( int j = 0 ; j < N - 1 ; j ++ ) {
            int f = permutation [ j ] ;
            int t = permutation [ j + 1 ] ;
            double distance = sqrt ( pow ( x [ t ] - x [ f ], 2 ) + pow ( y [ t ] - y [ f ], 2 ) ) ;
            total_distance += distance ;
        }
        
        // Append the total distance of the current permutation to the distances list
        distances [ i ] = total_distance ;
    }
    
    // Calculate the average distance by averaging all stored distances
    double result = 0 ;
    for ( int i = 0 ; i < count ; i ++ ) {
        result += distances [ i ] ;
    }
    result /= count ;
    
    // Print the result
    printf ( "%.10lf\n", result ) ;
    
    // Free the allocated memory
    free ( indices ) ;
    free ( permutation ) ;
    free ( temp ) ;
    free ( result ) ;
    free ( distances ) ;
    
    // Return from the function
    return ;
}

int main ( ) {
    // Function to iterate over tokens in the input
    char * token = NULL ;
    char * line = NULL ;
    size_t len = 0 ;
    int N ;
    int * x ;
    int * y ;
    
    // Read the number of points N
    getline ( & line, & len, stdin ) ;
    sscanf ( line, "%d", & N ) ;
    
    // Initialize lists for x and y coordinates
    x = ( int * ) malloc ( N * sizeof ( int ) ) ;
    y = ( int * ) malloc ( N * sizeof ( int ) ) ;
    
    // Read the x and y coordinates for each point
    for ( int i = 0 ; i < N ; i ++ ) {
        getline ( & line, & len, stdin ) ;
        sscanf ( line, "%d %d", & x [ i ], & y [ i ] ) ;
    }
    
    // Call the solve function with the input values
    solve ( N, x, y ) ;
    
    // Free the allocated memory
    free ( x ) ;
    free ( y ) ;
    
    // Return from the main function
    return 0 ;
}



Translate the above C code to Java and end with comment "