#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int long long
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22
#define MAX_N 100000

typedef struct {
    int _1, _2;
} P;

int N; // Number of nodes in the tree
P G[MAX_N][MAX_N]; // Adjacency list representation of the tree
int U[MAX_L][MAX_N], R[MAX_N]; // U for storing ancestors, R for depth
long long L[MAX_N]; // L for storing the distance from the root

// Depth-first search to initialize ancestor and depth information
void dfs(int x, int p, int r, long long l) {
    U[0][x] = p; // Set the parent of the current node
    R[x] = r; // Set the depth of the current node
    L[x] = l; // Set the distance from the root to the current node
    for (int i = 0; i < MAX_N; i++) { // Iterate through all adjacent nodes
        if (G[x][i]._1 == 0) break; // Stop if no more edges
        int t = G[x][i]._1; // Get the adjacent node
        if (t == p) continue; // Skip the parent node to avoid cycles
        dfs(t, x, r + 1, l + G[x][i]._2); // Recursive DFS call for the child node
    }
}

// Function to find the lowest common ancestor (LCA) of two nodes
int lca(int a, int b) {
    if (R[a] > R[b]) {
<<<<<<< HEAD
        int temp = a; a = b; b = temp; // Ensure a is the deeper node
=======
        int temp = a;
        a = b;
        b = temp; // Ensure a is the deeper node
>>>>>>> 98c87cb78a (data updated)
    }
    for (int k = 0; k < MAX_L; k++) { // Adjust b to the same depth as a
        if ((R[a] - R[b]) >> k & 1) b = U[k][b];
    }
    if (a == b) return a; // If both nodes are the same, return a
    for (int k = MAX_L - 1; k >= 0; k--) { // Find the LCA using binary lifting
        if (U[k][a] != U[k][b]) {
            a = U[k][a];
            b = U[k][b];
        }
    }
    return U[0][a]; // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
long long dist(int x, int y) {
    int g = lca(x, y); // Find the LCA of x and y
    return L[x] + L[y] - 2LL * L[g]; // Calculate the distance using LCA
}

int main() {
    scanf("%lld", &N); // Read the number of nodes
    for (int i = 0; i < N - 1; i++) { // Read the edges of the tree
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c); // Read nodes and weight
        a--, b--; // Convert to 0-based indexing
        G[a][i] = (P){b, c}; // Add edge to the adjacency list
        G[b][i] = (P){a, c}; // Add the reverse edge
    }
    
    // Initialize the ancestor table with -1
    for (int i = 0; i < MAX_L; i++) {
        for (int j = 0; j < N; j++) {
            U[i][j] = -1;
        }
    }
    
    // Perform DFS from the root to fill ancestor and depth information
    dfs(0, -1, 0, 0);
    
    // Precompute ancestors for binary lifting
    for (int i = 0; i < MAX_L - 1; i++) {
        for (int v = 0; v < N; v++) {
            if (U[i][v] == -1) U[i + 1][v] = -1; // If no ancestor, set to -1
            else U[i + 1][v] = U[i][U[i][v]]; // Set the 2^(i+1) ancestor
        }
    }
    
    int Q, K; // Number of queries and a specific node K
    scanf("%lld %lld", &Q, &K); // Read number of queries and node K
    K--; // Convert K to 0-based indexing
    
    // Process each query
    for (int i = 0; i < Q; i++) {
        int x, y; // Nodes for which distance is to be calculated
        scanf("%lld %lld", &x, &y); // Read the nodes
        x--, y--; // Convert to 0-based indexing
        // Output the total distance from x to K and K to y
        printf("%lld\n", dist(x, K) + dist(K, y));
    }
    
    return 0; // End of the program
}

// <END-OF-CODE>
