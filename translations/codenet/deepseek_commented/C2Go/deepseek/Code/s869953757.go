package main

import (
	"fmt"
)

const (
	M    = 100
	whi  = 0
	gra  = 1
	bla  = 2
)

var (
	n        int
	T        [M][M]int
	color    [M]int
	d        [M]int
	Q        [M]int
	head     int = 0
	tail     int = 0
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
		color[i] = whi
		d[i] = 1000000
	}

	// Set the color and distance of the source node
	color[s] = gra
	d[s] = 0
	enqueue(s)

	// Continue BFS until the queue is empty
	for head != tail {
		u = dequeue() // Dequeue the front node
		// Explore all adjacent nodes
		for v = 0; v < n; v++ {
			if T[u][v] == 1 && color[v] == whi {
				color[v] = gra // Mark as gray
				d[v] = d[u] + 1 // Update distance
				enqueue(v) // Enqueue the node
			}
		}
		color[u] = bla // Mark as black
	}
}

// Main function to read the graph, execute BFS, and print distances
func main() {
	var i, j int
	var u, k, v int

	fmt.Scan(&n) // Read the number of nodes

	// Initialize the adjacency matrix with zeros
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges and construct the adjacency matrix
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u-- // Convert to 0-based index
		for j = 0; j < k; j++ {
			fmt.Scan(&v)
			v-- // Convert to 0-based index
			T[u][v] = 1 // Set the edge in the adjacency matrix
		}
	}

	bfs(0) // Execute BFS starting from node 0

	// Print the distances from the source node to all other nodes
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1
		}
		fmt.Printf("%d %d\n", i+1, d[i]) // Print node number and distance
	}
}

