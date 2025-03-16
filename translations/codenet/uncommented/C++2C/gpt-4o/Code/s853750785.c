#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100005

int N, M;
int H[MAX_N];
int G[MAX_N][MAX_N]; // Adjacency list representation
int G_size[MAX_N]; // To keep track of the number of edges for each node

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
        G_size[i] = 0; // Initialize the size of each adjacency list
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; // Convert to 0-based index
        G[u][G_size[u]++] = v; // Add v to the adjacency list of u
        G[v][G_size[v]++] = u; // Add u to the adjacency list of v
    }
    
    long long ans = 0;
    
    for (int u = 0; u < N; u++) {
        bool flag = true;
<<<<<<< HEAD
        for (int j = 0; j < G_size[u]; j++) {
            int v = G[u][j];
=======
        for (int i = 0; i < G_size[u]; i++) {
            int v = G[u][i];
>>>>>>> 98c87cb78a (data updated)
            if (H[u] <= H[v]) {
                flag = false;
                break; // No need to check further if we found a taller neighbor
            }
        }
        if (flag) ans++;
    }
    
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
