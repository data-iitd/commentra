
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
func dfs(v int){
	// It marks the current node as visited.
	used[v] = true
	// It initializes the Grundy number of the current node to 0.
	grundy[v] = 0
	// It iterates through all the neighbors of the current node.
	for _, u := range G[v]{
		// If a neighbor has not been visited, it recursively calls dfs on that neighbor.
		if!used[u]{
			dfs(u)
			// It updates the Grundy number of the current node by performing the XOR operation with (grundy[u] + 1).
			grundy[v] ^= (grundy[u]+1)
		}
	}
}

// Step 4: Main function
func main() {
	// It reads the number of nodes N from standard input.
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
	// It constructs the adjacency list G.
	G = make([][]int, N)
	for i := 0; i < N-1; i++ {
		x, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
		y, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	// It initializes the used and grundy slices.
	used = make([]bool, N)
	grundy = make([]int, N)
	// It calls the dfs function starting from node 0.
	dfs(0)
	// It checks the Grundy number of the root node (node 0).
	if grundy[0]!= 0 {
		// It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}
