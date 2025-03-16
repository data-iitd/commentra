

#include < stdio.h > 
#include < stdlib.h > 
#include < string.h > 

int main ( ) { 
    int n ; 
    scanf ( "%d", & n ) ; // Read the number of integers
    int * a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Allocate memory for the integers
    for ( int i = 0 ; i < n ; i ++ ) { 
        scanf ( "%d", & a [ i ] ) ; // Read each integer value
    } 
    qsort ( a, n, sizeof ( int ) ) ; 
    // Sort the integers in ascending order
    bool found = false ; // Initialize a flag to check for consecutive integers
    for ( int i = 0 ; i < n - 2 ; i ++ ) { 
        if ( a [ i ] + 1 == a [ i + 1 ] && a [ i + 1 ] + 1 == a [ i + 2 ] ) { 
            found = true ; // Set the flag if three consecutive integers are found
        } 
    } 
    printf ( found? "YES\n" : "NO\n" ) ; // Print "YES" if consecutive integers are found, otherwise print "NO"
    free ( a ) ; // Free the allocated memory
    return 0 ; 
} 
