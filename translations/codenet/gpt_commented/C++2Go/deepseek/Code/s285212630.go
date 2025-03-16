package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define long long as int for convenience
type int = int64

// Macros for loop and container operations
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back

// Constants for maximum levels, infinity, and modulo
const int INF = 1145141919
const int MOD = 1000000007
const int MAX_L = 22

// Global variables
var N int
var G [100000][]P
var U [MAX_L][100000]int
var R [100000]int
var L [100000]int64

// Depth-first search to initialize ancestor and depth information
func dfs(x, p, r int, l int64) {
	U[0][x] = p // Set the parent of the current node
	R[x] = r // Set the depth of the current node
	L[x] = l // Set the distance from the root to the current node
	for _, pp := range G[x] { // Iterate through all adjacent nodes
		t := pp._1 // Get the adjacent node
		if t == p { continue } // Skip the parent node to avoid cycles
		dfs(t, x, r+1, l+int64(pp._2)) // Recursive DFS call for the child node
	}
}

// Function to find the lowest common ancestor (LCA) of two nodes
func lca(a, b int) int {
	if R[a] > R[b] { a, b = b, a } // Ensure a is the deeper node
	for k := 0; k < MAX_L; k++ { // Adjust b to the same depth as a
		if (R[a] - R[b]) >> k & 1 == 1 { b = U[k][b] }
	}
	if a == b { return a } // If both nodes are the same, return a
	for k := MAX_L - 1; k >= 0; k-- { // Find the LCA using binary lifting
		if U[k][a] != U[k][b] {
			a = U[k][a]
			b = U[k][b]
		}
	}
	return U[0][a] // Return the parent of a, which is the LCA
}

// Function to calculate the distance between two nodes
func dist(x, y int) int64 {
	g := lca(x, y) // Find the LCA of x and y
	return L[x] + L[y] - 2*L[g] // Calculate the distance using LCA
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N) // Read the number of nodes
	G = make([][]P, 100000) // Adjacency list representation of the tree
	for i := 0; i < N-1; i++ { // Read the edges of the tree
		var a, b, c int
		fmt.Fscan(reader, &a, &b, &c) // Read nodes and weight
		a--
		b--
		G[a] = append(G[a], P{b, int64(c)}) // Add edge to the adjacency list
		G[b] = append(G[b], P{a, int64(c)}) // Add the reverse edge
	}

	// Initialize the ancestor table with -1
	for i := 0; i < MAX_L; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}

	// Perform DFS from the root to fill ancestor and depth information
	dfs(0, -1, 0, 0)

	// Precompute ancestors for binary lifting
	for i := 0; i < MAX_L-1; i++ {
		for v := 0; v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
			}
		}
	}

	var Q, K int
	fmt.Fscan(reader, &Q, &K) // Read number of queries and node K
	K-- // Convert K to 0-based indexing

	// Process each query
	for i := 0; i < Q; i++ {
		var x, y int
		fmt.Fscan(reader, &x, &y) // Read the nodes
		x--
		y--
		// Output the total distance from x to K and K to y
		fmt.Fprintln(writer, dist(x, K) + dist(K, y))
	}
