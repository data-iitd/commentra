package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Number of nodes in the graph
var n int

// Adjacency list representation of the graph, where each node points to a list of edges
var g []map[int]int

// Array to store the answer for each edge
var ans []int

func main() {
	// Read the number of nodes
	n, _ = strconv.Atoi(readLine())

	// Initialize the adjacency list for the graph
	g = make([]map[int]int, n)
	for i := 0; i < n; i++ {
		g[i] = make(map[int]int)
	}

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		// Read the two endpoints of the edge, adjusting for 0-based indexing
		a, _ := strconv.Atoi(readLine())
		a--
		b, _ := strconv.Atoi(readLine())
		b--
		// Add the edge to both endpoints' adjacency lists
		g[a][b] = i
		g[b][a] = i
	}

	// Initialize the answer array to store results for each edge
	ans = make([]int, n-1)

	// Perform a depth-first search starting from node 0
	dfs(0, -1, -1)

	// Find the maximum value in the ans array
	max := 0
	for _, temp := range ans {
		max = max + temp
	}

	// Output the maximum value found
	fmt.Println(max)

	// Output the results for each edge
	for _, c := range ans {
		fmt.Println(c)
	}
}

// Depth-first search function to traverse the graph and assign colors to edges
func dfs(to, color, parents int) {
	k := 1 // Start coloring with color 1
	for e := range g[to] {
		// Skip the edge leading back to the parent node
		if e == parents {
			continue
		}
		// If the current color is the same as the edge color, increment it
		if k == color {
			k++
		}
		// Assign the color to the edge
		ans[g[to][e]] = k
		// Recursively call dfs for the connected node
		dfs(e, k, to)
		k++ // Increment color for the next edge
	}
}

// Read input from stdin
func readLine() string {
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

