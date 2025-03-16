package main

import (
	"fmt"
)

const MN = 520

type BitMatching struct {
	G    [][]int
	match []int
	used  []bool
}

func NewBitMatching() *BitMatching {
	return &BitMatching{
		G:    make([][]int, 2*MN),
		match: make([]int, 2*MN),
		used:  make([]bool, 2*MN),
	}
}

// Initialize the graph
func (bm *BitMatching) init() {
	for i := range bm.G {
		bm.G[i] = nil // Clear all edges
	}
}

// Add an edge between node a and node b in the bipartite graph
func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+MN) // Add edge from a to b+MN
	bm.G[b+MN] = append(bm.G[b+MN], a) // Add edge from b+MN to a
}

// Depth-First Search to find augmenting paths
func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true // Mark the node as visited
	for _, u := range bm.G[v] {
		w := bm.match[u]
		if w < 0 || (!bm.used[w] && bm.dfs(w)) { // If the node is not matched or can find an augmenting path
			bm.match[v] = u // Assign the match
			bm.match[u] = v // Assign the match
			return true     // Return true as we found an augmenting path
		}
	}
	return false // Return false if no augmenting path is found
}

// Execute the bipartite matching algorithm
func (bm *BitMatching) exec() int {
	res := 0 // Initialize the result
	for i := range bm.match {
		bm.match[i] = -1 // Initialize all matches to -1 (no match)
	}
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 { // If the node is not matched
			for i := range bm.used {
				bm.used[i] = false // Reset the used array
			}
			if bm.dfs(v) { // Perform DFS from the node
				res++ // Increment the result if an augmenting path is found
			}
		}
	}
	return res // Return the total number of matches found
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a // Base case: if b is 0, return a
	}
	return gcd(b, a%b) // Recursive call: compute GCD of b and the remainder of a divided by b
}

func main() {
	bm := NewBitMatching() // Create an instance of BitMatching
	for {
		var n, m int
		fmt.Scan(&n, &m) // Read the number of elements in the two sets
		if n == 0 {
			break // If n is 0, break the loop
		}
		bm.init() // Initialize the bipartite graph
		a := make([]int, n) // Array to store the elements of the first set
		b := make([]int, m) // Array to store the elements of the second set
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i]) // Read the elements of the first set
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i]) // Read the elements of the second set
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 { // Check if the GCD is not 1
					bm.add(i, j) // Add an edge between the corresponding nodes if GCD is not 1
				}
			}
		}
		fmt.Println(bm.exec()) // Execute the bipartite matching and print the result
	}
}

// <END-OF-CODE>
