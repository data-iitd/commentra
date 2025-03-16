
#include <stdio.h>
#include <string.h>

int main ( ) {
    char S [ 100000 ] ; // Defining a character array to store the input string
    int N = 0 ; // Defining an integer variable to store the length of the string
    int mod_arr [ 100000 ] = { 0 } ; // Defining an integer array to store intermediate results
    int mod_cnt [ 2019 ] = { 0 } ; // Defining an integer array to count the frequency of each number
    int radix = 1 ; // Defining an integer variable to store the radix

    scanf ( "%s", S ) ; // Reading the first line of input as a string
    N = strlen ( S ) ; // Getting the length of the string

    for ( int i = 0 ; i < N ; i ++ ) { // Iterating through each character in the string
        int tmp = 0 ; // Defining a temporary variable to store the intermediate result

        // Calculating the value of the current digit in the given base
        tmp = ( ( int ) S [ N - 1 - i ] - ( int ) '0' ) * radix % 2019 ;

        // Updating the temporary variable with the carry from the previous digit
        if ( i != 0 ) tmp = ( tmp + mod_arr [ i - 1 ] ) % 2019 ;

        // Storing the intermediate result in the array
        mod_arr [ i ] = tmp ;

        // Updating the frequency count of the current number in the array
        mod_cnt [ tmp ] ++ ;

        // Updating the radix for the next iteration
        radix = radix * 10 % 2019 ;
    }

    long ans = 0L ; // Defining a long variable to store the final answer

    // Calculating the answer by summing up the terms of the formula
    for ( int i = 0 ; i < 2019 ; i ++ ) {
        ans += mod_cnt [ i ] * ( mod_cnt [ i ] - 1 ) / 2 ;
    }

    printf ( "%ld\n", ans ) ; // Printing the final answer

    return 0 ;
}

