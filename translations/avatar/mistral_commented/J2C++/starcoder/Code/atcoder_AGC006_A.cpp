#include <bits/stdc++.h>
using namespace std;

// Class declaration and initialization of static variables
int N = 200 + 10 ;  // Initializing the size of the arrays
int f [ ] = new int [ N ] ;  // Initializing the failure function array
char b [ ] = new char [ N ] ;  // Initializing the character arrays

// Function declaration and initialization of variables
void getFail ( char b [ ], int m ) {
    // Main logic of the function
    int j = 0 ;
    f [ 0 ] = f [ 1 ] = 0 ;  // Initializing the first two elements of the failure function array

    for ( int i = 2 ; i <= m ; i ++ ) {
        while ( j > 0 && b [ j + 1 ]!= b [ i ] ) j = f [ j ] ;  // Searching for the longest common prefix of the current and previous strings
        if ( b [ j + 1 ] == b [ i ] ) j ++ ;  // If the characters match, move to the next character in the current string
        f [ i ] = j ;  // Updating the failure function for the current index
    }
}

int main ( ) {
    // Main function declaration and initialization of variables
    ios_base :: sync_with_stdio ( false ) ;  // Disabling synchronization with C++'s standard input and output streams
    cin.tie ( NULL ) ;  // Disabling synchronization with C++'s standard input and output streams

    int n = cin.get ( ) - '0' ;  // Reading the number of characters in the strings
    string s1, str ;
    cin >> s1 >> str ;  // Reading the two strings from the input

    int cnt = 0 ;  // Initializing a counter for the number of characters in the combined string

    // Concatenating the two strings and creating character arrays for each
    for ( int i = 0 ; i < n ; i ++ ) b [ ++ cnt ] = str [ i ] ;
    for ( int i = 0 ; i < n ; i ++ ) b [ ++ cnt ] = s1 [ i ] ;

    getFail ( b, cnt ) ;  // Calling the getFail function to compute the failure function

    int len = min ( f [ cnt ], min ( n, n ) ) ;  // Computing the length of the longest common prefix

    cout << 2 * n - len << endl ;  // Writing the output to the console

    return 0 ;
}

