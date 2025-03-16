

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the number of nodes: ")
	n, _ := strconv.Atoi(read(reader))

	A := make([][]int, n)
	for i := 0; i < n; i++ {
		A[i] = make([]int, n)
	}

	// Read the adjacency matrix from the user
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the number of neighbors for node %d: ", i+1)
		k, _ := strconv.Atoi(read(reader))
		for j := 0; j < k; j++ {
			fmt.Printf("Enter the neighbor index: ")
			v, _ := strconv.Atoi(read(reader))
			A[i][v-1] = 1 // Store the edge weight (assumed to be 1) in the adjacency matrix
		}
	}

	aaaaa(n, A) // Call the function aaaaa() to perform the required computation
}

func aaaaaa(n int, A [][]int) {
	color := make([]int, n)
	d := make([]int, n)
	f := make([]int, n)

	var TT int

	// Initialize all nodes with color SHIRO (white)
	for i := 0; i < n; i++ {
		color[i] = SHIRO
	}

	// Perform Depth First Search (DFS) from each unvisited node
	for u := 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbbb(u, n, A, color, d, f, &TT)
		}
	}

	// Print the results
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
		fmt.Printf("Node %d is visited at time %d and its finishing time is %d.\n", i+1, d[i], f[i])
	}
}

func bbbbbbb(k int, n int, A [][]int, color []int, d []int, f []int, TT *int) {
	var v int
	color[k] = HAI // Mark the current node as visited (gray)
	*TT++         // Increment the time variable TT
	d[k] = *TT    // Set the discovery time for the current node

	// Explore all neighbors of the current node
	for v = 0; v < n; v++ {
		if A[k][v] == 1 && color[v] == SHIRO { // If the neighbor is unvisited
			bbbbbb(v, n, A, color, d, f, TT) // Recursively call the function bbbbbbb() for the neighbor
		}
	}

	// Mark the current node as finished (black)
	color[k] = KURO
	f[k] = *TT + 1 // Set the finishing time for the current node
}

func read(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

