
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define the main function to execute the program.

func main() {
	// Read the input from the standard input.

	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	// Read the number of vertices from the input.

	G := make([][]int, n)
	// Create a 2D array to represent the graph.

	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		// Initialize the adjacency matrix with zeros.

		for j := 0; j < n; j++ {
			G[i][j], _ = strconv.Atoi(reader.ReadLine()[0:1])
		}
	}

	fmt.Println(prim(n, G))
	// Call the prim function and print the result.
}

// Define the prim function to implement Prim's algorithm for finding the Minimum Spanning Tree.

func prim(n int, G [][]int) int {
	u, i, v, mincost, d, pi, color, sum := 0, 0, 0, 0, make([]int, n), make([]int, n), make([]int, n), 0

	for u = 0; u < n; u++ {
		d[u] = 9999999
		pi[u] = -1
		color[u] = 0
	}

	// Initialize all distances to infinity, predecessors to nil, and colors to white.

	d[0] = 0
	// Set the distance of the first vertex to 0.

	for {
		mincost = 9999999

		// Initialize mincost to infinity.

		for i = 0; i < n; i++ {
			if color[i]!= 2 && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		// Find the vertex with the smallest distance that is not yet black.

		if mincost == 9999999 {
			break
		}

		// If no more vertices can be reached, break the loop.

		color[u] = 2
		// Mark the current vertex as black.

		for v = 0; v < n; v++ {
			if color[v]!= 2 && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}

		// Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight.
	}

	for i = 0; i < n; i++ {
		if d[i]!= 9999999 {
			sum += d[i]
		}
	}

	// Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices.

	return sum
}

// Translate the above C code to Go and end with comment "