

#include <stdio.h> // Include the header file for input/output operations

int main ( void ) { // Main function to start the program
    int n, q ; // Declaring and initializing variables to store the length of the string and the number of queries respectively
    char c [ 100001 ] ; // Declaring an array to store the string
    int range [ 100000 ] [ 2 ] ; // Declaring and initializing a 2D array to store the range of each query
    int frag [ 100001 ] = { 0 } ; // Declaring and initializing an array to store the frequency of 'AC' substring
    int rui [ 100001 ] = { 0 } ; // Declaring and initializing an array to store the running sum of 'AC' substring frequency

    scanf ( "%d %d", &n, &q ) ; // Reading the length of the string and the number of queries from the user

    scanf ( "%s", c ) ; // Reading the string from the user

    for ( int i = 2 ; i <= n ; i ++ ) { // Loop to iterate through the string from index 2 to the end
        if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) { // Checking if the current position is an 'AC' substring
            frag [ i ] ++ ; // Incrementing the frequency of 'AC' substring at the current position
        }
        rui [ i ] = rui [ i - 1 ] + frag [ i ] ; // Updating the running sum of 'AC' substring frequency
    }

    for ( int i = 0 ; i < q ; i ++ ) { // Loop to iterate through each query
        scanf ( "%d %d", &range [ i ] [ 0 ], &range [ i ] [ 1 ] ) ; // Reading the range of each query from the user
        printf ( "%d\n", rui [ range [ i ] [ 1 ] ] - rui [ range [ i ] [ 0 ] ] ) ; // Printing the result of the current query
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}

