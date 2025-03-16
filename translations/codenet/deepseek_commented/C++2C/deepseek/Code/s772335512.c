#include <stdio.h>
#include <stdlib.h>

// Step 2: Define global variables
// G is a vector of vectors representing the graph.
int* G[100000];
int G_sizes[100000];
// used is a boolean array to keep track of visited nodes.
int used[100000];
// grundy is an array to store the Grundy number of each node.
int grundy[100000];

// Step 3: Define the dfs function
// The function dfs is used to perform a depth-first search on the graph.
void dfs(int v, int N){
    // It marks the current node as visited.
    used[v] = 1;
    // It initializes the Grundy number of the current node to 0.
    grundy[v] = 0;
    // It iterates through all the neighbors of the current node.
    for(int i = 0; i < G_sizes[v]; i++){
        // If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if(!used[G[v][i]]){
            dfs(G[v][i], N);
            // It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
            grundy[v] ^= (grundy[G[v][i]]+1);
        }
    }
}

// Step 4: Main function
int main(){
    // It reads the number of nodes N.
    int N;
    scanf("%d", &N);
    // It reads the edges of the graph and constructs the adjacency list.
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        // Allocate memory for the adjacency list if not already done
        if (G[x] == NULL) {
            G[x] = (int*)malloc(100 * sizeof(int));
            G_sizes[x] = 0;
        }
        if (G[y] == NULL) {
            G[y] = (int*)malloc(100 * sizeof(int));
            G_sizes[y] = 0;
        }
        G[x][G_sizes[x]++] = y;
        G[y][G_sizes[y]++] = x;
    }
    // It calls the dfs function starting from node 0.
    dfs(0, N);
    // It checks the Grundy number of the root node (node 0).
    if(grundy[0] != 0){
        // It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
    // Free allocated memory
    for (int i = 0; i < N; i++) {
        if (G[i] != NULL) {
            free(G[i]);
        }
    }
    return 0;
}
