
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to perform Breadth First Search (BFS)
func bfs(v int, N int, G [][]int, E map[string]int) int {
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
			E[fmt.Sprintf("%d %d", q, nex)] = color

			// Add the neighbor to the queue
			queue = append(queue, nex)
		}

		// Update the maximum color found so far
		K = max(K, color)
	}

	// Return the maximum color
	return K
}

// Function to read input and call bfs function
func main() {
	// Initialize input reader
	reader := bufio.NewReader(os.Stdin)

	// Read number of nodes from the input
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize graph as a list of slices and empty dictionary for edges
	G := make([][]int, N)
	E := make(map[string]int)

	// Read edges from the input and add them to the graph
	for i := 0; i < N-1; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		a -= 1
		b -= 1
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[fmt.Sprintf("%d %d", a, b)] = 0
	}

	// Call bfs function and print the result
	K := bfs(0, N, G, E)
	fmt.Println(K)

	// Print colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}
}

// Function to read a single line from the input
func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

// Function to find the maximum of two integers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// Call the main function
func main() {
	main()
}

