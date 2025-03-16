package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int64 // start vertex, end vertex, and cost of the edge
}

type Graph struct {
	vcnt, ecnt int // number of vertices and edges
	e          []Edge // array to hold edges
	id         []int  // array to hold index of edges for each vertex
}

var g Graph // Global graph variable

// Function to read the graph from input
func readGraph() {
	var n int64
	// Read the number of vertices
	fmt.Scan(&n)
	// Initialize edges and id slices
	g.e = make([]Edge, 2*n-2)
	g.id = make([]int, n+1)

	// Read edges and construct the graph
	for i := int64(0); i < n-1; i++ {
		var x, y, c int64
		fmt.Scan(&x, &y, &c)
		// Add edge from x to y
		g.e[2*i] = Edge{s: x, g: y, c: c}
		// Add edge from y to x (undirected graph)
		g.e[2*i+1] = Edge{s: y, g: x, c: c}
	}
	g.vcnt = int(n) // Set vertex count
	g.ecnt = 2*int(n) - 2 // Set edge count (undirected edges)

	// Sort edges based on start and end vertices
	sort.Slice(g.e, func(i, j int) bool {
		if g.e[i].s != g.e[j].s {
			return g.e[i].s < g.e[j].s
		}
		return g.e[i].g < g.e[j].g
	})

	p := 0
	// Create an index for edges for each vertex
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < int64(i) {
			p++
		}
		g.id[i] = p // Store the index of the first edge for vertex i
	}
	g.id[g.vcnt] = g.ecnt // Sentinel value for the last vertex
}

// Function to perform DFS and find the diameter of the tree
var tyokkeitemp []int // Temporary array to store distances during DFS

// Recursive DFS function to explore the tree
func tyokkeidfs(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		// If the vertex has not been visited
		if tyokkeitemp[g.e[i].g] == 0 {
			// Update the distance and continue DFS
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + int(g.e[i].c)
			tyokkeidfs(int(g.e[i].g))
		}
	}
}

// Function to calculate the diameter of the tree
func tyokkei() int {
	// Allocate memory for distance array
	tyokkeitemp = make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1 // Start DFS from vertex 0
	tyokkeidfs(0) // First DFS to find the farthest vertex

	M, Mi := 0, 0 // Variables to track maximum distance and corresponding vertex
	for i := 0; i < g.vcnt; i++ {
		// Find the vertex with the maximum distance
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}

	// Reset distances for the second DFS
	for i := 0; i < g.vcnt; i++ {
		tyokkeitemp[i] = 0
	}
	tyokkeitemp[Mi] = 1 // Start DFS from the farthest vertex found
	tyokkeidfs(Mi) // Second DFS to find the diameter

	// Find the maximum distance from the second DFS
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
		}
	}
	return M - 1 // Return the diameter (subtract 1 for edge count)
}

func main() {
	readGraph() // Read the graph input
	fmt.Println(tyokkei()) // Calculate and print the diameter of the tree
}

// <END-OF-CODE>
