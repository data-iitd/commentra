
#include <iostream>
#include <cstring>

using namespace std ; // Using the standard namespace

const long mod = 1000000007 ; // Defining a constant value for modulus

int main ( ) { // Main method to start the program
    int n, q ; // Declaring and initializing variables to store the length of the string and the number of queries
    char c [ ] ; // Declaring and initializing a character array to store the string

    cin >> n >> q ; // Reading the first integer input representing the length of the string and the second integer input representing the number of queries

    c = new char [ n + 1 ] ; // Allocating memory for the character array

    for ( int i = 0 ; i < n ; i ++ ) { // Loop to read the string
        cin >> c [ i ] ;
    }

    int range [ q ] [ 2 ] ; // Declaring and initializing a 2D array to store the range of each query

    for ( int i = 0 ; i < q ; i ++ ) { // Loop to read the range of each query
        cin >> range [ i ] [ 0 ] >> range [ i ] [ 1 ] ;
    }

    int frag [ n + 1 ] ; // Declaring and initializing an array to store the frequency of 'AC' substring
    int rui [ n + 1 ] ; // Declaring and initializing an array to store the running sum of 'AC' substring frequency

    for ( int i = 2 ; i <= n ; i ++ ) { // Loop to iterate through the string from index 2 to the end
        if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) { // Checking if the current position is an 'AC' substring
            frag [ i ] ++ ; // Incrementing the frequency of 'AC' substring at the current position
        }
        rui [ i ] = rui [ i - 1 ] + frag [ i ] ; // Updating the running sum of 'AC' substring frequency
    }

    for ( int i = 0 ; i < q ; i ++ ) { // Loop to iterate through each query
        int left = range [ i ] [ 0 ] ; // Storing the starting index of the current query range
        int right = range [ i ] [ 1 ] ; // Storing the ending index of the current query range
        cout << rui [ right ] - rui [ left ] << endl ; // Printing the result of the current query
    }

    delete [ ] c ; // Deallocating memory for the character array

    return 0 ; // Returning 0 to indicate successful execution
}

