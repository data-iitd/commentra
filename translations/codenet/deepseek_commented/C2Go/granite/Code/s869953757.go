

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	M     = 100
	whi   = 0
	gra   = 1
	bla   = 2
	white = 0
	gray  = 1
	black = 2
)

var (
	n   int
	T   [M][M]int
	col [M]int
	d   [M]int
	Q   [M]int
	head, tail int
)

func enqueue(x int) {
	Q[tail] = x
	tail = (tail + 1) % M
}

func dequeue() int {
	x := Q[head]
	head = (head + 1) % M
	return x
}

func bfs(s int) {
	var i, u, v int

	// Initialize all nodes to white, set distance to infinity
	for i = 0; i < n; i++ {
		col[i] = white
		d[i] = 1000000
	}

	// Set the color and distance of the source node
	col[s] = gray
	d[s] = 0
	enqueue(s)

	// Continue BFS until the queue is empty
	for head!= tail {
		u = dequeue() // Dequeue the front node
		// Explore all adjacent nodes
		for v = 0; v < n; v++ {
			if T[u][v] == 1 && col[v] == white {
				col[v] = gray // Mark as gray
				d[v] = d[u] + 1 // Update distance
				enqueue(v) // Enqueue the node
			}
		}
		col[u] = black // Mark as black
	}
}

func main() {
	var i, j int
	var u, k, v int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}

	// Initialize the adjacency matrix with zeros
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}

	// Read the edges and construct the adjacency matrix
	for i = 0; i < n; i++ {
		if scanner.Scan() {
			u, _ = strconv.Atoi(scanner.Text())
		}
		u-- // Convert to 0-based index
		if scanner.Scan() {
			k, _ = strconv.Atoi(scanner.Text())
		}
		for j = 0; j < k; j++ {
			if scanner.Scan() {
				v, _ = strconv.Atoi(scanner.Text())
			}
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
		fmt.Printf("%d %d\n", i+1, d[i]) // Print node number and distance
	}
}

