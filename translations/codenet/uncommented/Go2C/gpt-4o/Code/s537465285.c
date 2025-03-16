#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define INF 1000

char S[MAX_N][MAX_N];
int D[MAX_N];
int G[MAX_N][MAX_N];

void NextLine(char *buffer) {
    fgets(buffer, MAX_N, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int NextInt() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer
    return n;
}

void Write(int s) {
    printf("%d\n", s);
}

bool Bipartite(int N) {
    memset(D, 0, sizeof(D));
    D[0] = 1;
    int Q[MAX_N];
    int pos = 1;
    Q[0] = 0;
    bool ret = true;

    for (int i = 0; i < N && ret; i++) {
        int q = Q[i];
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q[pos++] = j;
                continue;
            }
            if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int WarshallFloyd(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else if (S[i][j] == '0') {
                G[i][j] = INF;
            } else {
                G[i][j] = 1;
            }
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
            if (ans < G[i][j]) {
                ans = G[i][j];
            }
        }
    }
    return ans + 1;
}

int main() {
    int N = NextInt();
    for (int i = 0; i < N; i++) {
        NextLine(S[i]);
    }
    if (!Bipartite(N)) {
        Write(-1);
    } else {
        Write(WarshallFloyd(N));
    }
    return 0;
}

// <END-OF-CODE>
