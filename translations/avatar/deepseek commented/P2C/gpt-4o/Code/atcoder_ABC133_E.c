#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    int *neighbors;
    int count;
} Node;

Node *graph;
int N, K;

long long dfs(int fro, int to, int f) {
    long long caseNum = f;  // Initialize the number of valid colorings with the initial number of colors
    int colorNum = (f == K) ? (K - 1) : (K - 2);  // Set the number of available colors for the current node

    for (int i = 0; i < graph[fro].count; i++) {
        int u = graph[fro].neighbors[i];
        if (u == to) {
            continue;  // Skip if the neighbor is the parent node
        }
        long long pat = dfs(u, fro, colorNum);  // Recursively call dfs for the neighbor
        if (pat == 0) {
            return 0;  // If no valid colorings, return 0
        }
        caseNum = (caseNum * pat) % MOD;  // Multiply the current number of valid colorings by the recursive result
        colorNum--;  // Decrease the number of available colors for the next node
    }
    return caseNum;  // Return the number of valid colorings for the current node
}

int main() {
    scanf("%d %d", &N, &K);  // Read the number of nodes and the number of colors

    graph = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        graph[i].neighbors = (int *)malloc((N - 1) * sizeof(int));  // Allocate space for neighbors
        graph[i].count = 0;  // Initialize neighbor count
    }

    // Construct the graph by reading edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;  // Convert to 0-based index
        graph[a].neighbors[graph[a].count++] = b;  // Append the edge to the graph
        graph[b].neighbors[graph[b].count++] = a;  // Append the reverse edge as well
    }

    long long ans = dfs(0, -1, K);  // Call the dfs function starting from the root node with the initial number of colors
    printf("%lld\n", ans);  // Print the final result

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(graph[i].neighbors);
    }
    free(graph);

    return 0;
}

// <END-OF-CODE>
