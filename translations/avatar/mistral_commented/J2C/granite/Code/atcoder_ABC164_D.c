

#include <stdio.h> // Including the standard input/output library
#include <string.h> // Including the string manipulation library

int main ( void ) { // Starting the main method
    char S [ 100001 ] ; // Creating a character array to store the input string
    int N ; // Creating an integer variable to store the length of the string
    int mod_arr [ 100000 ] ; // Creating an array of size 100000 to store intermediate results
    int mod_cnt [ 2019 ] ; // Creating an array of size 2019 to count the frequency of each number
    int radix = 1 ; // Initializing the radix to 1

    // Reading the first line of input as a string
    scanf ( "%s", S ) ;
    N = strlen ( S ) ; // Getting the length of the string

    for ( int i = 0 ; i < N ; i ++ ) { // Iterating through each character in the string
        int tmp = 0 ; // Initializing a temporary variable to store the intermediate result

        // Calculating the value of the current digit in the given base
        tmp = ( ( int ) S [ N - 1 - i ] - ( int ) '0' ) * radix % 2019 ;

        // Updating the temporary variable with the carry from the previous digit
        if ( i!= 0 ) tmp = ( tmp + mod_arr [ i - 1 ] ) % 2019 ;

        // Storing the intermediate result in the array
        mod_arr [ i ] = tmp ;

        // Updating the frequency count of the current number in the array
        mod_cnt [ tmp ] ++ ;

        // Updating the radix for the next iteration
        radix = radix * 10 % 2019 ;
    }

    long long ans = 0LL ; // Initializing a long long variable to store the final answer

    // Calculating the answer by summing up the terms of the formula
    for ( int i = 0 ; i < 2019 ; i ++ ) {
        ans += mod_cnt [ i ] * ( mod_cnt [ i ] - 1 ) / 2 ;
    }

    printf ( "%lld\n", ans ) ; // Printing the final answer

    return 0 ; // Returning 0 to indicate successful execution
}

