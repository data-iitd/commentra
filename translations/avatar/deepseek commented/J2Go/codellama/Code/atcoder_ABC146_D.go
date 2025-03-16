package main

import (
	"fmt"
	"math"
)

var n int
var g [][]Edge // Step 1: Declare the graph as an adjacency list
var ans []int // Step 3: Declare the answer array to store edge colors

func main() {
	var sc = make([]int, 0)
	fmt.Scan(&n) // Read the number of nodes
	g = make([][]Edge, n) // Initialize the graph
	for i := 0; i < n; i++ {
		g[i] = make([]Edge, 0) // Initialize each node's adjacency list
	}
	for i := 0; i < n-1; i++ { // Step 2: Read and populate the graph
		var a, b int
		fmt.Scan(&a, &b) // Read node a
		g[a-1] = append(g[a-1], Edge{i, b - 1}) // Add edge from a to b
		g[b-1] = append(g[b-1], Edge{i, a - 1}) // Add edge from b to a
	}
	ans = make([]int, n-1) // Step 3: Initialize the answer array
	dfs(0, -1, -1) // Step 3: Call DFS with root node 0, initial color -1, and parent -1
	var max = 0 // Step 5: Initialize max to find the maximum color used
	for _, temp := range ans {
		max = int(math.Max(float64(max), float64(temp))) // Step 5: Find the maximum color used
	}
	fmt.Println(max) // Step 5: Print the maximum color used
	for _, c := range ans {
		fmt.Println(c) // Step 5: Print the colors assigned to each edge
	}
}

func dfs(to, color, parent int) { // Step 4: Define the DFS function
	k := 1 // Initialize the color counter
	for _, e := range g[to] { // Iterate through the adjacency list of the current node
		if e.To == parent {
			continue // Skip if the neighbor is the parent
		}
		if k == color {
			k++ // Ensure the color is not the same as the parent's color
		}
		ans[e.Id] = k // Assign the color to the edge
		dfs(e.To, k, to) // Recursively call DFS for the neighbor
		k++ // Increment the color counter for the next edge
	}
}

type Edge struct { // Define the Edge class
	Id  int
	To  int
}

// 