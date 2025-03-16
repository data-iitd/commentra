
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Set the recursion limit to a high value to handle deep recursions if needed
const RECURSION_LIMIT = 100000000

// Define a constant for infinity
const INF = 100000000000000000

// Function to read input from standard input
func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(line), "\r\n")
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of nodes (N) and edges (M)
	line := readLine(reader)
	N, M := 0, 0
	tmp := strings.Split(line, " ")
	N, _ = strconv.Atoi(tmp[0])
	M, _ = strconv.Atoi(tmp[1])

	// Initialize an adjacency list to represent the graph
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, 0)
	}

	// Read each edge and populate the adjacency list
	for i := 0; i < M; i++ {
		line = readLine(reader)
		X, Y, Z := 0, 0, 0
		tmp := strings.Split(line, " ")
		X, _ = strconv.Atoi(tmp[0])
		Y, _ = strconv.Atoi(tmp[1])
		Z, _ = strconv.Atoi(tmp[2])
		X--
		Y--
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	// Array to track visited nodes
	used := make([]bool, N)

	// Variable to count the number of connected components
	ans := 0

	// Iterate through each node to find connected components
	for i := 0; i < N; i++ {
		if!used[i] { // If the node has not been visited
			ans++ // Increment the count of connected components
			queue := make([]int, 0) // Initialize a queue for BFS
			queue = append(queue, i) // Start BFS from the current node

			// Perform BFS to mark all reachable nodes from the current node
			for len(queue) > 0 {
				node := queue[0] // Dequeue a node
				queue = queue[1:] // Remove the dequeued node from the queue
				used[node] = true // Mark the node as visited

				// Explore all adjacent nodes
				for _, nextnode := range edge[node] {
					if!used[nextnode] { // If the adjacent node has not been visited
						queue = append(queue, nextnode) // Enqueue the adjacent node
					}
				}
			}
		}
	}

	// Output the number of connected components found
	fmt.Println(ans)
}

