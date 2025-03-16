
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main ( ) {
    int n, q, i, j, left, right;
    char *c;
    int **range, *frag, *rui;

    scanf ("%d %d", &n, &q);
    c = (char *) malloc (sizeof (char) * (n + 1));
    scanf ("%s", c);
    range = (int **) malloc (sizeof (int *) * q);
    for (i = 0; i < q; i ++) {
        range [i] = (int *) malloc (sizeof (int) * 2);
        scanf ("%d %d", &range [i] [0], &range [i] [1]);
    }

    frag = (int *) malloc (sizeof (int) * (n + 1));
    rui = (int *) malloc (sizeof (int) * (n + 1));
    for (i = 2; i <= n; i ++) {
        if (c [i - 2] == 'A' && c [i - 1] == 'C') {
            frag [i] ++;
        }
        rui [i] = rui [i - 1] + frag [i];
    }

    for (i = 0; i < q; i ++) {
        left = range [i] [0];
        right = range [i] [1];
        printf ("%d\n", rui [right] - rui [left]);
    }

    return 0;
}

