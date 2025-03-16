
#include <iostream>  // Including necessary C++ I/O packages
#include <cstdlib>  // Including necessary C++ standard library packages

using namespace std ;  // Using the standard namespace

int main ( ) {
    int n , i = 1 , k = 0 , p = 1 ;  // Declaring and initializing variables
    bool flag = true ;
    int a [ 1000 ] ;  // Declaring and initializing an integer array of size 1000

    cin >> n ;  // Reading the first integer from the standard input stream and assigning it to the variable 'n'

    i = 1 ;  // Initializing the variable 'i' to 1
    k = 0 ;  // Initializing the variable 'k' to 0
    p = 1 ;  // Initializing the variable 'p' to 1
    flag = true ;  // Initializing the boolean variable 'flag' to true

    while ( k <= n ) {  // Starting a while loop that runs as long as 'k' is less than or equal to 'n'
        i += k ;  // Incrementing the variable 'i' by the value of 'k'

        if ( i >= n ) {  // Checking if the value of 'i' is greater than or equal to 'n'
            while ( i >= n ) i = i - n ;  // If yes, then decrement 'i' by 'n' until it becomes less than 'n'
        }

        ++ a [ i ] ;  // Incrementing the value of the 'i'-th element of the array 'a' by 1
        ++ k ;  // Incrementing the variable 'k' by 1
    }

    for ( i=0 ; i<n ; ++i ) {  // Starting a for loop that runs from 0 to 'n'-1
        if ( a [ i ] == 0 ) {  // Checking if the 'i'-th element of the array 'a' is equal to 0
            flag = false ;  // If yes, then set the boolean variable 'flag' to false
            break ;  // Exiting the for loop
        }
    }

    if ( flag ) cout << "YES" << endl ;  // If the boolean variable 'flag' is still true after the for loop, then print "YES" to the standard output stream
    else cout << "NO" << endl ;  // Otherwise, print "NO" to the standard output stream

    return 0 ;  // Returning 0 to indicate that the program executed successfully
}

