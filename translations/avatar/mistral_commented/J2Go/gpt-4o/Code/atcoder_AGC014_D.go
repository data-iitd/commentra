package main

import (
	"bufio"
	"fmt"
	"os"
)

// Declaring global variables
var g [][]int // Adjacency list for the graph
var maxMatching int // To store the maximum number of edges that can be matched in a bipartite graph

// Function to find the maximum number of edges that can be matched in a bipartite graph
func maxMatchingFunc(v, p int) int {
	a := 0 // Number of edges matched from the neighboring vertices of 'v'
	o := 0 // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

	// Iterating through all the neighbors of 'v'
	for _, w := range g[v] {
		if w == p {
			continue // Skip if the neighbor is 'p' (self-loop)
		}

		// Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
		r := maxMatchingFunc(w, v)
		a += r / 2
		o += r % 2
	}

	// Returning the result based on the parity of 'o'
	return 2*a + min(1, o)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Creating a buffered reader for input
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of vertices in the graph
	var n int
	fmt.Fscan(reader, &n)

	// Initializing the graph as a slice of slices
	g = make([][]int, n)

	// Reading the edges and adding them to the graph
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a-- // Adjusting for 0-based index
		b-- // Adjusting for 0-based index
		g[a] = append(g[a], b) // Adding the edge from 'a' to 'b'
		g[b] = append(g[b], a) // Adding the edge from 'b' to 'a'
	}

	// Finding the maximum number of edges that can be matched in the graph
	maxMatching = maxMatchingFunc(0, -1) / 2

	// Printing the result based on whether all vertices have even degree or not
	if 2*maxMatching == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
}

// <END-OF-CODE>
