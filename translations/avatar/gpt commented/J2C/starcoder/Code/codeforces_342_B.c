#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, s, f, maxT, k, a, b, cur, d;
    char M;
    scanf("%d %d %d", &m, &s, &f);
    maxT = -1;
    while (m > 0) {
        scanf("%d", &k);
        if (k > maxT) maxT = k;
        m--;
    }
    if (s < f) {
        M = 'R';
        d = 1;
    } else {
        M = 'L';
        d = -1;
    }
    cur = s;
    a = -1;
    b = -1;
    for (int t = 1; t <= maxT; t++) {
        if (t <= maxT) {
            scanf("%d %d", &a, &b);
        }
        if (cur >= a && cur <= b) {
            printf("X");
        } else {
            printf("%c", M);
            cur += d;
        }
        if (cur == f) break;
    }
    while (cur!= f) {
        printf("%c", M);
        cur += d;
    }
    printf("\n");
    return 0;
}

