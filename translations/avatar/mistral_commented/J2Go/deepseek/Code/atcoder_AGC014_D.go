package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var g [][]int
var maxMatching int

// Function to find the maximum number of edges that can be matched in a bipartite graph
func maxMatching(v, p int) int {
	a := 0 // Number of edges matched from the neighboring vertices of 'v'
	o := 0 // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

	// Iterating through all the neighbors of 'v'
	for _, w := range g[v] {
		if w == p {
			continue // Skip if the neighbor is 'p' (self-loop)
		}

		// Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
		r := maxMatching(w, v)
		a += r / 2
		o += r % 2
	}

	// Returning the result based on the parity of 'o'
	return 2*a + min(1, o)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Creating a new Scanner instance for reading input
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Reading the number of vertices in the graph
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initializing the graph as a slice of slices
	g = make([][]int, n)

	// Reading the edges and adding them to the graph
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		edges := strings.Fields(scanner.Text())
		a, _ := strconv.Atoi(edges[0])
		b, _ := strconv.Atoi(edges[1])
		g[a-1] = append(g[a-1], b-1) // Adding the edge from 'a' to 'b'
		g[b-1] = append(g[b-1], a-1) // Adding the edge from 'b' to 'a'
	}

	// Finding the maximum number of edges that can be matched in the graph
	maxMatching = maxMatching(0, -1) / 2

	// Printing the result based on whether all vertices have even degree or not
	if 2*maxMatching == n {
		fmt.Fprintln(writer, "Second")
	} else {
		fmt.Fprintln(writer, "First")
	}
}

