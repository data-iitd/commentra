package main

import (
	"bufio"
	"fmt"
	"os"
)

// Step 2: Define global variables
// G is a slice of slices representing the graph.
var G [][]int
// used is a boolean slice to keep track of visited nodes.
var used []bool
// grundy is a slice to store the Grundy number of each node.
var grundy []int

// Step 3: Define the dfs function
// The function dfs is used to perform a depth-first search on the graph.
func dfs(v int) {
	// It marks the current node as visited.
	used[v] = true
	// It initializes the Grundy number of the current node to 0.
	grundy[v] = 0
	// It iterates through all the neighbors of the current node.
	for i := 0; i < len(G[v]); i++ {
		// If a neighbor has not been visited, it recursively calls dfs on that neighbor.
		if !used[G[v][i]] {
			dfs(G[v][i])
			// It updates the Grundy number of the current node by performing the XOR operation with (grundy[G[v][i]] + 1).
			grundy[v] ^= (grundy[G[v][i]] + 1)
		}
	}
}

// Step 4: Main function
func main() {
	// It reads the number of nodes N.
	var N int
	fmt.Scan(&N)

	// Initialize the graph, used, and grundy slices
	G = make([][]int, N)
	used = make([]bool, N)
	grundy = make([]int, N)

	// It reads the edges of the graph and constructs the adjacency list.
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < N-1; i++ {
		var x, y int
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}

	// It calls the dfs function starting from node 0.
	dfs(0)

	// It checks the Grundy number of the root node (node 0).
	if grundy[0] != 0 {
		// It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

