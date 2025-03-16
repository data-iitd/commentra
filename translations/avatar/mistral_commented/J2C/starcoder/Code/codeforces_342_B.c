
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, s, f, maxT, k, a, b, d, cur;
    char M;
    char actions[1000000];
    scanf("%d %d %d %d", &m, &s, &f, &maxT);
    if (s < f) {
        M = 'R';
        d = 1;
    } else {
        M = 'L';
        d = -1;
    }
    cur = s;
    for (int t = 1; t <= maxT; t++) {
        if (m > 0) {
            scanf("%d %d %d", &k, &a, &b);
            m--;
            if (cur >= a && cur <= b || cur + d >= a && cur + d <= b) {
                actions[t - 1] = 'X';
            } else {
                actions[t - 1] = M;
                cur += d;
            }
        } else {
            actions[t - 1] = M;
            cur += d;
        }
        if (cur == f) {
            break;
        }
    }
    while (cur!= f) {
        actions[t - 1] = M;
        cur += d;
    }
    printf("%s", actions);
    return 0;
}

