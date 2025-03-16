#include <stdio.h>
#include <stdlib.h>

int task4 ( int A , int B , int n ) {
    for ( int X = -1000 ; X <= 1000 ; X++ ) {
        if ( A * ( X ** n ) == B ) {
            return X;
        }
    }
    return "No solution";
}

int main () {
    int A, B, n;
    scanf ( "%d %d %d" , &A , &B , &n );
    printf ( "%d" , task4 ( A , B , n ) );
    return 0;
}
