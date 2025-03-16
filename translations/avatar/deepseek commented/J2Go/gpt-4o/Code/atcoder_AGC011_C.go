package main

import (
	"fmt"
)

type Main struct {
	graph     [][]int
	visited   []bool
	color     []int
	one       int64
	bipartite int64
	count     int64
	mujun     bool
}

func (m *Main) dfs(a, c int) int {
	if m.visited[a] { // If node is already visited
		if m.color[a] >= 0 && m.color[a] != c {
			m.mujun = true // Check if color conflict and set mujun flag
		}
		return 0 // Return 0 as we don't want to count this node again
	}
	m.visited[a] = true // Mark node as visited
	m.color[a] = c      // Assign color to the node
	total := 1          // Initialize total count for this component
	for _, b := range m.graph[a] { // Iterate through neighbors
		total += m.dfs(b, 1-c) // Recursively call dfs and accumulate total
	}
	return total // Return total count for this component
}

func (m *Main) run() {
	var n, mEdges int
	fmt.Scan(&n, &mEdges) // Read number of nodes and edges
	m.graph = make([][]int, n) // Initialize graph adjacency list
	for i := 0; i < n; i++ {
		m.graph[i] = []int{} // Initialize each node's adjacency list
	}
	for i := 0; i < mEdges; i++ { // Read each edge and add to graph
		var u, v int
		fmt.Scan(&u, &v) // Read node u and v
		u-- // Convert to 0-based index
		v-- // Convert to 0-based index
		m.graph[u] = append(m.graph[u], v) // Add edge u -> v
		m.graph[v] = append(m.graph[v], u) // Add edge v -> u
	}
	m.visited = make([]bool, n) // Initialize visited array
	m.color = make([]int, n)     // Initialize color array
	for i := range m.color {
		m.color[i] = -1 // Set all colors to -1 (uncolored)
	}
	m.one = 0 // Initialize one counter
	m.bipartite = 0 // Initialize bipartite counter
	m.count = 0 // Initialize component counter
	for i := 0; i < n; i++ { // Iterate through all nodes
		if m.visited[i] {
			continue // Skip if already visited
		}
		m.count++ // Increment component count
		m.mujun = false // Reset mujun flag
		kind := m.dfs(i, 0) // Perform DFS and get component size
		if kind == 1 {
			m.one++ // If component has exactly one node, increment one counter
		} else if !m.mujun {
			m.bipartite++ // If component is bipartite, increment bipartite counter
		}
	}
	total := m.one * (2*int64(n) - m.one) // Calculate total for components with exactly one node
	total += (m.count - m.one) * (m.count - m.one) // Calculate total for components with more than one node
	total += m.bipartite * m.bipartite // Add total for bipartite components
	fmt.Println(total) // Print the total number of valid configurations
}

func main() {
	m := &Main{}
	m.run() // Start the program
}

// <END-OF-CODE>
