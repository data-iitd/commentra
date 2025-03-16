

#include <stdio.h>
#include <math.h>

int main ( ) {
    int N, M ;
    scanf ( "%d %d", & N, & M ) ;
    // Read the values of N and M
    char S [ N ] ;
    scanf ( "%s", S ) ;
    // Read the string S
    char T [ M ] ;
    scanf ( "%s", T ) ;
    // Read the string T
    int Number_i [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_i [ i ] = i ;
    }
    // Create a list of indices from 0 to N-1
    int Number_iMN [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        Number_iMN [ i ] = i * M / N ;
    }
    // Calculate a new list where each element is i * M / N
    int Number_j [ M ] ;
    for ( int j = 0 ; j < M ; j ++ ) {
        Number_j [ j ] = j ;
    }
    // Create a list of indices from 0 to M-1
    int Kaburi_j [ M ] ;
    int Kaburi_Size = 0 ;
    for ( int j = 0 ; j < M ; j ++ ) {
        if ( Number_iMN [ j ] == Number_j [ j ] ) {
            Kaburi_j [ Kaburi_Size ] = Number_j [ j ] ;
            Kaburi_Size ++ ;
        }
    }
    // Find the intersection of Number_iMN and Number_j
    int Kaburi_i [ Kaburi_Size ] ;
    for ( int i = 0 ; i < Kaburi_Size ; i ++ ) {
        Kaburi_i [ i ] = int ( Kaburi_j [ i ] * N / M ) ;
    }
    // Calculate Kaburi_i by converting each element of Kaburi_j to an integer and multiplying by N/M
    int counter = 0 ;
    int Flag = 0 ;
    while ( counter <= Kaburi_Size - 1 ) {
        if ( S [ Kaburi_i [ counter ] ]!= T [ Kaburi_j [ counter ] ] ) {
            Flag = 1 ;
            break ;
        }
        counter ++ ;
    }
    // Iterate through Kaburi_i to check if corresponding characters in S and T are the same
    int gcd ( int a, int b ) {
        while ( b > 0 ) {
            a, b = b, a % b ;
        }
        return a ;
    }
    // Define a function to calculate the greatest common divisor (GCD) of two numbers
    if ( Flag == 1 ) {
        printf ( "-1\n" ) ;
    } else {
        printf ( "%d\n", int ( N * M / gcd ( N, M ) ) ;
    }
    // If the flag is 1, print -1. Otherwise, print the result of N*M divided by the GCD of N and M.

    return 0 ;
}
// Translate the above Python code to C and end with comment "