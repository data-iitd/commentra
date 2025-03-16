package main

import (
	"bufio"
	"fmt"
	"os"
)

const INF = 1e18

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input values for N and M
	var N, M int
	fmt.Fscan(reader, &N, &M)

	// Initialize an empty slice for edges
	edges := make([][]int, N)

	// Read edges and add them to the edge list
	for i := 0; i < M; i++ {
		var X, Y int
		fmt.Fscan(reader, &X, &Y)
		X-- // Convert to 0-based index
		Y-- // Convert to 0-based index
		edges[X] = append(edges[X], Y)
		edges[Y] = append(edges[Y], X)
	}

	// Initialize a slice of boolean values for used nodes
	used := make([]bool, N)

	// Initialize a variable for answer
	ans := 0

	// Iterate through all nodes
	for i := 0; i < N; i++ {
		// If the current node is not used
		if !used[i] {
			// Increment the answer
			ans++
			// Initialize a queue for DFS traversal
			queue := []int{i}
			// Traverse through the graph using DFS
			for len(queue) > 0 {
				// Get the next node from the queue
				node := queue[0]
				queue = queue[1:] // Dequeue the first element
				// Mark the current node as used
				used[node] = true
				// Traverse through the neighbors of the current node
				for _, nextNode := range edges[node] {
					// If the neighbor is not used
					if !used[nextNode] {
						// Add the neighbor to the queue
						queue = append(queue, nextNode)
					}
				}
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
