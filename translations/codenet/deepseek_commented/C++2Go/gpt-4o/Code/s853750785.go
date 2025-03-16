package main

import (
	"fmt"
)

const MOD = 1e9 + 7

// Function to read integers from input
func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a slice of integers from input
func readIntSlice(n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		slice[i] = readInt()
	}
	return slice
}

func main() {
	// Read number of nodes (N) and edges (M)
	N := readInt()
	M := readInt()

	// Read heights of each node
	H := readIntSlice(N)

	// Create adjacency list for the graph
	G := make([][]int, N)
	for i := 0; i < M; i++ {
		u := readInt() - 1 // Convert to 0-based indexing
		v := readInt() - 1 // Convert to 0-based indexing
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ans := 0 // Variable to count the number of nodes that are taller than all their neighbors

	// Iterate through each node to check if it is taller than all its neighbors
	for u := 0; u < N; u++ {
		flag := true // Flag to check if the current node is taller
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false // If any neighbor is taller or equal, set flag to false
				break
			}
		}
		if flag {
			ans++ // If the flag is still true, increment the answer
		}
	}

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
