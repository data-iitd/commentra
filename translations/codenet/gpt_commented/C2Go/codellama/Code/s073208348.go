#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))

// Structure to hold edge information
type E struct {
    s, g, c int // start vertex, end vertex, and cost of the edge
}

// Structure to represent the graph
type G struct {
    vcnt, ecnt int // number of vertices and edges
    e []E // array to hold edges
    id []int // array to hold index of edges for each vertex
}

func esort(a, b interface{}) int {
    p, q := a.(*E), b.(*E)
    // Sort edges primarily by start vertex, then by end vertex
    if p.s < q.s { return -1 }
    if p.s > q.s { return 1 }
    if p.g < q.g { return -1 }
    return 1
}

var g G // Global graph variable

// Function to read the graph from input
func readgraph() {
    var n int
    // Read the number of vertices
    fmt.Scanf("%d", &n)
    // Read edges and construct the graph
    rep(i, 0, n - 1) {
        var x, y, c int
        fmt.Scanf("%d%d%d", &x, &y, &c)
        // Add edge from x to y
        g.e[2 * i].s = x
        g.e[2 * i].g = y
        g.e[2 * i].c = c
        // Add edge from y to x (undirected graph)
        g.e[2 * i + 1].s = y
        g.e[2 * i + 1].g = x
        g.e[2 * i + 1].c = c
    }
    g.vcnt = n
    g.ecnt = 2 * n - 2
    // Sort edges based on start and end vertices
    sort.Slice(g.e, func(i, j int) bool { return esort(&g.e[i], &g.e[j]) < 0 })

    p := 0
    // Create an index for edges for each vertex
    rep(i, 0, g.vcnt) {
        for p < g.ecnt && g.e[p].s < i { p++ }
        g.id[i] = p
    }
    g.id[g.vcnt] = g.ecnt
}

// Function to perform DFS and find the diameter of the tree
var tyokkeitemp []int // Temporary array to store distances during DFS

// Recursive DFS function to explore the tree
func tyokkeidfs(s int) {
    for i := g.id[s]; i < g.id[s + 1]; i++ {
        // If the vertex has not been visited
        if tyokkeitemp[g.e[i].g] == 0 {
            // Update the distance and continue DFS
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
            tyokkeidfs(g.e[i].g)
        }
    }
}

// Function to calculate the diameter of the tree
func tyokkei() int {
    // Allocate memory for distance array
    tyokkeitemp = make([]int, g.vcnt + 10)
    tyokkeitemp[0] = 1 // Start DFS from vertex 0
    tyokkeidfs(0) // First DFS to find the farthest vertex

    M, Mi := 0, 0 // Variables to track maximum distance and corresponding vertex
    rep(i, 0, g.vcnt) {
        // Find the vertex with the maximum distance
        if tyokkeitemp[i] > M {
            M = tyokkeitemp[i]
            Mi = i
        }
    }
    
    // Reset distances for the second DFS
    rep(i, 0, g.vcnt) tyokkeitemp[i] = 0
    tyokkeitemp[Mi] = 1 // Start DFS from the farthest vertex found
    tyokkeidfs(Mi) // Second DFS to find the diameter

    // Find the maximum distance from the second DFS
    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i])
    return M - 1 // Return the diameter (subtract 1 for edge count)
}

func main() {
    readgraph() // Read the graph input
    fmt.Println(tyokkei()) // Calculate and print the diameter of the tree
}

