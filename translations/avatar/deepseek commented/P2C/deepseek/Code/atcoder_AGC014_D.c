#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int adj[MAXN][MAXN];
int seen[MAXN];
int par[MAXN];
int child_num[MAXN];

void add_edge(int a, int b) {
    adj[a][b] = 1;
    adj[b][a] = 1;
}

int main() {
    int N;
    scanf("%d", &N);

    // Initialize adjacency list to store the graph
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            adj[i][j] = 0;
        }
    }

    // Read N-1 edges and populate the adjacency list
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    // Initialize deque for BFS and seen array to track visited nodes
    int que[MAXN];
    int front = 0, rear = 0;
    que[rear++] = 1;
    seen[1] = 1;

    // Array to store parent nodes
    memset(par, 0, sizeof(par));

    // Array to count the number of children for each node
    memset(child_num, 0, sizeof(child_num));

    // Perform BFS to find parent and child relationships
    while (front < rear) {
        int v = que[front++];
        for (int u = 1; u <= N; u++) {
            if (adj[v][u] == 1 && seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                que[rear++] = u;
            }
        }
    }

    // Find leaf nodes (nodes with no children)
    int seq[MAXN];
    int seq_size = 0;
    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            seq[seq_size++] = i;
        }
    }

    // Process leaf nodes to determine the winning strategy
    while (seq_size > 0) {
        int c = seq[--seq_size];
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if (child_num[par[par[c]]] == 0) {
            seq[seq_size++] = par[par[c]];
        }
    }

    // If no winning strategy is found for the first player, print 'Second'
    printf("Second\n");

    return 0;
}
