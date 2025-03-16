
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))

// Structure to hold edge information
typedef struct edge {
    ll s, g, c; // start vertex, end vertex, and cost of the edge
} E;

// Structure to represent the graph
typedef struct graph {
    int vcnt, ecnt; // number of vertices and edges
    E e[200010];    // array to hold edges
    int id[100010]; // array to hold index of edges for each vertex
} G;

int esort(const void *a, const void *b) {
    E *p = (E *)a, *q = (E *)b;
    // Sort edges primarily by start vertex, then by end vertex
    if ((*p).s < (*q).s) return -1;
    if ((*p).s > (*q).s) return 1;
    if ((*p).g < (*q).g) return -1;
    return 1;
}

G g; // Global graph variable

// Function to read the graph from input
def readgraph():
    n = int(input())
    # Read edges and construct the graph
    for i in range(n-1):
        x, y, c = map(int, input().split())
        # Add edge from x to y
        g.e[2*i].s = x
        g.e[2*i].g = y
        g.e[2*i].c = c
        # Add edge from y to x (undirected graph)
        g.e[2*i+1].s = y
        g.e[2*i+1].g = x
        g.e[2*i+1].c = c
    g.vcnt = n # Set vertex count
    g.ecnt = 2*n-2 # Set edge count (undirected edges)
    # Sort edges based on start and end vertices
    qsort(g.e, g.ecnt, sizeof(E), esort)

    p = 0
    # Create an index for edges for each vertex
    for i in range(g.vcnt):
        while p < g.ecnt and g.e[p].s < i: p += 1
        g.id[i] = p # Store the index of the first edge for vertex i
    g.id[g.vcnt] = g.ecnt # Sentinel value for the last vertex

# Function to perform DFS and find the diameter of the tree
tyokkeitemp = None # Temporary array to store distances during DFS

# Recursive DFS function to explore the tree
def tyokkeidfs(s):
    for i in range(g.id[s], g.id[s+1]):
        # If the vertex has not been visited
        if tyokkeitemp[g.e[i].g] == 0:
            # Update the distance and continue DFS
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
            tyokkeidfs(g.e[i].g)

# Function to calculate the diameter of the tree
def tyokkei():
    # Allocate memory for distance array
    tyokkeitemp = [0]*(g.vcnt+10)
    tyokkeitemp[0] = 1 # Start DFS from vertex 0
    tyokkeidfs(0) # First DFS to find the farthest vertex

    M = 0
    Mi = 0
    for i in range(g.vcnt):
        # Find the vertex with the maximum distance
        if tyokkeitemp[i] > M:
            M = tyokkeitemp[i]
            Mi = i
    # Reset distances for the second DFS
    for i in range(g.vcnt): tyokkeitemp[i] = 0
    tyokkeitemp[Mi] = 1 # Start DFS from the farthest vertex found
    tyokkeidfs(Mi) # Second DFS to find the diameter

    # Find the maximum distance from the second DFS
    M = 0
    for i in range(g.vcnt): M = max(M, tyokkeitemp[i])
    return M-1 # Return the diameter (subtract 1 for edge count)

readgraph() # Read the graph input
print(tyokkei()) # Calculate and print the diameter of the tree

