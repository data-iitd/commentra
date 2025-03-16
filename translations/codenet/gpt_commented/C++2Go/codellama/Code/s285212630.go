
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define long long as int for convenience
type int int
type P struct {
	_1 int
	_2 int
}

// Macros for loop and container operations
func rep(i, n int) {
	for i = 0; i < n; i++ {
	}
}
func all(c []P) []P {
	return c[:len(c)]
}
func uniq(c []P) {
	i := 0
	for j := 1; j < len(c); j++ {
		if c[i]._1 != c[j]._1 {
			i++
			c[i] = c[j]
		}
	}
	c = c[:i+1]
}
func _1(p P) int {
	return p._1
}
func _2(p P) int {
	return p._2
}
func pb(c []P, p P) []P {
	c = append(c, p)
	return c
}

// Constants for maximum levels, infinity, and modulo
const INF = 1145141919
const MOD = 1000000007
const MAX_L = 22

// Global variables
var N int // Number of nodes in the tree
var G [100000][]P // Adjacency list representation of the tree
var U [MAX_L][100000]int // U for storing ancestors, R for depth
var R [100000]int
var L [100000]int // L for storing the distance from the root

// Depth-first search to initialize ancestor and depth information
func dfs(x, p, r, l int) {
	U[0][x] = p // Set the parent of the current node
	R[x] = r    // Set the depth of the current node
	L[x] = l    // Set the distance from the root to the current node
	for _, pp := range G[x] { // Iterate through all adjacent nodes
		t := pp._1 // Get the adjacent node
		if t == p {
			continue // Skip the parent node to avoid cycles
		}
		dfs(t, x, r+1, l+pp._2) // Recursive DFS call for the child node
	}
}

// Function to find the lowest common ancestor (LCA) of two nodes
func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for i := 0; i < MAX_L; i++ { // Adjust b to the same depth as a
		if (R[a]-R[b])>>i&1 != 0 {
			b = U[i][b]
		}
	}
	if a == b {
		return a
	}
	for i := MAX_L - 1; i >= 0; i-- { // Find the LCA using binary lifting
		if U[i][a] != U[i][b] {
			a = U[i][a]
			b = U[i][b]
		}
	}
	return U[0][a] // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
func dist(x, y int) int {
	g := lca(x, y) // Find the LCA of x and y
	return L[x] + L[y] - 2*L[g] // Calculate the distance using LCA
}

func main() {
	// Read the number of nodes
	fmt.Scan(&N)
	rep(i, N-1) { // Read the edges of the tree
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Read nodes and weight
		a--
		b--
		G[a] = pb(G[a], P{b, c}) // Add edge to the adjacency list
		G[b] = pb(G[b], P{a, c}) // Add the reverse edge
	}

	// Initialize the ancestor table with -1
	rep(i, MAX_L) {
		rep(j, N) {
			U[i][j] = -1
		}
	}

	// Perform DFS from the root to fill ancestor and depth information
	dfs(0, -1, 0, 0)

	// Precompute ancestors for binary lifting
	for i := 0; i < MAX_L-1; i++ {
		rep(v, N) {
			if U[i][v] == -1 {
				U[i+1][v] = -1 // If no ancestor, set to -1
			} else {
				U[i+1][v] = U[i][U[i][v]] // Set the 2^(i+1) ancestor
			}
		}
	}

	var Q, K int // Number of queries and a specific node K
	fmt.Scan(&Q, &K)
	K--

	// Process each query
	rep(i, Q) {
		var x, y int // Nodes for which distance is to be calculated
		fmt.Scan(&x, &y)
		x--
		y--
		// Output the total distance from x to K and K to y
		fmt.Println(dist(x, K) + dist(K, y))
	}
}

