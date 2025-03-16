package main

import (
	"fmt"
	"os"
)

// Function to perform Breadth-First Search (BFS) to color the graph
func bfs(v int, N int, G [][]int, E map[int]int) int {
	// Initialize visited list to keep track of visited nodes
	visited := make([]bool, N)
	// Initialize a queue for BFS using slice
	queue := make([]int, 0)
	// Initialize the maximum color index K
	K := -1
	// List to store the color of each node, initialized to -1 (no color)
	node2color := make([]int, N)
	// Start BFS from vertex v
	queue = append(queue, v)
	visited[v] = true
	for len(queue) > 0 {
		// Dequeue the front node
		q := queue[0]
		queue = queue[1:]
		// Initialize color for the current node
		color := 0
		// Iterate over all adjacent nodes
		for _, nex := range G[q] {
			if visited[nex] {
				continue
			}
			visited[nex] = true
			color++
			// Ensure the color is different from the parent node's color
			if color == node2color[q] {
				color++
			}
			// Assign the color to the node and record the edge color
			node2color[nex] = color
			E[min(q, nex)*N+max(q, nex)] = color
			// Enqueue the adjacent node for further exploration
			queue = append(queue, nex)
		}
		// Update the maximum color used
		K = max(K, color)
	}
	return K
}

// Main function to read input, construct the graph, and execute the BFS
func main() {
	// Read the number of nodes N
	var N int
	fmt.Scan(&N)
	// Initialize a list of slice objects to represent the graph
	G := make([][]int, N)
	// Initialize an empty map to store edge colors
	E := make(map[int]int)
	// Read edges to populate the graph and edge map
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		G[a-1] = append(G[a-1], b-1)
		G[b-1] = append(G[b-1], a-1)
		E[min(a-1, b-1)*N+max(a-1, b-1)] = 0
	}
	// Perform BFS to determine the maximum color and edge colors
	K := bfs(0, N, G, E)
	// Print the maximum color used
	fmt.Println(K)
	// Print the colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}
}

// Utility function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Utility function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of code
