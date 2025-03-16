package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare a graph represented as an adjacency list
var G [100000][]int
// Array to track visited nodes during DFS
var used [100000]bool
// Array to store the Grundy values for each node
var grundy [100000]int

// Depth-First Search (DFS) function to compute Grundy values
func dfs(v int){
	// Mark the current node as visited
	used[v] = true
	// Initialize the Grundy value for the current node
	grundy[v] = 0
	
	// Iterate through all adjacent nodes
	for i := 0; i < len(G[v]); i++{
		// If the adjacent node has not been visited
		if!used[G[v][i]]{
			// Recursively perform DFS on the adjacent node
			dfs(G[v][i])
			// Update the Grundy value using the Grundy value of the child node
			grundy[v] ^= (grundy[G[v][i]] + 1)
		}
	}
}

func main(){
	// Read the number of nodes in the graph
	var N int
	fmt.Scanf("%d\n", &N)
	
	// Read the edges of the graph
	for i := 0; i < N-1; i++{
		var x, y int
		fmt.Scanf("%d %d\n", &x, &y)
		// Convert to zero-based indexing
		x--
		y--
		// Add the edge to the adjacency list
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}
	
	// Start DFS from the root node (node 0)
	dfs(0)
	
	// Determine the winner based on the Grundy value of the root node
	if grundy[0]!= 0{
		fmt.Println("Alice") // Alice wins if Grundy value is non-zero
	}else{
		fmt.Println("Bob")   // Bob wins if Grundy value is zero
	}
}

