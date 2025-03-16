#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a graph represented as an adjacency list
int G[100000][100000];
// Array to track visited nodes during DFS
int used[100000];
// Array to store the Grundy values for each node
int grundy[100000];

// Depth-First Search (DFS) function to compute Grundy values
void dfs(int v){
    // Mark the current node as visited
    used[v] = 1;
    // Initialize the Grundy value for the current node
    grundy[v] = 0;
    
    // Iterate through all adjacent nodes
    for(int i = 0; i < G[v][0]; i++){
        // If the adjacent node has not been visited
        if(!used[G[v][i+1]]){
            // Recursively perform DFS on the adjacent node
            dfs(G[v][i+1]);
            // Update the Grundy value using the Grundy value of the child node
            grundy[v] ^= (grundy[G[v][i+1]] + 1);
        }
    }
}

int main(){
    // Read the number of nodes in the graph
    int N;
    scanf("%d", &N);
    
    // Read the edges of the graph
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        // Convert to zero-based indexing
        x--; y--;
        // Add the edge to the adjacency list
        G[x][0]++;
        G[x][G[x][0]] = y;
        G[y][0]++;
        G[y][G[y][0]] = x;
    }
    
    // Start DFS from the root node (node 0)
    dfs(0);
    
    // Determine the winner based on the Grundy value of the root node
    if(grundy[0]!= 0){
        printf("Alice\n"); // Alice wins if Grundy value is non-zero
    }else{
        printf("Bob\n");   // Bob wins if Grundy value is zero
    }
}

