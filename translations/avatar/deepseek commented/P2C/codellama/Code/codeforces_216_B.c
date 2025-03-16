#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int readInts() {  // Function to read integers from input
    int n, m;
    scanf("%d %d", &n, &m);
    return n, m;
}

int dfs(int g[MAX_SIZE][MAX_SIZE], int seen[MAX_SIZE], int i) {  // Depth-First Search to count nodes and edges in a graph
    if (seen[i]) {  // If node is already seen, return 0, 0
        return 0, 0;
    }
    seen[i] = 1;  // Mark the node as seen
    int nodes = 1;  // Initialize node count
    int edges = g[i][0];  // Count edges from the current node
    for (int j = 1; j < g[i][0]; j++) {  // Traverse all adjacent nodes
        int x, y = dfs(g, seen, g[i][j]);  // Recursively call dfs for each adjacent node
        nodes += x;  // Update node count
        edges += y;  // Update edge count
    }
    return nodes, edges;  // Return the count of nodes and edges
}

int solve() {  // Main function to solve the problem
    int n, m;
    int line0[2];
    try {
        line0 = readInts();  // Read the first line of input
    } catch (EOFError) {
        return 0;  // Return False if EOF is encountered
    }
    n = line0[0];
    m = line0[1];
    int g[MAX_SIZE][MAX_SIZE];  // Initialize an empty graph
    int seen[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {  // Initialize the graph with empty sets for each node
        g[i][0] = 0;
    }
    for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][g[a][0]++] = b;
        g[b][g[b][0]++] = a;
    }
    int ans = 0;  // Initialize the answer variable
    for (int i = 1; i <= n; i++) {  // Traverse each node in the graph
        if (!seen[i]) {  // If the node is not seen, perform DFS
            int nodes, edges = dfs(g, seen, i);  // Get the count of nodes and edges
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {  // Check the conditions
                ans += 1;  // Increment the answer if the conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {  // Check if the number of disconnected components is odd
        ans += 1;  // Increment the answer if necessary
    }
    printf("%d\n", ans);  // Print the final answer
    return 1;  // Return True to continue the loop
}

int main() {
    while (solve()) {  // Continuously call solve until it returns False
        ;
    }
    return 0;
}

