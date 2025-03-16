

#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Entry point of the program
    int n, k, z ; // Declare three integer variables `n`, `k`, and `z`
    scanf ( "%d %d", &n, &k ) ; // Read the first and second integers `n` and `k` from the standard input
    n ++ ; // Increment the value of `n` by 1
    if ( n % k!= 0 ) { // Check if the remainder of `n` divided by `k` is equal to 0
        z = k - n % k ; // If the remainder is not equal to 0, calculate the difference between `k` and the remainder and assign it to `z`
    }
    printf ( "%d\n", n + z ) ; // Print the value of `n` plus the value of `z`
    return 0 ; // Return 0 to indicate successful execution of the program
}

