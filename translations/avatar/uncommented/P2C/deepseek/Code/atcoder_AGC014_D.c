#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int N;
int adj[MAXN][MAXN];
int seen[MAXN];
int par[MAXN];
int child_num[MAXN];

void add_edge(int a, int b) {
    adj[a][child_num[a]++] = b;
    adj[b][child_num[b]++] = a;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        child_num[i] = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    int que[MAXN];
    int front = 0, rear = 0;
    que[rear++] = 1;
    seen[1] = 1;
    par[1] = 0;

    while (front < rear) {
        int v = que[front++];
        for (int i = 0; i < child_num[v]; i++) {
            int u = adj[v][i];
            if (!seen[u]) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                que[rear++] = u;
            }
        }
    }

    int seq[MAXN];
    int seq_size = 0;
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            seq[seq_size++] = i;
        }
    }

    while (seq_size > 0) {
        int c = seq[seq_size - 1];
        seq_size--;
        seen[c] = 0;
        if (!seen[par[c]]) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            seq[seq_size++] = par[par[c]];
        }
    }

    printf("Second\n");
    return 0;
}
