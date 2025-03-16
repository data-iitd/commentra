
#include <stdio.h>
#include <stdbool.h>

// Define a 2D array 'e' to store the edges of the graph
int e[101][101];

// Define variables 'n' and'm' to store the number of nodes and edges respectively
int n, m;

// Function 'printEdge' to print the edges of the graph
void printEdge() {
    // Iterate through each node in the graph
    for (int i = 1; i <= n; i++) {
        // Print the node number and its connected nodes
        printf("%d: ", i);
        for (int j = 1; j <= n; j++) {
            if (e[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function 'dfs' to perform Depth First Search traversal
int dfs(int v, bool visited[]) {
    // Initialize a boolean array 'visited' to keep track of visited nodes
    // visited[v] = true
    // printf("%d %d\n", v, visited[v]);

    // Check if all nodes are visited, if yes then it's a strongly connected component
    bool comp = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp = false;
            break;
        }
    }

    // If all nodes are visited, return 1 for this strongly connected component
    if (comp) {
        return 1;
    }

    // Initialize a counter 'count' to store the size of the strongly connected component
    int count = 0;
    // Iterate through the neighbors of the current node 'v'
    for (int j = 1; j <= n; j++) {
        // If the neighbor is already visited, skip it
        if (visited[j]) {
            continue;
        }
        // Mark the neighbor as visited
        visited[j] = true;
        // Recursively call 'dfs' on the neighbor and add its size to the counter
        // int rst = dfs(j, visited, count);
        // count += rst;
        int rst = dfs(j, visited);
        count += rst;
        // Mark the neighbor as unvisited
        visited[j] = false;
    }
    // Return the size of the strongly connected component
    return count;
}

// Function'main' to read input and call the 'printEdge' and 'dfs' functions
int main() {
    // Read the number of nodes and edges from the standard input
    scanf("%d %d", &n, &m);

    // Initialize a 2D array 'e' of size (n+1)x(n+1) to store the edges of the graph
    for (int i = 1; i <= n; i++) {
        // Initialize an empty array for each node
        for (int j = 1; j <= n; j++) {
            e[i][j] = 0;
        }
    }
    // Read the edges of the graph from the standard input and add them to the 'e' array
    for (int i = 0; i < m; i++) {
        int a, b;
        // Read the nodes of an edge from the standard input
        scanf("%d %d", &a, &b);
        // Add the edge to the 'e' array for both nodes
        e[a][b] = 1;
        e[b][a] = 1;
    }
    // Call the 'printEdge' function to print the edges of the graph
    // printEdge();

    // Initialize a boolean array 'visited' of size (n+1) to keep track of visited nodes
    bool visited[101];
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    // Mark the first node as visited
    visited[1] = true;
    // Call the 'dfs' function on the first node and print the size of the strongly connected component
    int count = dfs(1, visited);
    printf("%d\n", count);
}
