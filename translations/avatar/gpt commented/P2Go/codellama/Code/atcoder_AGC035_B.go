package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of nodes (N) and edges (M) from input
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize adjacency list for edges, degree count, parity, and visited flag
	edges := make([][]int, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)

	// Read edges and populate the adjacency list and degree counts
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		edges[a-1] = append(edges[a-1], b-1) // Add edge from a to b
		edges[b-1] = append(edges[b-1], a-1) // Add edge from b to a
		degs[a-1]++                          // Increment degree of node a
		degs[b-1]++                          // Increment degree of node b
	}

	// If the number of edges is odd, it's impossible to pair them
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize a priority queue with degrees of nodes
	Q := make([]int, N)
	for i, d := range degs {
		Q[i] = d
	}
	sort.Ints(Q) // Transform the list into a heap

	// Process the nodes in the priority queue
	for len(Q) > 0 {
		u := Q[0] // Get the node with the smallest degree
		Q = Q[1:] // Remove it from the queue

		// If the node has already been processed, skip it
		if flag[u] {
			continue
		}

		flag[u] = true // Mark the node as processed

		// Iterate through the neighbors of the current node
		for i, v := range edges[u] {
			edges[v] = append(edges[v][:i], edges[v][i+1:]...) // Remove the edge from v to u
			// Check the parity to determine the output format
			if parity[u] != 0 && i == 0 {
				fmt.Println(u+1, v+1) // Print the edge in one format
				parity[u] = 1 - parity[u] // Toggle parity for u
			} else {
				fmt.Println(v+1, u+1) // Print the edge in the alternate format
				parity[v] = 1 - parity[v] // Toggle parity for v
			}

			degs[v]-- // Decrement the degree of neighbor v
			Q = append(Q, degs[v]) // Push updated degree back to the queue
		}
	}
}

