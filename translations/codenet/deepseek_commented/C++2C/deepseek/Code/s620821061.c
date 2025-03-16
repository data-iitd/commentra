#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 520

typedef long long ll;

typedef struct {
    int G[2 * MAX_V][2 * MAX_V]; // Graph representation using adjacency matrix
    int match[2 * MAX_V]; // Array to store the match of each node
    int used[2 * MAX_V]; // Array to keep track of used nodes in DFS
    int V; // Number of vertices
} BitMatching;

BitMatching bm;

// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive call: compute GCD of b and the remainder of a divided by b
}

// Initialize the graph
void init(int V) {
    bm.V = V;
    for (int i = 0; i < 2 * V; i++) {
        for (int j = 0; j < 2 * V; j++) {
            bm.G[i][j] = 0; // Clear all edges
        }
        bm.match[i] = -1; // Initialize all matches to -1 (no match)
    }
}

// Add an edge between node a and node b in the bipartite graph
void add(int a, int b) {
    bm.G[a][b + bm.V] = 1; // Add edge from a to b+V
    bm.G[b + bm.V][a] = 1; // Add edge from b+V to a
}

// Depth-First Search to find augmenting paths
int dfs(int v) {
    bm.used[v] = 1; // Mark the node as visited
    for (int u = 0; u < 2 * bm.V; u++) {
        if (bm.G[v][u] && bm.match[u] == -1) { // If the node is not matched
            bm.match[v] = u; // Assign the match
            bm.match[u] = v; // Assign the match
            return 1; // Return true as we found an augmenting path
        }
    }
    for (int u = 0; u < 2 * bm.V; u++) {
        if (bm.G[v][u] && !bm.used[bm.match[u]] && dfs(bm.match[u])) { // If the node is matched and can find an augmenting path
            bm.match[v] = u; // Assign the match
            bm.match[u] = v; // Assign the match
            return 1; // Return true as we found an augmenting path
        }
    }
    return 0; // Return false if no augmenting path is found
}

// Execute the bipartite matching algorithm
int exec() {
    int res = 0; // Initialize the result
    for (int v = 0; v < bm.V; v++) {
        if (bm.match[v] == -1) { // If the node is not matched
            memset(bm.used, 0, sizeof(bm.used)); // Reset the used array
            res += dfs(v); // Perform DFS from the node and add the result
        }
    }
    return res; // Return the total number of matches found
}

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m); // Read the number of elements in the two sets
        if (n == 0) break; // If n is 0, break the loop
        init(n + m); // Initialize the bipartite graph with the total number of vertices
        int a[n], b[m]; // Arrays to store the elements of the two sets
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); // Read the elements of the first set
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]); // Read the elements of the second set
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j]) != 1) { // Check if the GCD is not 1
                    add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                }
            }
        }
        printf("%d\n", exec()); // Execute the bipartite matching and print the result
    }
    return 0;
}
