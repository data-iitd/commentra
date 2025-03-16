package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int64 // Define the structure for edges
}

type Graph struct {
	vcnt, ecnt int
	e          []Edge // Define the slice of edges
	id         []int   // Define the slice of indices
}

var g Graph // Define a global graph variable

func readGraph() { // Define a function to read the graph
	var n int64
	fmt.Scan(&n) // Read the number of vertices
	g.e = make([]Edge, 2*n-2) // Initialize the edges slice
	g.id = make([]int, n+1) // Initialize the id slice

	for i := int64(0); i < n-1; i++ { // Read each edge and store it in the graph structure
		var x, y, c int64
		fmt.Scan(&x, &y, &c)
		g.e[2*i] = Edge{s: x, g: y, c: c}
		g.e[2*i+1] = Edge{s: y, g: x, c: c}
	}
	g.vcnt = int(n) // Set the number of vertices
	g.ecnt = 2*int(n) - 2 // Set the number of edges

	sort.Slice(g.e, func(i, j int) bool { // Sort the edges
		if g.e[i].s != g.e[j].s {
			return g.e[i].s < g.e[j].s
		}
		return g.e[i].g < g.e[j].g
	})

	p := 0
	for i := 0; i < g.vcnt; i++ { // Populate the id array with the starting index of edges for each vertex
		for p < g.ecnt && g.e[p].s < int64(i) {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt // Set the sentinel value for the id array
}

var tyokkeitemp []int // Define a temporary slice for DFS

func tyokkeidfs(s int) { // Define a function to perform DFS and update distances
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + int(g.e[i].c)
			tyokkeidfs(int(g.e[i].g))
		}
	}
}

func tyokkei() int { // Define a function to find the diameter of the tree
	tyokkeitemp = make([]int, g.vcnt+10) // Allocate memory for the temporary slice
	tyokkeitemp[0] = 1 // Start DFS from the root
	tyokkeidfs(0) // Perform DFS

	M, Mi := 0, 0 // Initialize variables to find the maximum distance
	for i := 0; i < g.vcnt; i++ { // Find the vertex with the maximum distance from the root
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		tyokkeitemp[i] = 0 // Reset the temporary slice
	}
	tyokkeitemp[Mi] = 1 // Start DFS from the farthest vertex found
	tyokkeidfs(Mi) // Perform DFS
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i] // Find the maximum distance in the second DFS
		}
	}
	return M - 1 // Return the diameter of the tree
}

func main() { // Define the main function
	readGraph() // Read the graph
	fmt.Println(tyokkei()) // Print the diameter of the tree
}

// <END-OF-CODE>
