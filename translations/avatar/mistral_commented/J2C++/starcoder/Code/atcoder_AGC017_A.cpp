
#include <bits/stdc++.h>

using namespace std ;

// Function to calculate the binomial coefficient C(n, m) using BigInteger
BigInteger C ( int n, int m ) {
    BigInteger res = BigInteger ( "1" ) ;  // Initialize result as 1

    // Calculate the binomial coefficient for n choose m
    for ( int i = m - n + 1 ; i <= m ; i ++ ) {
        res = res * BigInteger ( to_string ( i ) ) ;  // Multiply with current term
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        res = res / BigInteger ( to_string ( i ) ) ;  // Divide with denominator
    }

    return res ;  // Return the calculated binomial coefficient
}

int main ( ) {
    int n, p ;  // Declare variables n and p
    int k0 = 0, k1 = 0 ;  // Initialize counters k0 and k1 to 0

    cin >> n >> p ;  // Read the value of n and p from standard input

    // Read the values of n elements and count the number of odd and even elements
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( x % 2 == 1 ) {
            k1 ++ ;  // Increment the counter k1 if the current element is odd
        } else {
            k0 ++ ;  // Increment the counter k0 if the current element is even
        }
    }

    BigInteger ans = BigInteger ( "1" ) ;  // Initialize answer as 1

    // Calculate the answer based on the given conditions
    for ( int i = 0 ; i < k0 ; i ++ ) {
        ans = ans * BigInteger ( to_string ( 2 ) ) ;  // Multiply answer with 2 raised to the power of counter i
    }

    if ( p == 0 ) {  // If p is 0, calculate the answer using the given formula
        BigInteger add = BigInteger ( "0" ) ;

        for ( int i = 0 ; i <= k1 ; i += 2 ) {
            add = add + C ( i, k1 ) ;  // Calculate the sum of C(i, k1) for i from 0 to k1 with a step of 2
        }

        ans = ans * add ;  // Multiply the answer with the calculated sum

        cout << ans << endl ;  // Print the final answer
    } else {  // If p is not 0, calculate the answer using a similar formula
        BigInteger add = BigInteger ( "0" ) ;

        for ( int i = 1 ; i <= k1 ; i += 2 ) {
            add = add + C ( i, k1 ) ;  // Calculate the sum of C(i, k1) for i from 1 to k1 with a step of 2
        }

        ans = ans * add ;  // Multiply the answer with the calculated sum

        cout << ans << endl ;  // Print the final answer
    }

    return 0 ;
}

