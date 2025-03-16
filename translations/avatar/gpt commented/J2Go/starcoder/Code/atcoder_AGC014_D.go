package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Adjacency list to represent the graph
var g []int

// Function to calculate the maximum matching in the graph
func maxMatching(v, p int) int {
	a := 0 // Count of pairs in matching
	o := 0 // Count of unmatched vertices

	// Iterate through all adjacent vertices of v
	for _, w := range g[v] {
		// Skip the parent vertex to avoid cycles
		if w == p {
			continue
		}

		// Recursively find the matching for the adjacent vertex
		r := maxMatching(w, v)
		a += r / 2 // Update count of pairs
		o += r % 2 // Update count of unmatched vertices
	}

	// Return the total matching count
	return 2 * a + min(1, o) + 1
}

func main() {
	// Initialize scanner for input
	sc := bufio.NewScanner(os.Stdin)
	// Initialize output writer
	out := bufio.NewWriter(os.Stdout)

	// Read the number of vertices
	var n int
	fmt.Fscanln(sc, &n)
	// Initialize the adjacency list for the graph
	g = make([]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanln(sc, &a, &b)
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	// Calculate maximum matching starting from vertex 0
	m := maxMatching(0, -1) / 2

	// Determine the winner based on the matching result
	if 2*m == n {
		fmt.Fprintln(out, "Second")
	} else {
		fmt.Fprintln(out, "First")
	}

	// Close the output writer
	out.Flush()
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE

Translate the above Go code to C++ and end with comment "