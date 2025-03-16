package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Adjacency list representation of the graph
var graph [][]int

// Array to track visited nodes
var visited []bool

// Array to store colors of nodes for bipartite checking
var color []int

// Counters for specific conditions
var one, bipartite, count int

// Flag to check if the graph is not bipartite
var mujun bool

// Depth-First Search (DFS) method to explore the graph
func dfs(a, c int) int {
	// If the node has already been visited
	if visited[a] {
		// Check for color conflict indicating the graph is not bipartite
		if color[a] >= 0 && color[a]!= c {
			mujun = true
		}
		return 0
	}
	// Mark the node as visited and assign it a color
	visited[a] = true
	color[a] = c
	total := 1 // Count the current node

	// Recursively visit all adjacent nodes with alternate color
	for _, b := range graph[a] {
		total += dfs(b, 1-c)
	}
	return total // Return the total count of nodes in this component
}

// Main execution method for the program
func main() {
	// Read number of nodes and edges
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)

	// Initialize the graph
	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}

	// Read edges and populate the graph
	for i := 0; i < m; i++ {
		u, v := 0, 0
		fmt.Fscan(reader, &u, &v)
		graph[u-1] = append(graph[u-1], v-1)
		graph[v-1] = append(graph[v-1], u-1)
	}

	// Initialize visited and color arrays
	visited = make([]bool, n)
	color = make([]int, n)
	for i := 0; i < n; i++ {
		color[i] = -1
	}

	// Initialize counters
	one = 0
	bipartite = 0
	count = 0

	// Iterate through all nodes to find connected components
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}
		count++ // Increment component count
		mujun = false // Reset bipartite flag
		kind := dfs(i, 0) // Perform DFS starting from node i

		// Update counters based on the results of DFS
		if kind == 1 {
			one++
		} else if!mujun {
			bipartite++
		}
	}

	// Calculate the total based on the counts of components
	total := one * (2*n - one)
	total += (count - one) * (count - one)
	total += bipartite * bipartite

	// Output the final result
	fmt.Println(total)
}

// 