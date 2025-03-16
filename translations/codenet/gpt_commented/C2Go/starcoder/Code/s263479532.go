package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function prototype for Prim's algorithm
func prim(G [][]int) int {
	n := len(G)
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)
	sum := 0

	// Initialize arrays for distance, parent, and color of each vertex
	for i := 0; i < n; i++ {
		d[i] = 999999
		pi[i] = -1
		color[i] = 0
	}

	// Start with the first vertex
	d[0] = 0

	// Main loop to find the minimum spanning tree
	for {
		mincost := 999999
		u := -1

		// Find the vertex with the minimum cost edge that is not yet included in the MST
		for i := 0; i < n; i++ {
			if color[i] == 0 && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		// If no vertex is found, break the loop
		if u == -1 {
			break
		}

		// Mark the selected vertex as BLACK (included in the MST)
		color[u] = 1

		// Update the distances and parents for the adjacent vertices
		for v := 0; v < n; v++ {
			// If the vertex is not yet included in the MST and the edge weight is less than the current known distance
			if color[v] == 0 && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	// Calculate the total weight of the minimum spanning tree
	for i := 0; i < n; i++ {
		if d[i]!= 999999 {
			sum += d[i]
		}
	}

	// Return the total weight of the minimum spanning tree
	return sum
}

func main() {
	// Read the number of vertices in the graph
	n, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))

	// Read the adjacency matrix representation of the graph
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			G[i][j], _ = strconv.Atoi(strings.TrimSpace(os.Args[2+i*n+j]))
		}
	}

	// Call Prim's algorithm and print the total weight of the minimum spanning tree
	fmt.Println(prim(G))
}

