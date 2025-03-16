#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000

char buffer[MAX_LINE_LENGTH];
int pos = 0;

char* NextLine() {
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return buffer;
}

int NextInt() {
    return atoi(NextLine());
}

void Write(int s) {
    printf("%d\n", s);
}

int Bipartite(char** S, int N) {
    int* D = (int*)malloc(N * sizeof(int));
    D[0] = 1;
    int* Q = (int*)malloc(N * sizeof(int));
    int ret = 1;
    int q_pos = 1;
    for (int i = 0; i < N; i++) {
        if (!ret) break;
        int q = Q[i];
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') continue;
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q[q_pos++] = j;
                continue;
            }
            if (D[j] % 2 == D[q] % 2) {
                ret = 0;
                break;
            }
        }
    }
    free(D);
    free(Q);
    return ret;
}

int WarshallFloyd(char** S, int N) {
    int** G = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        G[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else {
                G[i][j] = (S[i][j] == '0') ? N : 1;
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
    for (int i = 0; i < N; i++) {
        free(G[i]);
    }
    free(G);
    return ans + 1;
}

int main() {
    int N = NextInt();
    char** S = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        S[i] = NextLine();
    }
    if (!Bipartite(S, N)) {
        Write(-1);
    } else {
        Write(WarshallFloyd(S, N));
    }
    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);
    return 0;
}
