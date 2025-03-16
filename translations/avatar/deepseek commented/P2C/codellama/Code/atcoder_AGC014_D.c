#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 100000
#define MAX_M 100000

int N, M;
int adj[MAX_N + 1][MAX_M];
int seen[MAX_N + 1];
int par[MAX_N + 1];
int child_num[MAX_N + 1];
int seq[MAX_N + 1];
int seq_size;

void bfs(int start) {
    int i, u, v;
    int que[MAX_N + 1];
    int que_size = 0;

    que[que_size++] = start;
    seen[start] = 1;

    while (que_size > 0) {
        u = que[--que_size];
        for (i = 0; i < M; i++) {
            v = adj[u][i];
            if (seen[v] == 0) {
                seen[v] = 1;
                par[v] = u;
                child_num[u]++;
                que[que_size++] = v;
            }
        }
    }
}

void find_leaf_nodes() {
    int i;
    for (i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            seq[seq_size++] = i;
        }
    }
}

void process_leaf_nodes() {
    int i, c;
    for (i = 0; i < seq_size; i++) {
        c = seq[i];
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            exit(0);
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            seq[seq_size++] = par[par[c]];
        }
    }
}

int main() {
    int i, a, b;

    scanf("%d", &N);
    M = N - 1;

    for (i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        adj[a][i] = b;
        adj[b][i] = a;
    }

    bfs(1);
    find_leaf_nodes();
    process_leaf_nodes();

    printf("Second\n");

    return 0;
}

