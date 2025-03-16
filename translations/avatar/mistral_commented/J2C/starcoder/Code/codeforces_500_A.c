
#include <stdio.h>
#include <stdlib.h>

int dfs ( int currpos, int* arr, int target ) { // Defining the recursive depth-first search function
    if ( currpos ==target ) { // Base case: if the current position is the target position, return true
        return 1 ;
    }
    if ( currpos==arr[0]+1 ) { // Base case: if the current position is out of the array bounds, return false
        return 0 ;
    }
    int teleport = dfs ( currpos+arr[currpos-1], arr, target ) ; // Recursive call: try to teleport to the previous position
    if ( teleport ) { // If teleportation was successful, return true
        return 1 ;
    }
    return 0 ; // If teleportation was not successful, return false
}

int main ( ) { // Defining the main function
    int n, goal ;
    scanf ( "%d %d", &n, &goal ) ; // Reading the number of positions in the array and the target position from the standard input
    int* arr = ( int* ) malloc ( n*sizeof ( int ) ) ; // Creating an array of size n to store the positions of the teleportals
    for ( int i = 0 ; i < n ; i ++ ) { // Reading the positions of the teleportals from the standard input and storing them in the array
        scanf ( "%d", &arr[i] ) ;
    }
    int isFound = dfs ( 1, arr, goal ) ; // Calling the depth-first search function with the initial position and the target position
    if ( isFound ) { // If the target position was found, print "YES" to the standard output
        printf ( "YES" ) ;
    } else { // If the target position was not found, print "NO" to the standard output
        printf ( "NO" ) ;
    }
    return 0 ;
}

