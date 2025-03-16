package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define long long as int for convenience
type int int64

// Macros for loop and container operations
func rep(i int, n int) {
	for i := 0; i < n; i++ {

// Constants for maximum levels, infinity, and modulo
const (
	INF = 1145141919
	MOD = 1000000007
	MAX_L = 22
)

// Global variables
var N int // Number of nodes in the tree
var G [100000][]P // Adjacency list representation of the tree
var U [MAX_L][100000]int // U for storing ancestors, R for depth
var L [100000]int // L for storing the distance from the root

// Depth-first search to initialize ancestor and depth information
func dfs(x int, p int, r int, l int) {
	U[0][x] = p // Set the parent of the current node
	R[x] = r // Set the depth of the current node
	L[x] = l // Set the distance from the root to the current node
	for _, pp := range G[x] { // Iterate through all adjacent nodes
		t := pp._1 // Get the adjacent node
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+pp._2) // Recursive DFS call for the child node
	}
}

// Function to find the lowest common ancestor (LCA) of two nodes
func lca(a int, b int) int {
	if R[a] > R[b] {
		swap(a, b) // Ensure a is the deeper node
	}
	for k := 0; k < MAX_L; k++ { // Adjust b to the same depth as a
		if (R[a] - R[b]) >> k & 1 {
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
func dist(x int, y int) int {
	g := lca(x, y) // Find the LCA of x and y
	return L[x] + L[y] - 2*L[g] // Calculate the distance using LCA
}

func main() {
	// Optimize input/output
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of nodes
	N, _ = strconv.Atoi(readLine(in))

	// Read the edges of the tree
	for i := 0; i < N-1; i++ {
		a, b, c := readThree(in)
		a--
		b--
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
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

	Q, K := readTwo(in) // Number of queries and a specific node K
	K-- // Convert K to 0-based indexing

	// Process each query
	for i := 0; i < Q; i++ {
		x, y := readTwo(in) // Nodes for which distance is to be calculated
		x--
		y--
		// Output the total distance from x to K and K to y
		fmt.Printf("%d\n", dist(x, K)+dist(K, y))
	}
}

// Read a single line from the input
func readLine(in *bufio.Reader) string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

// Read three integers from the input
func readThree(in *bufio.Reader) (int, int, int) {
	line := readLine(in)
	a, b, c := strings.Split(line, " "), 0, 0
	N := len(a)
	a[N-1] = a[N-1][:len(a[N-1])-1]
	b, _ = strconv.Atoi(a[0])
	c, _ = strconv.Atoi(a[1])
	d, _ = strconv.Atoi(a[2])
	return b, c, d
}

// Read two integers from the input
func readTwo(in *bufio.Reader) (int, int) {
	line := readLine(in)
	a, b := strings.Split(line, " "), 0
	N := len(a)
	a[N-1] = a[N-1][:len(a[N-1])-1]
	b, _ = strconv.Atoi(a[0])
	c, _ = strconv.Atoi(a[1])
	return b, c
}

// Swap two integers
func swap(a *int, b *int) {
	*a, *b = *b, *a
}

// END-OF-CODE
