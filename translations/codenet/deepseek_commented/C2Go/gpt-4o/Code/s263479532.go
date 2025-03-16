package main

import (
	"fmt"
	"math"
)

const (
	MAX = 100
	INF = math.MaxInt32
	NIL = -1
	WHITE = 0
	BLACK = 2
)

var n int
var G [MAX][MAX]int

// prim implements Prim's algorithm for finding the Minimum Spanning Tree.
func prim() int {
	var u, i, v, mincost, sum int
	var d [MAX]int
	var pi [MAX]int
	var color [MAX]int

	// Initialize all distances to infinity, predecessors to nil, and colors to white.
	for u = 0; u < n; u++ {
		d[u] = INF
		pi[u] = NIL
		color[u] = WHITE
	}

	d[0] = 0 // Set the distance of the first vertex to 0.

	for {
		mincost = INF

		// Find the vertex with the smallest distance that is not yet black.
		for i = 0; i < n; i++ {
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == INF {
			break // If no more vertices can be reached, break the loop.
		}

		color[u] = BLACK // Mark the current vertex as black.

		// Update the distances and predecessors for the neighboring vertices.
		for v = 0; v < n; v++ {
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	// Calculate the total cost of the Minimum Spanning Tree.
	for i = 0; i < n; i++ {
		if d[i] != INF {
			sum += d[i]
		}
	}

	return sum
}

func main() {
	var i, j int

	fmt.Scan(&n) // Read the number of vertices from the input.

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scan(&G[i][j]) // Read the adjacency matrix.
		}
	}

	fmt.Println(prim()) // Call the prim function and print the result.
}

// <END-OF-CODE>
