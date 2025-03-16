#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define INF 1000000

char S[MAX_N][MAX_N + 1];
int D[MAX_N];
int Q[MAX_N];

int bipartite(int N) {
    D[0] = 1;
    int pos = 1;
    for (int i = 0; i < N; i++) {
        int q = Q[i];
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') continue;
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q[pos++] = j;
                continue;
            }
            if (D[j] % 2 == D[q] % 2) return -1;
        }
    }
    return 1;
}

int warshallFloyd(int N) {
    int G[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) G[i][j] = 0;
            else if (S[i][j] == '0') G[i][j] = INF;
            else G[i][j] = 1;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans < G[i][j]) ans = G[i][j];
        }
    }
    return ans + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }
    if (bipartite(N) == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", warshallFloyd(N));
    }
    return 0;
}
