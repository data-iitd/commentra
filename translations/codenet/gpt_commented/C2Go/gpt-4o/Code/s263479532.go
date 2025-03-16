package main

import (
	"fmt"
	"math"
)

const (
	MAX  = 100
	INF  = 999999
	NIL  = -1
	WHITE = 0
	BLACK = 2
)

var n int
var G [MAX][MAX]int

// Function prototype for Prim's algorithm
func prim() int {
	var u, i, v, mincost, sum int
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)

	// Initialize arrays for distance, parent, and color of each vertex
	for u = 0; u < n; u++ {
		d[u] = INF      // Set initial distances to infinity
		pi[u] = NIL     // Set initial parents to NIL
		color[u] = WHITE // Set initial colors to WHITE (unvisited)
	}

	// Start with the first vertex
	d[0] = 0

	// Main loop to find the minimum spanning tree
	for {
		mincost = INF

		// Find the vertex with the minimum cost edge that is not yet included in the MST
		for i = 0; i < n; i++ {
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i // Update the vertex to be included in the MST
			}
		}

		// If no vertex is found, break the loop
		if mincost == INF {
			break
		}

		// Mark the selected vertex as BLACK (included in the MST)
		color[u] = BLACK

		// Update the distances and parents for the adjacent vertices
		for v = 0; v < n; v++ {
			// If the vertex is not yet included in the MST and the edge weight is less than the current known distance
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u    // Update the parent of vertex v
				d[v] = G[u][v] // Update the distance to vertex v
			}
		}
	}

	// Calculate the total weight of the minimum spanning tree
	for i = 0; i < n; i++ {
		if d[i] != INF {
			sum += d[i] // Sum up the distances of included vertices
		}
	}

	// Return the total weight of the minimum spanning tree
	return sum
}

func main() {
	var i, j int

	// Read the number of vertices in the graph
	fmt.Scan(&n)

	// Read the adjacency matrix representation of the graph
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	// Call Prim's algorithm and print the total weight of the minimum spanning tree
	fmt.Println(prim())
}

// <END-OF-CODE>
