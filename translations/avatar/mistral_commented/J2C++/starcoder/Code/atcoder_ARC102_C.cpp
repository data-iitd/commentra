#include <bits/stdc++.h>

using namespace std ;

// Import the C++ standard library

int mod = 998244353 ;

// Declare a static integer variable'mod' with the value 998244353

long long nchoosek [ 4001 ] [ 4001 ] ;

// Declare a 2-dimensional long long array 'nchoosek' for storing binomial coefficients

int main ( ) {
    // The main method where the program starts execution

    for ( int i = 0 ; i < 4001 ; i ++ ) {
        // Iterate through each row of the 'nchoosek' array

        nchoosek [ i ] [ 0 ] = nchoosek [ i ] [ i ] = 1 ;

        // Set the first element of each row and the last element of each row to 1
    }

    // Initialize the first two elements of each row to 1

    for ( int i = 2 ; i < 4001 ; i ++ ) {
        // Iterate through each row starting from the third row

        for ( int j = 1 ; j < i ; j ++ ) {
            // Iterate through each column starting from the second column

            nchoosek [ i ] [ j ] = ( nchoosek [ i - 1 ] [ j ] + nchoosek [ i - 1 ] [ j - 1 ] ) % mod ;

            // Calculate the binomial coefficient 'nCj' using the formula 'nCj = nCj-1 + nCj-2'
        }
    }

    // Calculate the binomial coefficients using the recursive formula

    int k ;

    // Declare an integer variable 'k' to store the first integer 'k'

    cin >> k ;

    // Read the first integer 'k' from the console

    int n ;

    // Declare an integer variable 'n' to store the second integer 'n'

    cin >> n ;

    // Read the second integer 'n' from the console

    for ( int i = 2 ; i <= 2 * k ; i ++ ) {
        // Iterate through all possible values of 'i' from 2 to 2*k

        int pairs ;

        // Declare an integer variable 'pairs' to store the number of pairs of 'i'

        if ( i > k ) {
            // If 'i' is greater than 'k', calculate the number of pairs

            pairs = k - i / 2 ;
        } else {
            // Otherwise, calculate the number of pairs for the first half of 'i'

            pairs = ( i - 1 ) / 2 ;
        }

        // Calculate the number of pairs based on the value of 'i'

        int active = k - 2 * pairs ;

        // Declare an integer variable 'active' to store the number of active elements

        if ( i % 2 == 0 ) active -= 1 ;

        // If 'i' is even, decrease the number of active elements by 1

        long long times2 = 1 ;

        // Declare a long long variable 'times2' to store the intermediate result for calculating 'nCj'

        long long total = 0 ;

        // Declare a long long variable 'total' to store the final result

        for ( int j = 0 ; j <= pairs ; j ++ ) {
            // Iterate through each pair 'j' from 0 to 'pairs'

            long long choice = times2 * nchoosek [ pairs ] [ j ] % mod ;

            // Calculate the binomial coefficient 'nCj' using the previously calculated binomial coefficients

            times2 = times2 * 2 % mod ;

            // Multiply the result by 2 to get 'nCj+1'

            if ( active + j - 1 < 0 ) continue ;

            // If the number of active elements is less than 0, skip to the next iteration

            total += choice * nchoosek [ n + active - 1 ] [ active + j - 1 ] ;

            // Multiply the result with the corresponding element of the 'nchoosek' array

            if ( i % 2 == 0 ) {
                // If 'i' is even, add the result multiplied by the element at the position 'n+active-2, active+j-1'

                total += choice * nchoosek [ n + active - 2 ] [ active + j - 1 ] ;
            }

            // Add the result multiplied by the corresponding element of the 'nchoosek' array (if 'i' is even)

            total %= mod ;

            // Take the modulo to ensure the result does not exceed the value of'mod'
        }

        // Calculate the final result by summing up all the intermediate results

        cout << total << endl ;

        // Print the final result to the console
    }

    // End the program with a newline character
}

// 