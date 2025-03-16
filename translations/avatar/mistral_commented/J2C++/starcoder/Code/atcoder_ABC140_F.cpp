
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    // Initialize a variable named N to store the number of slimes
    int N ;
    // Initialize a variable named size to store the size of the array S
    int size ;
    // Initialize a variable named next to keep track of the index of the current slime in array S
    int next ;
    // Initialize a variable named slime to store the current slime
    int slime ;
    // Initialize a variable named ans to store the answer
    bool ans ;

    // Initialize a variable named sc to store the input stream
    cin >> N ;
    // Calculate the size of the array S based on N
    size = ( 1 << N ) ;
    // Initialize the array S with user input
    int S [ size ] ;
    // Initialize a boolean array spawned to keep track of which slimes have been spawned
    bool spawned [ size ] ;
    // Set the last element of spawned to true, as it represents the position of the last slime
    spawned [ size - 1 ] = true ;

    // Read the initial positions of slimes from user input and store them in array S
    for ( int i = 0 ; i < size ; i ++ ) {
        cin >> S [ i ] ;
    }
    // Sort the array S in ascending order
    sort ( S, S + size ) ;

    // Initialize an ArrayList named active to store the indices of the currently active slimes
    list < int > active ;
    // Set the last element of spawned to true and add its index to the active list
    active.push_back ( size - 1 ) ;
    spawned [ size - 1 ] = true ;

    // Iterate through each generation of slimes
    for ( int i = 0 ; i < N ; i ++ ) {
        // Sort the ArrayList active in descending order
        active.sort ( greater < int > ( ) ) ;

        // Initialize an ArrayList named activated to store the indices of the slimes that will be activated in the next generation
        list < int > activated ;
        // Initialize a variable named next to keep track of the index of the current slime in array S
        next = size - 1 ;

        // Iterate through each slime in the current generation
        for ( auto slime : active ) {
            // While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
            while ( next >= 0 && ( S [ next ] >= slime || spawned [ next ] ) ) {
                next -- ;
            }
            // If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
            if ( next < 0 ) {
                cout << "No" << endl ;
                return 0 ;
            }
            // Set the current index as spawned and add its index to the activated ArrayList
            spawned [ next ] = true ;
            activated.push_back ( S [ next ] ) ;
        }
        // Add all the indices of the activated slimes to the active ArrayList
        active.merge ( activated ) ;
    }

    // Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
    cout << "Yes" << endl ;
}

