package main

import (
	"fmt"
)

// BitMatching class for finding maximum matching in a bipartite graph.
// The algorithm runs in O(EV) time complexity.
type BitMatching struct {
	G [2 * 520][]int // Adjacency list for the bipartite graph
	match [2 * 520]int // Array to store matches for vertices
	used [2 * 520]bool // Array to track visited vertices during DFS
}

// Initializes the graph by clearing the adjacency list
func (bm *BitMatching) init() {
	for i := 0; i < 2*520; i++ {
		bm.G[i] = bm.G[i][:0]
	}
}

// Adds an edge between vertex a and vertex b in the bipartite graph
// Note: b is adjusted by adding V to differentiate between the two sets
func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b + 520) // Connect a to b in the second set
	bm.G[b + 520] = append(bm.G[b + 520], a) // Connect b to a in the first set
}

// Depth-First Search to find an augmenting path
func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true // Mark the current vertex as visited
	for i := 0; i < len(bm.G[v]); i++ {
		u := bm.G[v][i]
		w := bm.match[u]
		// If u is unmatched or we can find an augmenting path
		if w < 0 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true // Found a match
		}
	}
	return false // No match found
}

// Executes the matching algorithm and returns the size of the maximum matching
func (bm *BitMatching) exec() int {
	res := 0 // Result variable to count matches
	for i := 0; i < 520; i++ {
		bm.match[i] = -1 // Initialize matches to -1 (unmatched)
	}
	for v := 0; v < 520; v++ {
		if bm.match[v] < 0 { // If vertex v is unmatched
			for i := 0; i < len(bm.G[v]); i++ {
				bm.used[bm.G[v][i]] = false // Reset visited array
			}
			if bm.dfs(v) { // Try to find a match for v
				res++ // Increment the result if a match is found
			}
		}
	}
	return res // Return the total number of matches
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}

		bm := new(BitMatching)
		bm.init()
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i])
		}

		// Build the bipartite graph based on the GCD condition
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(int64(a[i]), int64(b[j])) != 1 { // If GCD is not 1, add an edge
					bm.add(i, j)
				}
			}
		}

		// Execute the matching algorithm and print the result
		fmt.Println(bm.exec())
	}
}

