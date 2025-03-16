#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int nums [ 3 ] = { 0, 0, 0 };
    char operations [ 3 ] [ 10 ] = { 0 };
    int ans = 10000000000000000000000000;
    int i = 0;
    int j = 0;
    int k = 0;
    int s = 0;
    int t = 0;
    scanf ( "%d %d %d", &nums [ 0 ], &nums [ 1 ], &nums [ 2 ] );
    scanf ( "%s %s %s", &operations [ 0 ], &operations [ 1 ], &operations [ 2 ] );
    for ( i = 0 ; i < 3 ; i++ ) {
        for ( j = 0 ; j < 4 ; j++ ) {
            for ( k = j + 1 ; k < 4 ; k++ ) {
                if ( nums [ j ]!= -1 && nums [ k ]!= -1 ) {
                    s = nums [ j ];
                    nums [ j ] = -1;
                    t = nums [ k ];
                    if ( strcmp ( operations [ i ], "+" ) == 0 ) {
                        nums [ k ] = s + t;
                    } else if ( strcmp ( operations [ i ], "*" ) == 0 ) {
                        nums [ k ] = s * t;
                    }
                    if ( i == 2 && nums [ k ] < ans ) {
                        ans = nums [ k ];
                    }
                }
            }
        }
    }
    printf ( "%d", ans );
    return 0;
}
