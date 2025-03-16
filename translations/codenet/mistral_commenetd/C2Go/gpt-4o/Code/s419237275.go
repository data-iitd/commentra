package main

import (
	"fmt"
)

const N = 200
const (
	SHIRO = iota // 0
	HAI          // 1
	KURO         // 2
)

var (
	n     int
	A     [N][N]int
	color [N]int
	d     [N]int
	f     [N]int
	TT    int
)

func main() {
	var k, v int

	fmt.Print("Enter the number of nodes: ")
	fmt.Scan(&n) // Read the number of nodes from the user

	// Initialize the 2D array A with zeros
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the adjacency matrix from the user
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the number of neighbors for node %d: ", i+1)
		fmt.Scan(&k)
		for j := 0; j < k; j++ {
			fmt.Print("Enter the neighbor index: ")
			fmt.Scan(&v)
			A[i][v-1] = 1 // Store the edge weight (assumed to be 1) in the adjacency matrix
		}
	}

	aaaaa() // Call the function aaaaa() to perform the required computation
}

func aaaaa() {
	var u int

	// Initialize all nodes with color SHIRO (white)
	for i := 0; i < n; i++ {
		color[i] = SHIRO
	}

	TT = 0 // Initialize the time variable TT to 0

	// Perform Depth First Search (DFS) from each unvisited node
	for u = 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbb(u)
		}
	}

	// Print the results
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
		fmt.Printf("Node %d is visited at time %d and its finishing time is %d.\n", i+1, d[i], f[i])
	}
}

func bbbbb(k int) {
	var v int
	color[k] = HAI // Mark the current node as visited (gray)
	TT++          // Increment the time variable TT
	d[k] = TT     // Set the discovery time for the current node

	// Explore all neighbors of the current node
	for v = 0; v < n; v++ {
		if A[k][v] == 1 && color[v] == SHIRO { // If the neighbor is unvisited
			bbbbb(v) // Recursively call the function bbbbb() for the neighbor
		}
	}

	// Mark the current node as finished (black)
	color[k] = KURO
	f[k] = TT + 1 // Set the finishing time for the current node
	TT++          // Increment the time variable TT
}

// <END-OF-CODE>
