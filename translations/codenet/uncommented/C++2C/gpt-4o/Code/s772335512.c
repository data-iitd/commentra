#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int G[MAX_N][MAX_N]; // Adjacency list representation
<<<<<<< HEAD
int G_size[MAX_N];   // To keep track of the size of each adjacency list
=======
int size[MAX_N]; // To keep track of the size of each adjacency list
>>>>>>> 98c87cb78a (data updated)
int used[MAX_N];
int grundy[MAX_N];

void dfs(int v) {
    used[v] = 1;
    grundy[v] = 0;
<<<<<<< HEAD
    for (int i = 0; i < G_size[v]; i++) {
=======
    for (int i = 0; i < size[v]; i++) {
>>>>>>> 98c87cb78a (data updated)
        int neighbor = G[v][i];
        if (!used[neighbor]) {
            dfs(neighbor);
            grundy[v] ^= (grundy[neighbor] + 1);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
<<<<<<< HEAD
        x--; y--; // Convert to 0-based index
        G[x][G_size[x]++] = y;
        G[y][G_size[y]++] = x;
=======
        x--; y--;
        G[x][size[x]++] = y;
        G[y][size[y]++] = x;
>>>>>>> 98c87cb78a (data updated)
    }
    dfs(0);
    if (grundy[0] != 0) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
    return 0;
}

// <END-OF-CODE>
