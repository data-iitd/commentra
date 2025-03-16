#include <stdio.h>
#include <stdlib.h>

int get_nums ( int num , int t ) {
    int i;
    int *ans = ( int * ) malloc ( sizeof ( int ) * num );
    for ( i = 0 ; i < num ; i++ ) {
        if ( i < t % num ) {
            ans[i] = t / num + 1;
        } else {
            ans[i] = t / num;
        }
    }
    return ans;
}

int main () {
    int n , k , l , r , sa , sk;
    int *ans;
    scanf ( "%d %d %d %d %d %d" , &n , &k , &l , &r , &sa , &sk );
    ans = get_nums ( k , sk );
    ans = get_nums ( n - k , sa - sk );
    printf ( "%d " , ans[0] );
    for ( int i = 1 ; i < n ; i++ ) {
        printf ( "%d " , ans[i] );
    }
    printf ( "\n" );
    return 0;
}
