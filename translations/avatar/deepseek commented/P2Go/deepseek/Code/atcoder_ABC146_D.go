package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to perform Breadth-First Search (BFS) to color the graph
func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	// Initialize visited list to keep track of visited nodes
	visited := make([]bool, N)
	// Initialize a queue for BFS
	queue := []int{v}
	// Initialize the maximum color index K
	K := -1
	// List to store the color of each node, initialized to -1 (no color)
	node2color := make([]int, N)
	for i := 0; i < N; i++ {
		node2color[i] = -1
	}
	// Start BFS from vertex v
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
			edge := [2]int{min(q, nex), max(q, nex)}
			E[edge] = color
			// Enqueue the adjacent node for further exploration
			queue = append(queue, nex)
		}
		// Update the maximum color used
		if color > K {
			K = color
		}
	}
	return K
}

// Main function to read input, construct the graph, and execute the BFS
func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the number of nodes N
	scanner.Scan()
	N := parseInt(scanner.Text())
	// Initialize a slice of slices to represent the graph
	G := make([][]int, N)
	// Initialize an empty map to store edge colors
	E := make(map[[2]int]int)
	// Read edges to populate the graph and edge dictionary
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, b := parseInt(scanner.Text())
		a--
		b--
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[[2]int{a, b}] = 0
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

// Helper function to convert string to integer
func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

