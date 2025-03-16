package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Adjacency list to represent the graph
var graph [][]int

// Array to keep track of visited nodes
var visited []bool

// Array to store colors for bipartite check
var color []int

// Counter for components with exactly one node
var one int

// Counter for bipartite components
var bipartite int

// Counter for total number of connected components
var count int

// Flag to check for non-bipartite conditions
var mujun bool

// Depth-first search method to color nodes and check for bipartiteness
func dfs(a int, c int) int {
	if visited[a] { // If node is already visited
		if color[a] >= 0 && color[a]!= c { // Check if color conflict and set mujun flag
			mujun = true
		}
		return 0 // Return 0 as we don't want to count this node again
	}
	visited[a] = true // Mark node as visited
	color[a] = c // Assign color to the node
	total := 1 // Initialize total count for this component
	for _, b := range graph[a] { // Iterate through neighbors
		total += dfs(b, 1-c) // Recursively call dfs and accumulate total
	}
	return total // Return total count for this component
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &m)
	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		u, v := 0, 0
		fmt.Fscan(reader, &u)
		fmt.Fscan(reader, &v)
		graph[u-1] = append(graph[u-1], v-1)
		graph[v-1] = append(graph[v-1], u-1)
	}
	visited = make([]bool, n)
	color = make([]int, n)
	for i := 0; i < n; i++ {
		color[i] = -1
	}
	one = 0
	bipartite = 0
	count = 0
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}
		count++
		mujun = false
		kind := dfs(i, 0)
		if kind == 1 {
			one++
		} else if!mujun {
			bipartite++
		}
	}
	total := one * (2*n - one)
	total += (count - one) * (count - one)
	total += bipartite * bipartite
	fmt.Println(total)
}

