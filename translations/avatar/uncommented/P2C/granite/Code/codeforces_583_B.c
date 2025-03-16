
#include <stdio.h>
#include <stdlib.h>

int main_function ( ) {
    int n;
    scanf ( "%d", & n );
    int * a = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0; i < n; i ++ ) {
        scanf ( "%d", & a [ i ] );
    }
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    while ( counter < n ) {
        counter_turns += 1;
        for ( int i = 0; i < n; i ++ ) {
            if ( a [ i ]!= - 1 && a [ i ] <= counter ) {
                counter += 1;
                a [ i ] = - 1;
            }
        }
        for ( int i = n - 1; i >= 0; i -- ) {
            a [ i ] = a [ i ] == - 1? 0 : a [ i ];
        }
    }
    printf ( "%d", counter_turns );
    return 0;
}

int main ( ) {
    main_function ( );
    return 0;
}

