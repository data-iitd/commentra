package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var g [][]int // Adjacency list to represent the graph

// Function to calculate the maximum matching in the graph
func maxMatching(v, p int) (int, int) {
	a := 0 // Count of pairs in matching
	o := 0 // Count of unmatched vertices

	// Iterate through all adjacent vertices of v
	for _, w := range g[v] {
		// Skip the parent vertex to avoid cycles
		if w == p {
			continue
		}

		// Recursively find the matching for the adjacent vertex
		r, _ := maxMatching(w, v)
		a += r / 2 // Update count of pairs
		o += r % 2 // Update count of unmatched vertices
	}

	// Return the total matching count
	return 2*a + min(1, o) + 1, 0
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Initialize scanner for input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of vertices
	scanner.Scan()
	n := toInt(scanner.Text())

	// Initialize the adjacency list for the graph
	g = make([][]int, n)

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		edge := strings.Split(scanner.Text(), " ")
		a := toInt(edge[0]) - 1 // Read vertex a
		b := toInt(edge[1]) - 1 // Read vertex b
		g[a] = append(g[a], b)   // Add edge to the graph
		g[b] = append(g[b], a)   // Add edge to the graph (undirected)
	}

	// Calculate maximum matching starting from vertex 0
	m, _ := maxMatching(0, -1)

	// Determine the winner based on the matching result
	if 2*m == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
}

// Helper function to convert string to int
func toInt(s string) int {
	var n int
	fmt.Sscanf(s, "%d", &n)
	return n
}

// <END-OF-CODE>
