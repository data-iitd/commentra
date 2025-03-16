
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function prototype for Prim's algorithm
func prim() int {
	// Read the number of vertices in the graph
	n, _ := strconv.Atoi(scanner.Text())

	// Read the adjacency matrix representation of the graph
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			G[i][j], _ = strconv.Atoi(scanner.Text())
		}
	}

	// Call Prim's algorithm and print the total weight of the minimum spanning tree
	fmt.Println(prim(G))

	return 0
}

func prim(G [][]int) int {
	n := len(G)

	// Initialize arrays for distance, parent, and color of each vertex
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)

	// Start with the first vertex
	d[0] = 0

	// Main loop to find the minimum spanning tree
	for {
		mincost := 9999999 // Set initial costs to a large value
		u := 0            // Initialize the vertex to be included in the MST

		// Find the vertex with the minimum cost edge that is not yet included in the MST
		for i := 0; i < n; i++ {
			if color[i]!= 2 && d[i] < mincost {
				mincost = d[i]
				u = i // Update the vertex to be included in the MST
			}
		}

		// If no vertex is found, break the loop
		if mincost == 9999999 {
			break
		}

		// Mark the selected vertex as BLACK (included in the MST)
		color[u] = 2

		// Update the distances and parents for the adjacent vertices
		for v := 0; v < n; v++ {
			// If the vertex is not yet included in the MST and the edge weight is less than the current known distance
			if color[v]!= 2 && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = u    // Update the parent of vertex v
				d[v] = G[u][v] // Update the distance to vertex v
			}
		}
	}

	// Calculate the total weight of the minimum spanning tree
	sum := 0
	for i := 0; i < n; i++ {
		if d[i]!= 9999999 {
			sum += d[i] // Sum up the distances of included vertices
		}
	}

	// Return the total weight of the minimum spanning tree
	return sum
}

func main() {
	// Initialize the scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Call the prim function and end with comment "