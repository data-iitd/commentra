
#include <iostream>
#include <cstring>

using namespace std ;

int main ( ) {
    int n, k, arr [ ] = { 0 } ; // Declaring and initializing the variables 'n', 'k', and the array 'arr'

    cin >> n >> k ; // Reading the values of 'n' and 'k' from the user

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> arr [ i ] ; // Reading the values of the array 'arr' from the user
    }

    string res = "" ; // Declaring and initializing the string 'res'
    int o = 0, e = 0 ; // Declaring and initializing the variables 'o' and 'e'

    // Counting the number of 1's and 0's in the array 'arr'
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( arr [ i ] == 1 ) ++ o ; // Incrementing the variable 'o' when the current element in the array is 1
        else ++ e ; // Incrementing the variable 'e' when the current element in the array is 0
    }

    // Processing the user queries
    for ( int i = 0 ; i < k ; i ++ ) {
        int l, r ; // Declaring and initializing the variables 'l' and 'r'

        cin >> l >> r ; // Reading the values of 'l' and 'r' from the user

        if ( ( r - l + 1 ) % 2 == 1 ) { // Checking if the length of the query is odd
            res += "0\n" ; // If the length is odd, appending '0' to the output string followed by a newline character
        } else { // If the length is even
            if ( ( r - l + 1 ) / 2 <= o ) { // Checking if half of the length is less than or equal to the number of 1's in the array
                res += "1\n" ; // If it is, appending '1' to the output string followed by a newline character
            } else { // Otherwise
                res += "0\n" ; // Appending '0' to the output string followed by a newline character
            }
        }
    }

    cout << res ; // Printing the final output string

    return 0 ; // Returning 0 to indicate successful execution
}

