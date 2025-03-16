

#include <bits/stdc++.h> // Include the necessary header files

using namespace std ; // Using the standard namespace

const long long mod = 1000000007 ; // Define a constant value for modulus

int main ( ) { // Main function to start the program
    ios_base::sync_with_stdio ( false ) ; // Disable synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Disable unwanted behavior of cin.clear ( ) and cin.ignore ( )

    int n, q ; // Declare and initialize variables to store the length of the string and the number of queries respectively
    cin >> n >> q ;

    string s ; // Declare a string variable to store the input string
    cin >> s ;

    vector < vector < int > > range ( q, vector < int > ( 2 ) ) ; // Declare and initialize a 2D vector to store the range of each query

    for ( int i = 0 ; i < q ; i ++ ) { // Loop to read the range of each query
        cin >> range [ i ] [ 0 ] >> range [ i ] [ 1 ] ;
    }

    vector < int > frag ( n + 1 ) ; // Declare and initialize a vector to store the frequency of 'AC' substring
    vector < int > rui ( n + 1 ) ; // Declare and initialize a vector to store the running sum of 'AC' substring frequency

    for ( int i = 2 ; i <= n ; i ++ ) { // Loop to iterate through the string from index 2 to the end
        if ( s [ i - 2 ] == 'A' && s [ i - 1 ] == 'C' ) { // Checking if the current position is an 'AC' substring
            frag [ i ] ++ ; // Incrementing the frequency of 'AC' substring at the current position
        }
        rui [ i ] = rui [ i - 1 ] + frag [ i ] ; // Updating the running sum of 'AC' substring frequency
    }

    for ( int i = 0 ; i < q ; i ++ ) { // Loop to iterate through each query
        int left = range [ i ] [ 0 ] ; // Storing the starting index of the current query range
        int right = range [ i ] [ 1 ] ; // Storing the ending index of the current query range
        cout << rui [ right ] - rui [ left ] << endl ; // Printing the result of the current query
    }

    return 0 ; // Return 0 to indicate successful execution of the program
}

