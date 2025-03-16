
#include <stdio.h>

int main ( ) {
    int a, at, b, bt, t1, t2, st, fin, now, ans;
    scanf ( "%d:%d %d:%d", &t1, &t2, &a, &at );
    st = t2 + ( t1 - 5 ) * 60;
    fin = st + at;
    now = 0;
    ans = 0;
    while ( now < fin && now < 1140 ) {
        if ( now + bt > st ) {
            ans += 1;
        }
        now += b;
    }
    printf ( "%d\n", ans );
    return 0;
}

