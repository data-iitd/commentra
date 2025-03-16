#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MOD 1000000007
#define INF 1e9

int n, ta, ao;
int g[MAX_N][MAX_N]; // Adjacency list representation
int ta_dist[MAX_N];
int ao_dist[MAX_N];
int visited[MAX_N];

void ta_dfs(int node) {
    for (int v = 0; v < n; v++) {
        if (g[node][v] && ta_dist[v] == -1) { // Check if there's an edge and not visited
            ta_dist[v] = ta_dist[node] + 1; // Update distance
            ta_dfs(v); // Recursive DFS call
        }
    }
}

void ao_dfs(int node) {
    for (int v = 0; v < n; v++) {
        if (g[node][v] && ao_dist[v] == -1) { // Check if there's an edge and not visited
            ao_dist[v] = ao_dist[node] + 1; // Update distance
            ao_dfs(v); // Recursive DFS call
        }
    }
}

int main() {
    // Set the recursion limit to a high value to handle deep recursions
    // Note: C does not have a recursion limit like Python, but stack size can be adjusted if needed.

    // Read the number of nodes and the starting points for ta and ao
    scanf("%d %d %d", &n, &ta, &ao);
    ta--; // Adjusting to zero-based index
    ao--; // Adjusting to zero-based index

    // Initialize the graph as an adjacency list
    memset(g, 0, sizeof(g));
    
    // Read the edges of the graph and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Adjusting to zero-based index
        b--; // Adjusting to zero-based index
        g[a][b] = 1; // Mark the edge
        g[b][a] = 1; // Mark the edge
    }

    // Initialize distance arrays for ta and ao
    memset(ta_dist, -1, sizeof(ta_dist));
    memset(ao_dist, -1, sizeof(ao_dist));
    ta_dist[ta] = 0; // Distance to itself is 0
    ao_dist[ao] = 0; // Distance to itself is 0

    // Perform DFS from ao to calculate distances
    ao_dfs(ao);

    // Perform DFS from ta to calculate distances
    ta_dfs(ta);

    // Initialize result variable to track the maximum distance
    int res = 0;

    // Calculate the maximum distance where ta's distance is less than or equal to ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) {
            continue; // Skip if ta is further away than ao
        }
        res = (res > ao_dist[i]) ? res : ao_dist[i]; // Update result with the maximum distance
    }

    // Print the result, subtracting 1 to adjust for zero-based indexing
    printf("%d\n", res - 1);

    return 0;
}

// <END-OF-CODE>
