
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
const (
	M = 100
)

var (
	n int
	T [M][M]int
	color [M]int
	d [M]int
	Q [M]int
	head, tail int
)

// Function to enqueue an element into the queue
func enqueue(x int) {
	Q[tail] = x
	tail = (tail + 1) % M
}

// Function to dequeue an element from the queue
func dequeue() int {
	x := Q[head]
	head = (head + 1) % M
	return x
}

// Function to perform Breadth-First Search (BFS) starting from node s
func bfs(s int) {
	var i, u, v int

	// Initialize all nodes to white, set distance to infinity
	for i = 0; i < n; i++ {
		color[i] = 0
		d[i] = 1000000
	}

	// Set the color and distance of the source node
	color[s] = 1
	d[s] = 0
	enqueue(s)

	// Continue BFS until the queue is empty
	for head!= tail {
		u = dequeue() // Dequeue the front node
		// Explore all adjacent nodes
		for v = 0; v < n; v++ {
			if T[u][v] == 1 && color[v] == 0 {
				color[v] = 1 // Mark as gray
				d[v] = d[u] + 1 // Update distance
				enqueue(v) // Enqueue the node
			}
		}
		color[u] = 2 // Mark as black
	}
}

// Main function to read the graph, execute BFS, and print distances
func main() {
	var i, j int
	var u, k, v int

	fmt.Scanf("%d", &n) // Read the number of nodes

	// Initialize the adjacency matrix with zeros
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges and construct the adjacency matrix
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u-- // Convert to 0-based index
		for j = 0; j < k; j++ {
			fmt.Scanf("%d", &v)
			v-- // Convert to 0-based index
			T[u][v] = 1 // Set the edge in the adjacency matrix
		}
	}

	bfs(0) // Execute BFS starting from node 0

	// Print the distances from the source node to all other nodes
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1 // If unreachable, set distance to -1
		}
		fmt.Printf("%d %d\n", i + 1, d[i]) // Print node number and distance
	}
}

