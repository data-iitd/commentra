package main

import (
	"fmt"
)

const MN = 520 // Maximum number of vertices

type BitMatching struct {
	G    [][]int // Adjacency list for the bipartite graph
	match []int  // Array to store matches for vertices
	used  []bool // Array to track visited vertices during DFS
}

// Initializes the graph by clearing the adjacency list
func (bm *BitMatching) init() {
	bm.G = make([][]int, 2*MN)
	bm.match = make([]int, 2*MN)
	bm.used = make([]bool, 2*MN)
	for i := range bm.match {
		bm.match[i] = -1 // Initialize matches to -1 (unmatched)
	}
}

// Adds an edge between vertex a and vertex b in the bipartite graph
func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+MN) // Connect a to b in the second set
	bm.G[b+MN] = append(bm.G[b+MN], a) // Connect b to a in the first set
}

// Depth-First Search to find an augmenting path
func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true // Mark the current vertex as visited
	for _, u := range bm.G[v] {
		w := bm.match[u] // Get the matched vertex for u
		// If u is unmatched or we can find an augmenting path
		if w < 0 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u // Match v with u
			bm.match[u] = v // Match u with v
			return true     // Found a match
		}
	}
	return false // No match found
}

// Executes the matching algorithm and returns the size of the maximum matching
func (bm *BitMatching) exec() int {
	res := 0 // Result variable to count matches
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 { // If vertex v is unmatched
			bm.used = make([]bool, 2*MN) // Reset visited array
			if bm.dfs(v) { // Try to find a match for v
				res++ // Increment the result if a match is found
			}
		}
	}
	return res // Return the total number of matches
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a // Base case: if b is 0, return a
	}
	return gcd(b, a%b) // Recursive case: GCD of b and a mod b
}

func main() {
	var bm BitMatching
	for {
		var n, m int // Number of elements in two sets
		fmt.Scan(&n, &m) // Read the sizes of the two sets
		if n == 0 {
			break // Exit if n is 0 (no more input)
		}

		bm.init() // Initialize the BitMatching instance
		a := make([]int, n) // Arrays to hold the elements of the first set
		b := make([]int, m) // Arrays to hold the elements of the second set
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i]) // Read elements of the first set
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i]) // Read elements of the second set
		}

		// Build the bipartite graph based on the GCD condition
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 { // If GCD is not 1, add an edge
					bm.add(i, j)
				}
			}
		}

		// Execute the matching algorithm and print the result
		fmt.Println(bm.exec())
	}
}

// <END-OF-CODE>
