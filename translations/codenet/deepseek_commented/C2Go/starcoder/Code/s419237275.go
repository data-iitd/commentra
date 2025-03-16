<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// Global variables
var (
	n int
	A [200][200]int
	color [200]int
	d [200]int
	f [200]int
	TT int
)

// Function prototypes
func aaaaa()
func bbbbb(k int)

func main() {
	var (
		u, k, v int
	)
=======
// Constants
const (
	N = 200
	SHIRO = 0
	HAI = 1
	KURO = 2
)

// Global variables
var (
	n int
	A [N][N]int
	color [N]int
	d [N]int
	f [N]int
	TT int
)

func main() {
	var u, k, v int
	var i, j int
	var line string
	var err error
>>>>>>> 98c87cb78a (data updated)

	// Read the number of nodes
	fmt.Scanf("%d", &n)

	// Initialize the adjacency matrix to zero
<<<<<<< HEAD
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
=======
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
>>>>>>> 98c87cb78a (data updated)
			A[i][j] = 0
		}
	}

	// Read the edges for each node and update the adjacency matrix
<<<<<<< HEAD
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u--
		for j := 0; j < k; j++ {
=======
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u--
		for j = 0; j < k; j++ {
>>>>>>> 98c87cb78a (data updated)
			fmt.Scanf("%d", &v)
			v--
			A[u][v] = 1
		}
	}

	// Perform DFS and print the results
	aaaaa()

<<<<<<< HEAD
	return
=======
	// Print the discovery and finish times for each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i + 1, d[i], f[i])
	}
>>>>>>> 98c87cb78a (data updated)
}

// Depth-First Search (DFS) function
func aaaaa() {
<<<<<<< HEAD
	var (
		u, i int
	)

	// Initialize all nodes to "SHIRO" (unvisited)
	for i = 0; i < n; i++ {
		color[i] = 0
=======
	var u, i int

	// Initialize all nodes to "SHIRO" (unvisited)
	for i = 0; i < n; i++ {
		color[i] = SHIRO
>>>>>>> 98c87cb78a (data updated)
	}

	// Set the time counter to zero
	TT = 0

	// Iterate over all nodes and perform DFS if the node is "SHIRO"
	for u = 0; u < n; u++ {
<<<<<<< HEAD
		if color[u] == 0 {
			bbbbb(u)
		}
	}

	// Print the discovery and finish times for each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i + 1, d[i], f[i])
	}
=======
		if color[u] == SHIRO {
			bbbbb(u)
		}
	}
>>>>>>> 98c87cb78a (data updated)
}

// Recursive DFS function
func bbbbb(k int) {
<<<<<<< HEAD
	var (
		v int
	)

	// Set the current node's color to "HAI" (currently in the recursion stack)
	color[k] = 1
=======
	var v int

	// Set the current node's color to "HAI" (currently in the recursion stack)
	color[k] = HAI
>>>>>>> 98c87cb78a (data updated)
	// Increment the time counter and record the discovery time
	TT++
	d[k] = TT

	// Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue
		}
<<<<<<< HEAD
		if color[v] == 0 {
=======
		if color[v] == SHIRO {
>>>>>>> 98c87cb78a (data updated)
			bbbbb(v)
		}
	}

	// Set the current node's color to "KURO" (fully processed)
<<<<<<< HEAD
	color[k] = 2
=======
	color[k] = KURO
>>>>>>> 98c87cb78a (data updated)
	// Record the finish time
	f[k] = TT + 1
}

