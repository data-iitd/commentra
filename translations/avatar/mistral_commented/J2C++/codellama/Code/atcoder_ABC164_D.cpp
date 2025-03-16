
#include <iostream>
#include <string>

using namespace std ;

int main ( ) {
    string S ; // Declaring a string to store the input
    int N ; // Declaring an integer to store the length of the string

    cin >> S ; // Reading the first line of input as a string
    N = S.length ( ) ; // Getting the length of the string

    int mod_arr [ N ] ; // Declaring an array of size N to store intermediate results
    int mod_cnt [ 2019 ] ; // Declaring an array of size 2019 to count the frequency of each number
    int radix = 1 ; // Initializing the radix to 1

    for ( int i = 0 ; i < N ; i ++ ) { // Iterating through each character in the string
        int tmp = 0 ; // Initializing a temporary variable to store the intermediate result

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

    long ans = 0L ; // Initializing a long variable to store the final answer

    // Calculating the answer by summing up the terms of the formula
    for ( int i = 0 ; i < 2019 ; i ++ ) {
        ans += mod_cnt [ i ] * ( mod_cnt [ i ] - 1 ) / 2 ;
    }

    cout << ans << endl ; // Printing the final answer

    return 0 ;
}

