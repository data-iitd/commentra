// Import necessary packages
package main

import (
	"fmt"
	"os"
)

// Define constant value for INF
const INF = 1000000000

// Define a custom input function
func input() string {
	return os.Stdin.ReadString('\n')
}

// Define the main function
func main() {
	// Read input values for N and M
	N, M := readInt(), readInt()

	// Initialize an empty list for edge
	edge := make([][]int, N)

	// Read edges and add them to the edge list
	for i := 0; i < M; i++ {
		X, Y, Z := readInt(), readInt(), readInt()
		edge[X-1] = append(edge[X-1], Y-1)
		edge[Y-1] = append(edge[Y-1], X-1)
	}

	// Initialize a list of boolean values for used nodes
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
			queue := make([]int, 0)
			// Add the current node to the queue
			queue = append(queue, i)
			// Traverse through the graph using DFS
			for len(queue) > 0 {
				// Get the next node from the queue
				node := queue[0]
				queue = queue[1:]
				// Mark the current node as used
				used[node] = true
				// Traverse through the neighbors of the current node
				for _, nextnode := range edge[node] {
					// If the neighbor is not used
					if !used[nextnode] {
						// Add the neighbor to the queue
						queue = append(queue, nextnode)
					}
				}
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Read an integer from the input
func readInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

// 