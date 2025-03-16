#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MOD 1000000007
#define MAX_N 1000000
#define MAX_K 1000000
#define MAX_S_LEN 1000000
#define MAX_SEG_CNT 1000000
#define MAX_CUR_HAPPY 1000000
#define MAX_ANS 1000000
int main ( ) {
    int N, K;
    char S [ MAX_S_LEN + 1 ];
    scanf ( "%d %d", &N, &K );
    scanf ( "%s", S );
    int seg_cnt = 0;
    for ( int i = 0 ; i < N - 1 ; i++ ) {
        if ( S [ i ]!= S [ i + 1 ] ) {
            seg_cnt++;
        }
    }
    int cur_happy = N - 1 - seg_cnt;
    if ( 2 * K >= seg_cnt ) {
        int ans = N - 1;
        printf ( "%d\n", ans );
    } else {
        int ans = cur_happy + 2 * K;
        printf ( "%d\n", ans );
    }
    return 0;
}
