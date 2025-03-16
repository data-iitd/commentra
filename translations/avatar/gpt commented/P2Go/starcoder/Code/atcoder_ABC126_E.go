package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Set the recursion limit to a high value to handle deep recursions if needed
const MAX_RECURSION_DEPTH = 1000000000

func main() {
	// Read the number of nodes (N) and edges (M)
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	M, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize an adjacency list to represent the graph
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, 0)
	}

	// Read each edge and populate the adjacency list
	for i := 0; i < M; i++ {
		X, Y, Z := readInput(reader)
		edge[X-1] = append(edge[X-1], Y-1)
		edge[Y-1] = append(edge[Y-1], X-1)
	}

	// Array to track visited nodes
	used := make([]bool, N)

	// Variable to count the number of connected components
	ans := 0

	// Iterate through each node to find connected components
	for i := 0; i < N; i++ {
		if!used[i] {  // If the node has not been visited
			ans += 1  // Increment the count of connected components
			queue := make([]int, 0)  // Initialize a queue for BFS
			queue = append(queue, i)  // Start BFS from the current node

			// Perform BFS to mark all reachable nodes from the current node
			for len(queue) > 0 {
				node := queue[0]  // Dequeue a node
				queue = queue[1:]  // Remove the node from the queue
				used[node] = true  // Mark the node as visited

				// Explore all adjacent nodes
				for _, nextnode := range edge[node] {
					if!used[nextnode] {  // If the adjacent node has not been visited
						queue = append(queue, nextnode)  // Enqueue the adjacent node
			}
		}
	}

	// Output the number of connected components found
	fmt.Println(ans)
}

// Function to read input from standard input
func readInput(reader *bufio.Reader) (int, int, int) {
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	X, Y, Z := strings.Split(input, " ")
	return strconv.Atoi(X)
}

// 