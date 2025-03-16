#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))

// Structure to hold edge information
class E {
    int s, g, c; // start vertex, end vertex, and cost of the edge
    public E(int s, int g, int c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

// Structure to represent the graph
class G {
    int vcnt, ecnt; // number of vertices and edges
    E[] e;    // array to hold edges
    int[] id; // array to hold index of edges for each vertex
    public G(int vcnt, int ecnt) {
        this.vcnt = vcnt;
        this.ecnt = ecnt;
        this.e = new E[200010];
        this.id = new int[100010];
    }
}

int esort(E a, E b) {
    // Sort edges primarily by start vertex, then by end vertex
    if (a.s < b.s) return -1;
    if (a.s > b.s) return 1;
    if (a.g < b.g) return -1;
    return 1;
}

G g; // Global graph variable

// Function to read the graph from input
void readgraph() {
    int n;
    // Read the number of vertices
    scanf("%d", &n);
    // Read edges and construct the graph
    rep(i, 0, n - 1) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        // Add edge from x to y
        g.e[2 * i] = new E(x, y, c);
        // Add edge from y to x (undirected graph)
        g.e[2 * i + 1] = new E(y, x, c);
    }
    g.vcnt = n; // Set vertex count
    g.ecnt = 2 * n - 2; // Set edge count (undirected edges)
    // Sort edges based on start and end vertices
    Arrays.sort(g.e, 0, g.ecnt, (a, b) -> esort(a, b));

    int p = 0;
    // Create an index for edges for each vertex
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p; // Store the index of the first edge for vertex i
    }
    g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex
}

// Function to perform DFS and find the diameter of the tree
int[] tyokkeitemp; // Temporary array to store distances during DFS

// Recursive DFS function to explore the tree
void tyokkeidfs(int s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        // If the vertex has not been visited
        if (tyokkeitemp[g.e[i].g] == 0) {
            // Update the distance and continue DFS
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g.e[i].g);
        }
    }
}

// Function to calculate the diameter of the tree
int tyokkei() {
    // Allocate memory for distance array
    tyokkeitemp = new int[g.vcnt + 10];
    tyokkeitemp[0] = 1; // Start DFS from vertex 0
    tyokkeidfs(0); // First DFS to find the farthest vertex

    int M = 0, Mi; // Variables to track maximum distance and corresponding vertex
    rep(i, 0, g.vcnt) {
        // Find the vertex with the maximum distance
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }
    
    // Reset distances for the second DFS
    rep(i, 0, g.vcnt) tyokkeitemp[i] = 0;
    tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
    tyokkeidfs(Mi); // Second DFS to find the diameter

    // Find the maximum distance from the second DFS
    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i]);
    return M - 1; // Return the diameter (subtract 1 for edge count)
}

public class Main {
    public static void main(String[] args) {
        readgraph(); // Read the graph input
        System.out.println(tyokkei()); // Calculate and print the diameter of the tree
    }
}

