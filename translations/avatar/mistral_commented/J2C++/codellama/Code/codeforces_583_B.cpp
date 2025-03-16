
#include <iostream>
#include <cstdlib>

using namespace std ;

int main ( ) {
    int n ; // Declaring the variable 'n' to store the number of elements in the arrays
    int * a ; // Declaring a pointer 'a' to store the address of the first element of the array 'a'
    int * b ; // Declaring a pointer 'b' to store the address of the first element of the array 'b'
    int s = - 1 ; // Initializing the variable 's' to -1
    while ( true ) { // Main loop to read input until the end of the file is reached
        cin >> n ; // Reading the number of elements in the arrays
        if ( n == 0 ) { // If the number of elements is 0, break the loop
            break ;
        }
        a = new int [ n ] ; // Creating an integer array 'a' of size 'n'
        b = new int [ n ] ; // Creating an integer array 'b' of size 'n'
        for ( int i = 0 ; i < n ; i ++ ) { // Loop to read and initialize the arrays 'a' and 'b'
            cin >> a [ i ] ; // Reading an integer value and storing it in the 'i'th position of array 'a'
            b [ i ] = 0 ; // Initializing all elements of array 'b' to zero
        }
        int tem = 1 ; // Initializing the variable 'tem' to 1
        int q = 0 ; // Initializing the variable 'q' to 0
        while ( q != n ) { // Main loop to find the sequence length
            s ++ ; // Incrementing the variable 's'
            if ( tem == 1 ) { // If 'tem' is 1, perform the first half of the loop
                for ( int i = 0 ; i < n ; i ++ ) {
                    if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                        b [ i ] = 1 ; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                    }
                }
                tem = 0 ; // Switching the value of 'tem' to 0
            } else { // If 'tem' is 0, perform the second half of the loop
                for ( int i = n - 1 ; i >= 0 ; i -- ) {
                    if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                        b [ i ] = 1 ; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                    }
                }
                tem = 1 ; // Switching the value of 'tem' to 1
            }
        }
        cout << s << endl ; // Printing the length of the sequence found
    }
    return 0 ;
}

