
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 1000

int main() {
    int m, s, f, maxT = -1;
    int cur = s;
    int a, b;
    char M;
    char actions[MAX_THREADS];
    int d;

    scanf("%d %*s %d %d", &m, &s, &f);

    int map[MAX_THREADS][2];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
        maxT = maxT < map[i][0] ? map[i][0] : maxT;
    }

    M = (s < f) ? 'R' : 'L';
    d = (s < f) ? 1 : -1;

    for (int t = 1; t <= maxT; t++) {
        if (map[t][0] == t) {
            a = map[t][1];
            b = map[t][2];

            if (cur >= a && cur <= b || cur + d >= a && cur + d <= b) {
                actions[t] = 'X';
            } else {
                actions[t] = M;
                cur += d;
            }

            if (cur == f) {
                break;
            }
        } else {
            actions[t] = M;
            cur += d;
        }
    }

    while (cur != f) {
        actions[t] = M;
        cur += d;
    }

    printf("%s\n", actions);

    return 0;
}

