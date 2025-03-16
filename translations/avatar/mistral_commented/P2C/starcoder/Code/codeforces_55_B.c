
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int nums [ 4 ], ans = 10000000000000000000000000, i, j, k, s, t;
    char operations [ 1000000 ];
    scanf ( "%d %d %d %d", nums, nums + 1, nums + 2, nums + 3 );
    scanf ( "%s", operations );
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = i + 1 ; j < 4 ; j ++ ) {
            for ( k = j + 1 ; k < 4 ; k ++ ) {
                s = nums [ j ];
                nums [ j ] = - 1;
                t = nums [ k ];
                if ( operations [ i ] == '+' ) {
                    nums [ k ] = s + t;
                }
                else if ( operations [ i ] == '*' ) {
                    nums [ k ] = s * t;
                }
                if ( i == 2 && nums [ k ] < ans ) {
                    ans = nums [ k ];
                }
                for ( j = 0 ; j < 4 ; j ++ ) {
                    for ( k = j + 1 ; k < 4 ; k ++ ) {
                        s = nums [ j ];
                        nums [ j ] = - 1;
                        t = nums [ k ];
                        if ( operations [ i ] == '+' ) {
                            nums [ k ] = s + t;
                        }
                        else if ( operations [ i ] == '*' ) {
                            nums [ k ] = s * t;
                        }
                        if ( i == 2 && nums [ k ] < ans ) {
                            ans = nums [ k ];
                        }
                    }
                }
                nums [ j ] = s;
                nums [ k ] = t;
            }
        }
    }
    printf ( "%d", ans );
    return 0;
}

