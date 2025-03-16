#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int q, n, x;
    long s;
    scanf ("%d", &q);
    while (q-- > 0) {
        scanf ("%d", &n);
        x = (int) (log (n) / log (2));
        x++;
        s = -1 * (long) pow (2, x) + 2 + (long) n * (long) (n + 1) / 2 - (long) pow (2, x);
        printf ("%ld\n", s);
    }
    return 0;
}

