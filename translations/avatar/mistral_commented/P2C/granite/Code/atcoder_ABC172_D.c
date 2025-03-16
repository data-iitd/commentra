
#include <stdio.h>

int main ( ) {
    // Read the number of test cases from standard input
    int N = 0;
    scanf ( "%d", & N );

    // Initialize the answer to 0
    int ans = 0;

    // Iterate through all numbers from 1 to N
    for ( int i = 1 ; i <= N ; i ++ ) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }

    // Print the answer
    printf ( "%d\n", ans );

    return 0;
}
