package main

import (
	"bufio"
	"fmt"
	"os"
)

var g [][]int

// maxMatching calculates the maximum matching in a tree structure.
func maxMatching(v, p int) int {
	a, o := 0, 0 // Number of matched pairs and unmatched nodes
	for _, w := range g[v] {
		if w == p {
			continue // Skip the parent node
		}
		r := maxMatching(w, v) // Recursively calculate matching for child nodes
		a += r / 2            // Add half of the matches from the child
		o += r % 2            // Count the unmatched nodes
	}
	return 2*a + min(1, o) + 1 // Return the total number of matches
}

// min returns the minimum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := atoi(scanner.Text()) // Read the number of nodes
	g = make([][]int, n)     // Initialize the graph's adjacency list

	for i := 0; i < n-1; i++ { // Read the edges and construct the graph
		scanner.Scan()
		a := atoi(scanner.Text()) - 1 // Read node a and convert to 0-based index
		scanner.Scan()
		b := atoi(scanner.Text()) - 1 // Read node b and convert to 0-based index
		g[a] = append(g[a], b)        // Add edge from a to b
		g[b] = append(g[b], a)        // Add edge from b to a
	}

	m := maxMatching(0, -1) / 2 // Calculate the maximum matching
	if 2*m == n {
		fmt.Println("Second") // Determine the winner and print the result
	} else {
		fmt.Println("First")
	}
}

// atoi converts a string to an integer.
func atoi(s string) int {
	var n int
	for _, c := range s {
		n = n*10 + int(c-'0')
	}
	return n
}

// <END-OF-CODE>
