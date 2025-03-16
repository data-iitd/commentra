
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define long long as int for convenience
type int64 = int

// Macros for loop and container operations
func rep(i, n int) {
	for ; i < n; i++
}

func all(c []int) []int {
	return c
}

func uniq(c []int) []int {
	return c
}

func _1(p Pair) int {
	return p.First
}

func _2(p Pair) int {
	return p.Second
}

func pb(c []int, v int) []int {
	return append(c, v)
}

// Constants for maximum levels, infinity, and modulo
const (
	INF = 1145141919
	MOD = 1000000007
	MAX_L = 22
)

// Global variables
var (
	N int64 // Number of nodes in the tree
	G []Pair // Adjacency list representation of the tree
	U [MAX_L][100000]int64 // U for storing ancestors
	R [100000]int64 // R for storing depth
	L [100000]int64 // L for storing the distance from the root
)

// Pair struct for representing a pair of integers
type Pair struct {
	First, Second int64
}

// Depth-first search to initialize ancestor and depth information
func dfs(x, p, r, l int64) {
	U[0][x] = p // Set the parent of the current node
	R[x] = r // Set the depth of the current node
	L[x] = l // Set the distance from the root to the current node
	for _, pp := range G[x] { // Iterate through all adjacent nodes
		t := pp.First // Get the adjacent node
		if t == p {
			continue // Skip the parent node to avoid cycles
		}
		dfs(t, x, r+1, l+pp.Second) // Recursive DFS call for the child node
	}
}

// Function to find the lowest common ancestor (LCA) of two nodes
func lca(a, b int64) int64 {
	if R[a] > R[b] {
		a, b = b, a // Ensure a is the deeper node
	}
	for k := int64(0); k < MAX_L; k++ { // Adjust b to the same depth as a
		if (R[a]-R[b])>>k&1 == 1 {
			b = U[k][b]
		}
	}
	if a == b {
		return a // If both nodes are the same, return a
	}
	for k := MAX_L - 1; k >= 0; k-- { // Find the LCA using binary lifting
		if U[k][a]!= U[k][b] {
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
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var x, y, a, b, c, q, k int64
	scanner.Scan()
	N = scanner.Int64()
	G = make([]Pair, N-1)
	for i := int64(0); i < N-1; i++ {
		scanner.Scan()
		a = scanner.Int64()
		scanner.Scan()
		b = scanner.Int64()
		scanner.Scan()
		c = scanner.Int64()
		a--
		b--
		G[i] = Pair{b, c}
		G[i+N-1] = Pair{a, c}
	}
	for i := int64(0); i < MAX_L; i++ {
		for j := int64(0); j < N; j++ {
			U[i][j] = -1
		}
	}
	dfs(0, -1, 0, 0)
	for i := int64(0); i < MAX_L-1; i++ {
		for v := int64(0); v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
			}
		}
	}
	scanner.Scan()
	q = scanner.Int64()
	scanner.Scan()
	k = scanner.Int64()
	k--
	for i := int64(0); i < q; i++ {
		scanner.Scan()
		x = scanner.Int64()
		scanner.Scan()
		y = scanner.Int64()
		x--
		y--
		fmt.Println(dist(x, k) + dist(k, y))
	}
}

// Translate the above Go code to C++ and end with comment "