#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100010

// Structure to represent an edge in the graph
struct edge {
    int to, pre, c; // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
} e[N << 1]; 

// Array to store the head of each vertex's adjacency list
int u[N], l = 0;

// Function to insert an edge into the graph
void ins(int a, int b, int c) { 
    e[++l] = (struct edge){b, u[a], c}; // Create a new edge
    u[a] = l; // Update the head of the adjacency list for vertex 'a'
}

// Macros for accessing edge properties
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

// Global variables
int n, m; // Number of vertices and edges
bool vis[N], ok; // vis[i] indicates if vertex i has been visited, ok indicates if the graph is valid
long long cnt[3]; // Count of vertices in each of the three color classes
int d[N]; // Array to store the color of each vertex
int T; // Total number of vertices in the current connected component

// Depth-first search function to traverse the graph
void dfs(int x, int l) {
    vis[x] = true; // Mark the current vertex as visited
    cnt[l]++; // Increment the count for the current color class
    d[x] = l; // Assign the color to the current vertex

    // Iterate through all edges of the current vertex
    reg(i,x) {
        T++; // Increment the total count of vertices in the component
        if (!vis[v]) // If the adjacent vertex has not been visited
            dfs(v, (l + ec) % 3); // Recursively visit it with the new color
        else if ((l + ec) % 3 != d[v]) // If the adjacent vertex is visited but has a different color
            ok = false; // Mark the component as invalid
    }
}

int main() {
    // Read the number of vertices and edges
    scanf("%d%d", &n, &m);
    
    // Read edges and construct the graph
    for(int i = 1; i <= m; i++) {
        int a, b; 
        scanf("%d%d", &a, &b); // Read each edge
        ins(a, b, 1); // Insert edge from a to b with color 1
        ins(b, a, 2); // Insert edge from b to a with color 2
    }

    long long ans = 0; // Variable to store the final answer

    // Iterate through all vertices
    for(int i = 1; i <= n; i++) 
        if (!vis[i]) { // If the vertex has not been visited
            T = 0; // Reset the total count for the new component
            for(int j = 0; j < 3; j++) cnt[j] = 0; // Reset color counts
            ok = true; // Assume the component is valid
            dfs(i, 0); // Start DFS from the current vertex with color 0
            
            // Calculate the size of the current component
            long long s = cnt[0] + cnt[1] + cnt[2];
            
            // If the component is invalid, add the square of its size to the answer
            if (!ok) 
                ans += s * s;
            else {
                // If all three color classes are present, calculate combinations
                if (cnt[0] && cnt[1] && cnt[2]) 
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                else 
                    ans += T / 2; // If not all color classes are present, add half of the total vertices
            }
        }
    
    // Output the final answer
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
