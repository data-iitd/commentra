package main

import (
	"bufio"
	"fmt"
	"os"
)

const INF = 1e18 // Define a constant for infinity

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscan(reader, &N, &M) // Read the number of nodes and edges

	edge := make([][]int, N) // Initialize the edge list to represent the graph
	for i := 0; i < M; i++ {
		var X, Y int
		fmt.Fscan(reader, &X, &Y) // Read each edge
		X-- // Adjust indices
		Y--
		edge[X] = append(edge[X], Y) // Add edge in both directions for an undirected graph
		edge[Y] = append(edge[Y], X)
	}

	used := make([]bool, N) // Initialize a list to track visited nodes
	ans := 0                // Initialize the counter for connected components

	for i := 0; i < N; i++ {
		if !used[i] {
			ans++ // Increment the counter for each new connected component found
			queue := []int{i} // Initialize a queue for BFS
			used[i] = true     // Mark the starting node as visited

			for len(queue) > 0 {
				node := queue[0] // Get the next node from the queue
				queue = queue[1:] // Remove the node from the queue

				for _, nextnode := range edge[node] {
					if !used[nextnode] {
						queue = append(queue, nextnode) // Add unvisited neighbors to the queue
						used[nextnode] = true            // Mark the neighbor as visited
					}
				}
			}
		}
	}
	fmt.Println(ans) // Output the total number of connected components
}

// <END-OF-CODE>
