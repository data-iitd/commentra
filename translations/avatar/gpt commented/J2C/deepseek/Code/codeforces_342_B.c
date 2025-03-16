#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, s, f;
    scanf("%d %d %d", &m, &s, &f);

    int maxT = -1;
    int** map = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        map[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        map[k][0] = a;
        map[k][1] = b;
        if (k > maxT) {
            maxT = k;
        }
    }

    char actions[100000];
    int cur = s;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;

    for (int t = 1; t <= maxT; t++) {
        int a = -1, b = -1;
        if (t <= maxT && map[t][0] != 0) {
            a = map[t][0];
            b = map[t][1];
        }

        if ((a != -1 && (cur >= a && cur <= b)) || (cur + d >= a && cur + d <= b)) {
            actions[t] = 'X';
        } else {
            actions[t] = M;
            cur += d;
        }

        if (cur == f) {
            break;
        }
    }

    while (cur != f) {
        actions[t] = M;
        cur += d;
    }

    for (int i = 1; i <= maxT; i++) {
        printf("%c", actions[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}
