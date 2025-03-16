package main

import (
	"fmt"
)

const (
	M        = 100 // Maximum number of vertices in the graph
	whi      = 0   // Color code for white (unvisited)
	gra      = 1   // Color code for gray (visited but not fully explored)
	bla      = 2   // Color code for black (fully explored)
)

var (
	n        int
	T        [M][M]int
	color    [M]int
	d        [M]int
	Q        [M]int
	head     int
	tail     int
)

// Function to add an element to the queue
func enqueue(x int) {
	Q[tail] = x
	tail = (tail + 1) % M
}

// Function to remove and return an element from the queue
func dequeue() int {
	x := Q[head]
	head = (head + 1) % M
	return x
}

// Function to perform Breadth-First Search (BFS) starting from vertex s
func bfs(s int) {
	var i, u, v int

	// Initialize all vertices as unvisited and set their distances to a large value
	for i = 0; i < n; i++ {
		color[i] = whi
		d[i] = 1000000
	}

	// Start BFS from the source vertex s
	color[s] = gra
	d[s] = 0
	enqueue(s)

	// Continue BFS until the queue is empty
	for head != tail {
		u = dequeue()
		// Explore all adjacent vertices of u
		for v = 0; v < n; v++ {
			// If there is an edge from u to v and v is unvisited
			if T[u][v] == 1 && color[v] == whi {
				color[v] = gra
				d[v] = d[u] + 1
				enqueue(v)
			}
		}
		color[u] = bla
	}
}

func main() {
	var i, j int
	var u, k, v int

	// Read the number of vertices
	fmt.Scan(&n)

	// Initialize the adjacency matrix to zero (no edges)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges of the graph
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u--
		for j = 0; j < k; j++ {
			fmt.Scan(&v)
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

