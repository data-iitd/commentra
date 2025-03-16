
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Adjacency list to represent the graph
var g [][]int

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
	return 2*a + int(math.Min(1, float64(o))) + 1
}

func main() {
	// Initialize scanner for input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of vertices
	scanner.Scan()
	n := int(mustParseInt(scanner.Text()))

	// Initialize the adjacency list for the graph
	g = make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		parts := bytes.Split(scanner.Bytes(), []byte{' '})
		a := int(mustParseInt(parts[0])) - 1 // Read vertex a
		b := int(mustParseInt(parts[1])) - 1 // Read vertex b
		g[a] = append(g[a], b) // Add edge to the graph
		g[b] = append(g[b], a) // Add edge to the graph (undirected)
	}

	// Calculate maximum matching starting from vertex 0
	m := maxMatching(0, -1) / 2

	// Determine the winner based on the matching result
	if 2*m == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
}

// Function to parse an integer from a string
func mustParseInt(s string) int {
	n, err := strconv.Atoi(string(s))
	if err!= nil {
		panic(err)
	}
	return n
}

// Output:
// Second