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

var G [MAX][MAX]int // 2D array to represent the graph
var n int          // Number of vertices in the graph

// Prim's algorithm to find the Minimum Spanning Tree (MST)
func prim() {
	var i, j int
	var d [MAX]int    // Array to store the minimum distance from the tree to each vertex
	var pi [MAX]int   // Array to store the parent of each vertex in the MST
	var color [MAX]int // Array to keep track of the color of each vertex (WHITE, GRAY, BLACK)
	var min, u, v, sum int // Variables to find the minimum distance vertex and to store the sum of MST weights

	// Initialize all distances to infinity, parents to NIL, and colors to WHITE
	for i = 0; i < n; i++ {
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	// Distance of the first vertex is set to 0
	d[0] = 0

	// Continue until all vertices are processed
	for {
		min = INF
		u = NIL
		// Find the vertex with the minimum distance that is not BLACK
		for i = 0; i < n; i++ {
			if color[i] != BLACK && d[i] < min {
				min = d[i]
				u = i
			}
		}
		// If no such vertex is found, break the loop
		if u == NIL {
			break
		}
		// Mark the selected vertex as BLACK
		color[u] = BLACK
		// Update the distances and parents of adjacent vertices
		for v = 0; v < n; v++ {
			if color[v] != BLACK && G[u][v] != INF {
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = GRAY
				}
			}
		}
	}
	// Calculate the sum of the weights of the edges in the MST
	for i = 0; i < n; i++ {
		if pi[i] != NIL {
			sum += G[i][pi[i]]
		}
	}
	// Print the sum of the weights of the MST
	fmt.Println(sum)
}

// Main function to read the graph and call Prim's algorithm
func main() {
	var e int

	fmt.Scan(&n) // Read the number of vertices

	// Read the adjacency matrix of the graph
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Scan(&e)
			if e == -1 {
				G[i][j] = INF // If no edge, set weight to INF
			} else {
				G[i][j] = e // Otherwise, set the weight of the edge
			}
		}
	}

	prim() // Call Prim's algorithm to find and print the sum of the MST
}

// <END-OF-CODE>
