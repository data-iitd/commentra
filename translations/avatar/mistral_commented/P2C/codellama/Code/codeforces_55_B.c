
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000000000000000000000000

void rememberTheNumber ( int nums [ ] , int i , char operations [ ] , int ans [ ] ) {
    if ( i >= 3 ) {
        return;
    }
    for ( int j = 0 ; j < 4 ; j++ ) {
        for ( int k = j + 1 ; k < 4 ; k++ ) {
            if ( nums [ j ] != -1 && nums [ k ] != -1 ) {
                int s = nums [ j ];
                nums [ j ] = -1;
                int t = nums [ k ];
                if ( operations [ i ] == '+' ) {
                    nums [ k ] = s + t;
                } else if ( operations [ i ] == '*' ) {
                    nums [ k ] = s * t;
                }
                if ( i == 2 && nums [ k ] < ans [ 0 ] ) {
                    ans [ 0 ] = nums [ k ];
                }
                rememberTheNumber ( nums , i + 1 , operations , ans );
                nums [ j ] = s;
                nums [ k ] = t;
            }
        }
    }
}

int main ( ) {
    int nums [ 4 ];
    char operations [ 4 ];
    int ans [ 1 ];
    ans [ 0 ] = MAX_SIZE;
    for ( int i = 0 ; i < 4 ; i++ ) {
        scanf ( "%d" , &nums [ i ] );
    }
    for ( int i = 0 ; i < 4 ; i++ ) {
        scanf ( "%c" , &operations [ i ] );
    }
    rememberTheNumber ( nums , 0 , operations , ans );
    printf ( "%d\n" , ans [ 0 ] );
    return 0;
}

