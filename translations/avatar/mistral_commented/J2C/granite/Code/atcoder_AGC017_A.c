

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the binomial coefficient C(n, m) using double
double C ( int n, int m ) {
    double res = 1.0 ;  // Initialize result as 1

    // Calculate the binomial coefficient for n choose m
    for ( int i = m - n + 1 ; i <= m ; i ++ ) {
        res *= i ;  // Multiply with current term
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        res /= i ;  // Divide with denominator
    }

    return res ;  // Return the calculated binomial coefficient
}

int main ( ) {
    int n, p ;  // Declare variables n and p
    int k0 = 0, k1 = 0 ;  // Initialize counters k0 and k1 to 0

    scanf ( "%d %d", &n, &p ) ;  // Read the values of n and p from standard input

    // Read the values of n elements and count the number of odd and even elements
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        scanf ( "%d", &x ) ;

        if ( x % 2 == 1 ) {
            k1 ++ ;  // Increment the counter k1 if the current element is odd
        } else {
            k0 ++ ;  // Increment the counter k0 if the current element is even
        }
    }

    double ans = 1.0 ;  // Initialize answer as 1

    // Calculate the answer based on the given conditions
    for ( int i = 0 ; i < k0 ; i ++ ) {
        ans *= pow ( 2, i ) ;  // Multiply answer with 2 raised to the power of counter i
    }

    if ( p == 0 ) {  // If p is 0, calculate the answer using the given formula
        double add = 0 ;

        for ( int i = 0 ; i <= k1 ; i += 2 ) {
            add += C ( i, k1 ) ;  // Calculate the sum of C(i, k1) for i from 0 to k1 with a step of 2
        }

        ans *= add ;  // Multiply the answer with the calculated sum

        printf ( "%.0f", ans ) ;  // Print the final answer
    } else {  // If p is not 0, calculate the answer using a similar formula
        double add = 0 ;

        for ( int i = 1 ; i <= k1 ; i += 2 ) {
            add += C ( i, k1 ) ;  // Calculate the sum of C(i, k1) for i from 1 to k1 with a step of 2
        }

        ans *= add ;  // Multiply the answer with the calculated sum

        printf ( "%.0f", ans ) ;  // Print the final answer
    }

    return 0 ;  // Return 0 to indicate successful execution
}

These comments should provide a clear understanding of the code and its functionality.