
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Adjacency list to represent the graph
int **g;
int n;

// Function to calculate the maximum matching in the graph
int max_matching(int v, int p) {
    int a = 0; // Count of pairs in matching
    int o = 0; // Count of unmatched vertices
    
    // Iterate through all adjacent vertices of v
    for (int i = 0; i < g[v][0]; i++) {
        int w = g[v][i + 1];
        
        // Skip the parent vertex to avoid cycles
        if (w == p) continue; 
        
        // Recursively find the matching for the adjacent vertex
        int r = max_matching(w, v); 
        a += r / 2; // Update count of pairs
        o += r % 2; // Update count of unmatched vertices
    }
    
    // Return the total matching count
    return 2 * a + (o < 2? o : 2);
}

int main() {
    // Initialize scanner for input
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    
    // Initialize the adjacency list for the graph
    g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g[i] = (int *)malloc(sizeof(int));
        g[i][0] = 0;
    }
    
    // Read edges and populate the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        fscanf(fp, "%d %d", &a, &b);
        a--;
        b--;
        g[a][0]++;
        g[b][0]++;
        int *temp = (int *)malloc((g[a][0] + 1) * sizeof(int));
        memcpy(temp, g[a], g[a][0] * sizeof(int));
        temp[g[a][0]] = b;
        free(g[a]);
        g[a] = temp;
        temp = (int *)malloc((g[b][0] + 1) * sizeof(int));
        memcpy(temp, g[b], g[b][0] * sizeof(int));
        temp[g[b][0]] = a;
        free(g[b]);
        g[b] = temp;
    }
    
    // Calculate maximum matching starting from vertex 0
    int m = max_matching(0, -1) / 2; 
    
    // Determine the winner based on the matching result
    if (2 * m == n) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
    
    // Close the input file
    fclose(fp);
    
    return 0;
}

