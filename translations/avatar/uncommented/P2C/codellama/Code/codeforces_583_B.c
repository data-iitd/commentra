#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int a [ n ];
    for ( int i = 0; i < n; i++ ) {
        scanf ( "%d", &a [ i ] );
    }
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    while ( counter < n ) {
        counter_turns += 1;
        for ( int i = 0; i < n; i++ ) {
            if ( a [ i ] != - 1 && a [ i ] <= counter ) {
                counter += 1;
                a [ i ] = - 1;
            }
        }
        for ( int i = 0; i < n; i++ ) {
            if ( a [ i ] != - 1 ) {
                a [ i ] = - 1;
            }
        }
    }
    printf ( "%d\n", counter_turns );
    return 0;
}
