package main

import (
	"fmt"
)

// BitMatching structure for solving Bipartite Graph Matching problem.
type BitMatching struct {
	G    [][]int // Adjacency list for the graph.
	match []int  // Stores the matching result for each vertex.
	used  []bool // Stores whether a vertex is being processed or not.
	V    int     // Maximum number of vertices in the graph.
}

// NewBitMatching initializes a new BitMatching instance.
func NewBitMatching(v int) *BitMatching {
	bm := &BitMatching{
		G:    make([][]int, 2*v),
		match: make([]int, 2*v),
		used:  make([]bool, 2*v),
		V:    v,
	}
	for i := range bm.match {
		bm.match[i] = -1 // Initialize match array with -1.
	}
	return bm
}

// Add adds an edge between two vertices in the graph.
func (bm *BitMatching) Add(a, b int) {
	bm.G[a] = append(bm.G[a], b+bm.V) // Adds the destination vertex to the adjacency list of the source vertex.
	bm.G[b+bm.V] = append(bm.G[b+bm.V], a) // Adds the source vertex to the adjacency list of the destination vertex.
}

// DFS performs Depth First Search to find a matching between vertices.
func (bm *BitMatching) DFS(v int) bool {
	bm.used[v] = true // Marks the current vertex as being processed.

	for _, u := range bm.G[v] {
		w := bm.match[u] // Gets the neighboring vertex and its matching vertex.

		if w < 0 || (!bm.used[w] && bm.DFS(w)) { // If the neighboring vertex is not matched or can be matched, update the matching result.
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false // If no matching is found, return false.
}

// Exec executes the Bipartite Graph Matching algorithm.
func (bm *BitMatching) Exec() int {
	res := 0 // Initializes the result variable.

	for v := 0; v < bm.V; v++ { // Iterates through all vertices in the graph.
		if bm.match[v] < 0 { // If the current vertex is not matched, perform DFS to find a matching.
			for i := range bm.used {
				bm.used[i] = false // Reset used array.
			}
			if bm.DFS(v) {
				res++
			}
		}
	}
	return res // Returns the number of matched vertices.
}

// GCD computes the greatest common divisor of two numbers using Euclidean algorithm.
func GCD(a, b int) int {
	if b == 0 {
		return a // Base case: if b is 0, return a.
	}
	return GCD(b, a%b) // Recursive case: call GCD with b and the remainder of a divided by b.
}

// Main function to read input data and perform the Bipartite Graph Matching algorithm.
func main() {
	const MN = 520
	for {
		var n, m int // Reads the number of vertices and edges in the graph.
		fmt.Scan(&n, &m)

		if n == 0 {
			break // If the number of vertices is 0, breaks the loop.
		}

		bm := NewBitMatching(MN) // Initializes the graph data structures.

		a := make([]int, n) // Reads the input data for vertices a.
		b := make([]int, m) // Reads the input data for vertices b.

		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&b[i])
		}

		for i := 0; i < n; i++ { // Iterates through all vertices a.
			for j := 0; j < m; j++ { // Iterates through all vertices b.
				if GCD(a[i], b[j]) != 1 { // If the GCD of a[i] and b[j] is not 1, adds an edge between them.
					bm.Add(i, j)
				}
			}
		}

		fmt.Println(bm.Exec()) // Executes the Bipartite Graph Matching algorithm and prints the result.
	}
}

// <END-OF-CODE>
