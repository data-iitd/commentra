
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main ( ) { 
    // Declare and initialize a constant integer
    int num = 998244353 ; 
    
    // Create a BufferedReader object to read input from the standard input
    FILE *bf = stdin ; 
    
    // Create a PrintWriter object to write output to the standard output
    FILE *out = stdout ; 
    
    // Read the number of elements 'n' from the input
    int n ; 
    fscanf ( bf, "%d", &n ) ; 
    
    // Create two ArrayList objects to store the pairs of integers
    int *ai = ( int * ) malloc ( n * sizeof ( int ) ) ; 
    int *bi = ( int * ) malloc ( n * sizeof ( int ) ) ; 
    
    // Read the pairs of integers from the input and store them in the ArrayList objects
    for ( int i = 0 ; i < n ; i ++ ) { 
        fscanf ( bf, "%d %d", &ai[i], &bi[i] ) ; 
    } 
    
    // Sort both the ArrayList objects
    qsort ( ai, n, sizeof ( int ), compare ) ; 
    qsort ( bi, n, sizeof ( int ), compare ) ; 
    
    // Check if 'n' is odd or even
    if ( n % 2 == 1 ) { 
        // If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        fprintf ( out, "%d\n", bi[n / 2] - ai[n / 2] + 1 ) ; 
        fclose ( out ) ; 
    } else { 
        // If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        double b = ( ai[n / 2] + ai[n / 2 - 1] + 0.0 ) / 2 ; 
        double c = ( bi[n / 2] + bi[n / 2 - 1] + 0.0 ) / 2 ; 
        fprintf ( out, "%d\n", ( int ) ( 2 * ( c - b ) + 1 ) ) ; 
        fclose ( out ) ; 
    } 
    
    // Free the memory allocated to the ArrayList objects
    free ( ai ) ; 
    free ( bi ) ; 
    
    return 0 ; 
} 

int compare ( const void *a, const void *b ) { 
    return ( *( int * ) a - *( int * ) b ) ; 
} 

