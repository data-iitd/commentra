package main

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

// Function to remove and return an element from the queue
func dequeue() int {
	var x int
	x = Q[head]
	head = (head + 1) % 100
	return x
}

// Function to perform Breadth-First Search (BFS) starting from vertex s
func bfs(s int) {
	var i, u, v int

	// Initialize all vertices as unvisited and set their distances to a large value
	for i = 0; i < n; i++ {
		color[i] = 0
		d[i] = 1000000
	}

	// Start BFS from the source vertex s
	color[s] = 1
	d[s] = 0
	enqueue(s)

	// Continue BFS until the queue is empty
	for head!= tail {
		u = dequeue()
		// Explore all adjacent vertices of u
		for v = 0; v < n; v++ {
			// If there is an edge from u to v and v is unvisited
			if T[u][v] == 1 && color[v] == 0 {
				color[v] = 1
				d[v] = d[u] + 1
				enqueue(v)
			}
		}
		color[u] = 2
	}
}

// Main function
func main() {
	var i, j int
	var u, k, v int

	// Read the number of vertices
	fmt.Scanf("%d", &n)

	// Initialize the adjacency matrix to zero (no edges)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges of the graph
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u--
		for j = 0; j < k; j++ {
			fmt.Scanf("%d", &v)
			v--
			T[u][v] = 1
		}
	}

	// Perform BFS starting from vertex 0
	bfs(0)

	// Output the distance from the source vertex to each vertex
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1
		}
		fmt.Printf("%d %d\n", i+1, d[i])
	}
}

