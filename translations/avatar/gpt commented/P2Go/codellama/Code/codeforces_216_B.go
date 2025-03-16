
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
	line, _ := reader.ReadString('\n')
	fields := strings.Fields(line)
	ints := make([]int, len(fields))
	for i, field := range fields {
		ints[i], _ = strconv.Atoi(field)
	}
	return ints
}

func dfs(g map[int][]int, seen map[int]bool, i int) (int, int) {
	// Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
	// 'seen' keeps track of visited nodes to avoid cycles
	if seen[i] {
		// If the node has already been visited, return 0 nodes and 0 edges
		return 0, 0
	}
	seen[i] = true // Mark the current node as seen
	nodes := 1      // Count the current node
	edges := len(g[i]) // Count the edges connected to the current node
	for _, j := range g[i] {
		// Recursively visit all adjacent nodes
		x, y := dfs(g, seen, j)
		nodes += x // Accumulate the number of nodes found
		edges += y // Accumulate the number of edges found
	}
	return nodes, edges // Return the total count of nodes and edges
}

func solve() bool {
	// Main function to solve the problem
	line0, _ := reader.ReadString('\n')
	fields := strings.Fields(line0)
	n, _ := strconv.Atoi(fields[0])
	m, _ := strconv.Atoi(fields[1])
	g := make(map[int][]int) // Initialize the graph as a dictionary
	seen := make(map[int]bool) // Initialize a set to keep track of seen nodes
	for i := 1; i <= n; i++ {
		// Initialize each node's adjacency list as an empty set
		g[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		// Read each edge and add it to the graph (undirected)
		a, _ := reader.ReadString('\n')
		b, _ := reader.ReadString('\n')
		a, _ = strconv.Atoi(a)
		b, _ = strconv.Atoi(b)
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := 0 // Initialize the answer counter
	for i := 1; i <= n; i++ {
		// Iterate through each node to find connected components
		if !seen[i] {
			// If the node has not been seen, perform DFS
			nodes, edges := dfs(g, seen, i)
			// Check the conditions for counting valid components
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++ // Increment the answer if conditions are met
			}
		}
	}
	if (n - ans) % 2 == 1 {
		// Adjust the answer if the remaining nodes are odd
		ans++
	}
	fmt.Println(ans) // Output the final answer
	return true // Return True to indicate successful processing
}

var reader *bufio.Reader

func main() {
	// Initialize the reader
	reader = bufio.NewReader(os.Stdin)
	// Continuously solve the problem until EOF is reached
	for solve() {
	}
}

