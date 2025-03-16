package main

import (
	"fmt"
)

const (
	INF  = 100000
	MAX  = 101
	NIL  = -6
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

var G [MAX][MAX]int
var n int

// Function to perform Prim's Algorithm
func prim() {
	var i, j int
	var d [MAX]int
	var pi [MAX]int
	var color [MAX]int
	var min, u, v, sum int

	// Initialize all vertices with INF distance, NIL previous vertex, and WHITE color
	for i = 0; i < n; i++ {
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	// Set the distance of the source vertex to 0
	d[0] = 0

	// While there are still unvisited vertices
	for {
		min = INF
		u = NIL // Initialize min and u to uninitialized values
		for i = 0; i < n; i++ {
			// Find the unvisited vertex with the minimum distance
			if color[i] != BLACK && d[i] < min {
				min = d[i]
				u = i
			}
		}
		// If all vertices have been visited, break the loop
		if u == NIL {
			break
		}
		// Mark the current vertex as visited (Black color)
		color[u] = BLACK
		// Update the distances of all adjacent vertices
		for v = 0; v < n; v++ {
			if color[v] != BLACK && G[u][v] != INF {
				// If the distance through the current vertex is shorter than the current distance, update it
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = GRAY
				}
			}
		}
	}
	// Calculate and print the total weight of the minimum spanning tree
	for i = 0; i < n; i++ {
		if pi[i] != NIL {
			sum += G[i][pi[i]]
		}
	}
	fmt.Println(sum)
}

func main() {
	var e, i, j int // Loop variables and input variable

	// Read the number of vertices from the standard input
	fmt.Scan(&n)

	// Initialize the adjacency matrix with INF for unconnected vertices and input edges with their weights
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scan(&e)
			if e == -1 {
				G[i][j] = INF
			} else {
				G[i][j] = e
			}
		}
	}

	// Call the Prim's Algorithm function to find the minimum spanning tree
	prim()
	// Return 0 to indicate successful execution
}

