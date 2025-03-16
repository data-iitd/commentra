
#include <bits/stdc++.h>
// Including necessary standard library headers

using namespace std ;
// Using the'std' namespace for standard library functions and objects

int main ( ) {
    // Declaring the main function, which is the entry point of the C++ application

    ios_base::sync_with_stdio ( false ) ;
    // Disabling synchronization between C and C++ input/output streams

    cin.tie ( NULL ) ;
    // Disabling buffering of input data

    int T ;
    // Declaring an integer variable 'T' to store the number of test cases

    cin >> T ;
    // Reading the number of test cases from the standard input stream

    while ( T -- ) {
        // Starting a while loop that iterates 'T' times

        int N ;
        // Declaring an integer variable 'N' to store the length of the string

        cin >> N ;
        // Reading the length of the string from the standard input stream

        string str ;
        // Declaring a string variable'str' to store the input string

        cin >> str ;
        // Reading the input string from the standard input stream

        int K ;
        // Declaring an integer variable 'K' to store the number of queries

        cin >> K ;
        // Reading the number of queries from the standard input stream

        int res = 0 ;
        // Declaring and initializing an integer variable'res' to store the result

        while ( K -- ) {
            // Starting a nested while loop that iterates 'K' times

            string query ;
            // Declaring a string variable 'query' to store the query string

            cin >> query ;
            // Reading the query string from the standard input stream

            int a = 0 ;
            int b = 0 ;
            // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string'str'

            for ( int i = 0 ; i < N ; i ++ ) {
                // Starting a for loop that iterates through each index of the string'str'

                if ( str [ i ] == query [ 0 ] )
                    a ++ ;  // Incrementing the 'a' variable if the character at the current index matches the first character of the query string

                else if ( str [ i ] == query [ 1 ] )
                    b ++ ;  // Incrementing the 'b' variable if the character at the current index matches the second character of the query string

                else {
                    res += min ( a, b ) ;  // Adding the minimum of 'a' and 'b' to the'res' variable if the current character is different from both characters in the query string
                    a = b = 0 ;  // Resetting the 'a' and 'b' variables to zero
                }
            }

            res += min ( a, b ) ;  // Adding the minimum of 'a' and 'b' to the'res' variable after the end of the outer for loop
        }

        cout << res << endl ;
        // Printing the final result to the standard output stream
    }

    return 0 ;
    // Returning 0 to indicate successful execution of the C++ program
}

