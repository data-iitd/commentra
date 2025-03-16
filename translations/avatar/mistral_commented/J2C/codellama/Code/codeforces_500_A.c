
#include <stdio.h>
#include <stdbool.h>

bool dfs ( int currpos , int* arr , int target ) {
    if ( currpos ==target ) {
        return true ;
    }
    if ( currpos==arr[0]+1 ) {
        return false ;
    }
    bool teleport = dfs ( currpos+arr[currpos-1], arr, target ) ;
    if ( teleport ) {
        return true ;
    }
    return false ;
}

int main ( ) {
    int n ;
    int goal ;
    int* arr ;
    bool isFound ;
    scanf ( "%d", &n ) ;
    scanf ( "%d", &goal ) ;
    arr = ( int* ) malloc ( n-1*sizeof ( int ) ) ;
    for ( int i = 0 ; i < n-1 ; i ++ ) {
        scanf ( "%d", &arr[i] ) ;
    }
    isFound = dfs ( 1 , arr , goal ) ;
    if ( isFound ) {
        printf ( "YES\n" ) ;
    } else {
        printf ( "NO\n" ) ;
    }
    free ( arr ) ;
    return 0 ;
}

