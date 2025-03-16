#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

// Declare a graph represented as an adjacency list
int G[MAX_NODES][MAX_NODES];
// Array to track visited nodes during DFS
bool used[MAX_NODES];
// Array to store the Grundy values for each node
int grundy[MAX_NODES];

// Depth-First Search (DFS) function to compute Grundy values
void dfs(int v, int N){
    // Mark the current node as visited
    used[v] = true;
    // Initialize the Grundy value for the current node
    grundy[v] = 0;
    
    // Iterate through all adjacent nodes
    for(int i = 0; i < N; i++){
        if(G[v][i] == 1 && !used[i]){
            // Recursively perform DFS on the adjacent node
            dfs(i, N);
            // Update the Grundy value using the Grundy value of the child node
            grundy[v] ^= (grundy[i] + 1);
        }
    }
}

int main(){
    // Read the number of nodes in the graph
    int N;
    scanf("%d", &N);
    
    // Initialize the graph adjacency matrix with 0
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            G[i][j] = 0;
        }
    }
    
    // Read the edges of the graph
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        // Convert to zero-based indexing
        x--; y--;
        // Add the edge to the adjacency matrix
        G[x][y] = 1;
        G[y][x] = 1;
    }
    
    // Start DFS from the root node (node 0)
    dfs(0, N);
    
    // Determine the winner based on the Grundy value of the root node
    if(grundy[0] != 0){
        printf("Alice\n"); // Alice wins if Grundy value is non-zero
    }else{
        printf("Bob\n");   // Bob wins if Grundy value is zero
    }
    
