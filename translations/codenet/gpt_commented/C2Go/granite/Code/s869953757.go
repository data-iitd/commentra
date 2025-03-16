
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	M = 100 // Maximum number of vertices in the graph
	whi = 0  // Color code for white (unvisited)
	gra = 1  // Color code for gray (visited but not fully explored)
	bla = 2  // Color code for black (fully explored)
)

var (
	n int // Number of vertices in the graph
	T [M][M]int // Adjacency matrix to represent the graph
	color [M]int // Arrays to store the color and distance of each vertex
	d [M]int // Arrays to store the color and distance of each vertex
	Q [M]int // Queue for BFS implementation
	head, tail int // Variables to keep track of the queue
)

// Function to add an element to the queue
func enqueue(x int) {
	Q[tail] = x // Add element x to the queue
	tail = (tail + 1) % M // Update tail index in a circular manner
}

// Function to remove and return an element from the queue
func dequeue() int {
	x := Q[head] // Get the front element of the queue
	head = (head + 1) % M // Update head index in a circular manner
	return x // Return the dequeued element
}

// Function to perform Breadth-First Search (BFS) starting from vertex s
func bfs(s int) {
	var i, u, v int

	// Initialize all vertices as unvisited and set their distances to a large value
	for i = 0; i < n; i++ {
		color[i] = whi // Set color to white (unvisited)
		d[i] = 1000000 // Set distance to a large number (infinity)
	}

	// Start BFS from the source vertex s
	color[s] = gra // Mark the source vertex as gray (visited)
	d[s] = 0 // Distance to source vertex is 0
	enqueue(s) // Enqueue the source vertex

	// Continue BFS until the queue is empty
	for head!= tail {
		u = dequeue() // Dequeue a vertex from the queue
		// Explore all adjacent vertices of u
		for v = 0; v < n; v++ {
			// If there is an edge from u to v and v is unvisited
			if T[u][v] == 1 && color[v] == whi {
				color[v] = gra // Mark v as gray (visited)
				d[v] = d[u] + 1 // Update distance to v
				enqueue(v) // Enqueue vertex v for further exploration
			}
		}
		color[u] = bla // Mark u as black (fully explored)
	}
}

// Main function
func main() {
	var i, j, u, k, v int

	// Read the number of vertices
	fmt.Scan(&n)

	// Initialize the adjacency matrix to zero (no edges)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0 // No edge between vertices i and j
		}
	}

	// Read the edges of the graph
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k) // Read vertex u and number of edges k
		u-- // Convert to zero-based index
		for j = 0; j < k; j++ {
			fmt.Scan(&v) // Read each adjacent vertex v
			v-- // Convert to zero-based index
			T[u][v] = 1 // Set the edge from u to v in the adjacency matrix
		}
	}

	// Perform BFS starting from vertex 0
	bfs(0)

	// Output the distance from the source vertex to each vertex
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1 // If distance is still infinity, set it to -1
		}
		fmt.Printf("%d %d\n", i+1, d[i]) // Print vertex number and its distance
	}
}

