

#include <stdio.h>

int task4 ( int A, int B, int n ) {
    // The function `task4` is designed to find the value of `X` such that `A * (X ** n) == B`.
    for ( int X = - 1000 ; X <= 1000 ; X ++ ) {
        // It iterates over the range from -1000 to 1000 for `X`.
        if ( A * pow ( X, n ) == B ) {
            // For each value of `X`, it checks if the equation `A * (X ** n) == B` holds true.
            return X;
            // If a solution is found, it returns the value of `X`.
    }
    return - 1;
    // If no solution is found after the loop, it returns -1.
}

int main ( ) {
    int A, B, n;
    // The main part of the code takes input for `A`, `B`, and `n`.
    scanf ( "%d %d %d", & A, & B, & n );
    int X = task4 ( A, B, n );
    // Converts them to integers, and calls the `task4` function.
    if ( X!= - 1 ) {
        // If a solution is found, it prints the value of `X`.
        printf ( "%d", X );
    } else {
        // If no solution is found, it prints "No solution".
        printf ( "No solution" );
    }
    return 0;
}
