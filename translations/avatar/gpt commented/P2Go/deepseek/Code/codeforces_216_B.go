package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInts() []int {
	// Reads a line of input, splits it into components, and converts them to integers
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		ints[i] = num
	}
	return ints
}

func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
	// Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
	// 'seen' keeps track of visited nodes to avoid cycles
	if seen[i] {
		// If the node has already been visited, return 0 nodes and 0 edges
		return 0, 0
	}
	seen[i] = true  // Mark the current node as seen
	nodes := 1  // Count the current node
	edges := len(g[i])  // Count the edges connected to the current node
	for j := range g[i] {
		// Recursively visit all adjacent nodes
		x, y := dfs(g, seen, j)
		nodes += x  // Accumulate the number of nodes found
		edges += y  // Accumulate the number of edges found
	}
	return nodes, edges  // Return the total count of nodes and edges
}

func solve() bool {
	// Main function to solve the problem
	line0 := readInts()
	if len(line0) == 0 {
		return false
	}
	n, m := line0[0], line0[1]  // Unpack the number of nodes (n) and edges (m)
	g := make(map[int]map[int]bool)  // Initialize the graph as a map
	seen := make(map[int]bool)  // Initialize a map to keep track of seen nodes
	for i := 1; i <= n; i++ {
		// Initialize each node's adjacency list as an empty set
		g[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		// Read each edge and add it to the graph (undirected)
		edge := readInts()
		a, b := edge[0], edge[1]
		g[a][b] = true
		g[b][a] = true
	}
	ans := 0  // Initialize the answer counter
	for i := 1; i <= n; i++ {
		// Iterate through each node to find connected components
		if !seen[i] {
			// If the node has not been seen, perform DFS
			nodes, edges := dfs(g, seen, i)
			// Check the conditions for counting valid components
			if nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges {
				ans += 1  // Increment the answer if conditions are met
			}
		}
	}
	if (n - ans) % 2 == 1 {
		// Adjust the answer if the remaining nodes are odd
		ans += 1
	}
	fmt.Println(ans)  // Output the final answer
	return true  // Return True to indicate successful processing
}

func main() {
	// Continuously solve the problem until EOF is reached
	for solve() {}
}

