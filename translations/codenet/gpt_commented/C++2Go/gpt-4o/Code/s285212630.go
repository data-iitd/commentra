package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	INF    = 1145141919
	MOD    = 1000000007
	MAX_L  = 22
)

type Pair struct {
	first, second int64
}

var (
	N int64                     // Number of nodes in the tree
	G   [100000][]Pair          // Adjacency list representation of the tree
	U   [MAX_L][100000]int64    // U for storing ancestors
	R   [100000]int64           // R for depth
	L   [100000]int64           // L for storing the distance from the root
)

func dfs(x, p, r int64, l int64) {
	U[0][x] = p // Set the parent of the current node
	R[x] = r    // Set the depth of the current node
	L[x] = l    // Set the distance from the root to the current node
	for _, pp := range G[x] { // Iterate through all adjacent nodes
		t := pp.first // Get the adjacent node
		if t == p {
			continue // Skip the parent node to avoid cycles
		}
		dfs(t, x, r+1, l+pp.second) // Recursive DFS call for the child node
	}
}

// Function to find the lowest common ancestor (LCA) of two nodes
func lca(a, b int64) int64 {
	if R[a] > R[b] {
		a, b = b, a // Ensure a is the deeper node
	}
	for k := int64(0); k < MAX_L; k++ { // Adjust b to the same depth as a
		if (R[a]-R[b])&(1<<k) != 0 {
			b = U[k][b]
		}
	}
	if a == b {
		return a // If both nodes are the same, return a
	}
	for k := MAX_L - 1; k >= 0; k-- { // Find the LCA using binary lifting
		if U[k][a] != U[k][b] {
			a = U[k][a]
			b = U[k][b]
		}
	}
	return U[0][a] // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
func dist(x, y int64) int64 {
	g := lca(x, y) // Find the LCA of x and y
	return L[x] + L[y] - 2*L[g] // Calculate the distance using LCA
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &N) // Read the number of nodes
	for i := int64(0); i < N-1; i++ { // Read the edges of the tree
		var a, b, c int64
		fmt.Fscan(reader, &a, &b, &c) // Read nodes and weight
		a-- // Convert to 0-based indexing
		b-- // Convert to 0-based indexing
		G[a] = append(G[a], Pair{b, c}) // Add edge to the adjacency list
		G[b] = append(G[b], Pair{a, c}) // Add the reverse edge
	}

	// Initialize the ancestor table with -1
	for i := int64(0); i < MAX_L; i++ {
		for j := int64(0); j < N; j++ {
			U[i][j] = -1
		}
	}

	// Perform DFS from the root to fill ancestor and depth information
	dfs(0, -1, 0, 0)

	// Precompute ancestors for binary lifting
	for i := int64(0); i < MAX_L-1; i++ {
		for v := int64(0); v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1 // If no ancestor, set to -1
			} else {
				U[i+1][v] = U[i][U[i][v]] // Set the 2^(i+1) ancestor
			}
		}
	}

	var Q, K int64 // Number of queries and a specific node K
	fmt.Fscan(reader, &Q, &K) // Read number of queries and node K
	K-- // Convert K to 0-based indexing

	// Process each query
	for i := int64(0); i < Q; i++ {
		var x, y int64 // Nodes for which distance is to be calculated
		fmt.Fscan(reader, &x, &y) // Read the nodes
		x-- // Convert to 0-based indexing
		y-- // Convert to 0-based indexing
		// Output the total distance from x to K and K to y
		fmt.Fprintln(writer, dist(x, K)+dist(K, y))
	}
}

// <END-OF-CODE>
