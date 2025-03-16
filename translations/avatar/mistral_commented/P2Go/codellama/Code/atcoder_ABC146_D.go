#######
# Code
#######

// Import necessary libraries
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to perform Breadth First Search (BFS)
func bfs(v int, N int, G [][]int, E map[int]int) int {
	// Initialize visited array and queue
	visited := make([]bool, N)
	queue := make([]int, 0)

	// Initialize variables for coloring nodes
	K := -1
	node2color := make([]int, N)

	// Add starting node to the queue and mark it as visited
	queue = append(queue, v)
	visited[v] = true

	// BFS algorithm
	for len(queue) > 0 {
		// Dequeue the next node from the queue
		q := queue[0]
		queue = queue[1:]

		// Initialize color for the current node
		color := 0

		// Traverse through all neighbors of the current node
		for _, nex := range G[q] {
			// Skip if the neighbor is already visited
			if visited[nex] {
				continue
			}

			// Mark the neighbor as visited and assign it a color
			visited[nex] = true
			color += 1

			// If the color of the current node is same as its neighbor, assign a new color to the neighbor
			if color == node2color[q] {
				color += 1
			}

			// Update node2color and E dictionary with the new color
			node2color[nex] = color
			E[min(q, nex)*N+max(q, nex)] = color

			// Add the neighbor to the queue
			queue = append(queue, nex)
		}

		// Update the maximum color found so far
		K = max(K, color)
	}

	// Return the maximum color
	return K
}

// Main function to read input and call bfs function
func main() {
	// Read number of nodes from the input
	var N int
	fmt.Scan(&N)

	// Initialize graph as a list of slices and empty dictionary for edges
	G := make([][]int, N)
	E := make(map[int]int)

	// Read edges from the input and add them to the graph
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		G[a-1] = append(G[a-1], b-1)
		G[b-1] = append(G[b-1], a-1)
		E[min(a-1, b-1)*N+max(a-1, b-1)] = 0
	}

	// Call bfs function and print the result
	K := bfs(0, N, G, E)
	fmt.Println(K)

	// Print colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}
}

// Utility function to find minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Utility function to find maximum of two integers
func max(a, b int) int {
	if 