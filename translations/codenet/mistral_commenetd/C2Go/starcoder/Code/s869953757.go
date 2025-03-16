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
var (
	n int
	T [100][100]int
	color [100]int
	d [100]int
	Q [100]int
	head, tail int
)

// Function to add an element to the queue
func enqueue(x int) {
	Q[tail] = x
	tail = (tail + 1) % 100
}

// Function to remove an element from the queue
func dequeue() int {
	var x int
	x = Q[head]
	head = (head + 1) % 100
	return x
}

// Breadth First Search Algorithm
func bfs(s int) {
	var i, u, v int // i is a counter, u and v are vertices

	// Initialize all vertices with white color and infinite distance
	for i = 0; i < n; i++ {
		color[i] = 0
		d[i] = 1000000
	}

	// Initialize source vertex with gray color and zero distance
	color[s] = 1
	d[s] = 0
	enqueue(s) // Enqueue source vertex

	// Traverse the queue until it is empty
	for head!= tail {
		u = dequeue() // Dequeue a vertex
		for v = 0; v < n; v++ { // Iterate through all adjacent vertices
			if T[u][v] == 1 && color[v] == 0 { // If the adjacent vertex is unvisited
				color[v] = 1 // Mark it as visited
				d[v] = d[u] + 1 // Update its distance
				enqueue(v) // Enqueue the adjacent vertex
			}
		}
		color[u] = 2 // Mark the current vertex as black
	}
}

// Main function
func main() {
	var i, j int // i and j are counters
	var u, k, v int // u is a vertex, k is the number of neighbors, and v is a neighbor

	// Read the number of vertices
	fmt.Scanf("%d", &n)

	// Initialize the adjacency matrix with zeros
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges and add them to the adjacency matrix
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u-- // Decrease the index of the source vertex by 1
		for j = 0; j < k; j++ {
			fmt.Scanf("%d", &v)
			v-- // Decrease the index of the neighbor vertex by 1
			T[u][v] = 1 // Add an edge between the vertices
		}
	}

	// Perform BFS algorithm starting from the source vertex 0
	bfs(0)

	// Print the results
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1 // Set the distance to -1 if it is unreachable
		}
		fmt.Printf("%d %d\n", i+1, d[i]) // Print the vertex index and its distance from the source
	}
}

