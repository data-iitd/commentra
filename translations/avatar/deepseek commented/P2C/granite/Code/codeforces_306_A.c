

#include <stdio.h>

int main ( ) {
    int n, m, q, r, i;
    scanf ( "%d %d", &n, &m );  // Take two integers n and m as input
    q = n / m;  // Calculate the quotient, which is the number of items each group will have
    r = n % m;  // Calculate the remainder, which is the number of items that will be left over
    int a [ m ];  // Initialize an array a of length m
    for ( i = 0; i < m; i++ ) {
        a [ i ] = q;  // Set each element of the array a to the value of q
    }
    for ( i = 0; i < r; i++ ) {
        a [ i ] += 1;  // Increment the corresponding element in the array a by 1
    }
    for ( i = 0; i < m; i++ ) {
        printf ( "%d ", a [ i ] );  // Print each element of the array a separated by a space
    }
    return 0;
}

