#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

// Set the maximum recursion limit to handle deep recursions
#define MAX_RECURSION_DEPTH 1000000

// Global variables
int n, k, links[MAX_N];

// Function to perform DFS and get the total cuts
int dfs(int v, int p) {
    // Initialize height from the leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;
    
    // Iterate through all connected nodes (children) of the current node
    for (int u = links[v]; u!= 0; u = links[u]) {
        // Recursively perform DFS on the child node and get its height and cut count
        int hgt, cut = dfs(u, v);
        
        // Update the maximum height from the leaf node
        height_from_leaf = (height_from_leaf > hgt)? height_from_leaf : hgt;
        
        // Accumulate the cut count from the child nodes
        cut_count += cut;
    }
    
    // Increment the height from the leaf node as we return to the parent
    height_from_leaf++;
    
    // Check if the current height matches k and we are not at the root node
    if (p!= 0 && height_from_leaf == k) {
        // Reset height from leaf to 0 and increment cut count
        height_from_leaf = 0;
        cut_count++;
    }
    
    // Return the height from the leaf and the total cut count
    return height_from_leaf;
}

int main() {
    // Read input values for n (number of nodes), k (target height), and the rest of the connections
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        links[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        links[a - 1] = b - 1;
    }
    
    // Perform DFS starting from the root node (0) and get the total cuts
    int ans = dfs(0, 0);
    
    // If the first node is not the root, increment the answer
    if (links[0]!= 1) {
        ans++;
    }
    
    // Print the final answer (total cuts)
    printf("%d\n", ans);
    
    return 0;
}

