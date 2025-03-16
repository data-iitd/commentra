#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define MAX_N 100000
#define MAX_M 100000

// Function to read input from standard input
char* input() {
    static char buf[1024];
    fgets(buf, 1024, stdin);
    char* p = buf;
    while (*p =='' || *p == '\n' || *p == '\r') p++;
    return p;
}

int main() {
    // Read the number of nodes (N) and edges (M)
    int N, M;
    sscanf(input(), "%d %d", &N, &M);
    
    // Initialize an adjacency list to represent the graph
    int edge[MAX_N][MAX_N];
    memset(edge, 0, sizeof(edge));
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        sscanf(input(), "%d %d %d", &X, &Y, &Z);
        edge[X][Y] = Z;
        edge[Y][X] = Z;
    }
    
    // Array to track visited nodes
    bool used[MAX_N];
    memset(used, 0, sizeof(used));
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            ans++;  // Increment the count of connected components
            int queue[MAX_N];
            int front = 0, back = 0;
            queue[back++] = i;  // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (front < back) {
                int node = queue[front++];  // Dequeue a node
                used[node] = true;  // Mark the node as visited
                
                // Explore all adjacent nodes
                for (int nextnode = 0; nextnode < N; nextnode++) {
                    if (!used[nextnode] && edge[node][nextnode]) {  // If the adjacent node has not been visited
                        queue[back++] = nextnode;  // Enqueue the adjacent node
            }
        }
    }
    
    // Output the number of connected components found
    printf("%d\n", ans);
}

// 