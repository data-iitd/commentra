package main

import (
	"bufio"
	"fmt"
	"os"
)

const INF = 1e18

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of nodes (N) and edges (M)
	var N, M int
	fmt.Fscan(reader, &N, &M)

	// Initialize an adjacency list to represent the graph
	edge := make([][]int, N)

	// Read each edge and populate the adjacency list
	for i := 0; i < M; i++ {
		var X, Y int
		fmt.Fscan(reader, &X, &Y)
		X-- // Convert to 0-based index
		Y-- // Convert to 0-based index
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	// Array to track visited nodes
	used := make([]bool, N)

	// Variable to count the number of connected components
	ans := 0

	// Iterate through each node to find connected components
	for i := 0; i < N; i++ {
		if !used[i] { // If the node has not been visited
			ans++ // Increment the count of connected components
			queue := []int{i} // Initialize a queue for BFS
			used[i] = true // Mark the starting node as visited

			// Perform BFS to mark all reachable nodes from the current node
			for len(queue) > 0 {
				node := queue[0] // Dequeue a node
				queue = queue[1:] // Remove the first element

				// Explore all adjacent nodes
				for _, nextnode := range edge[node] {
					if !used[nextnode] { // If the adjacent node has not been visited
						queue = append(queue, nextnode) // Enqueue the adjacent node
						used[nextnode] = true // Mark the adjacent node as visited
					}
				}
			}
		}
	}

	// Output the number of connected components found
	fmt.Println(ans)
}

// <END-OF-CODE>
