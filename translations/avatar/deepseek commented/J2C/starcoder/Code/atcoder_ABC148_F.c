
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--;
    v--;

    int edges[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    int d[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = 0;
    }
    d[u] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (edges[i][j] == 1 && d[j] == 0) {
                d[j] = d[i] + 1;
            }
        }
    }

    int e[MAX_N];
    for (int i = 0; i < N; i++) {
        e[i] = 0;
    }
    e[v] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (edges[i][j] == 1 && e[j] == 0) {
                e[j] = e[i] + 1;
            }
        }
    }

    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    return 0;
}

