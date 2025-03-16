package main

import (
	"fmt"
)

type Main struct {
	count int
	seen  []bool
	graph [][]int
}

const (
	path = 0
	cycle = 1
)

// Depth-first search method to detect cycles
func (m *Main) dfs(child, par int) int {
	if m.seen[child] {
		return cycle // If child is already seen, return cycle
	}
	m.seen[child] = true // Mark the child as seen
	for _, i := range m.graph[child] { // Iterate over neighbors of child
		if i != par { // Avoid going back to parent
			m.count++ // Increment count for each edge traversed
			if m.dfs(i, child) == cycle {
				return cycle // If cycle is detected, return cycle
			}
		}
	}
	return path // Return path if no cycle is detected
}

// Main function to handle input and output
func main() {
	var m, n int
	fmt.Scan(&m, &n) // Number of nodes and edges
	ft := Main{
		graph: make([][]int, m+1),
		seen:  make([]bool, m+1),
	}
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Read edge from and to
		ft.graph[x] = append(ft.graph[x], y) // Add edge to adjacency list of node x
		ft.graph[y] = append(ft.graph[y], x) // Add edge to adjacency list of node y
	}
	toremove := 0 // Initialize removal count
	for i := 1; i <= m; i++ {
		if !ft.seen[i] { // If node is not visited
			ft.count = 0 // Reset count for each DFS call
			if ft.dfs(i, 0) == cycle { // If cycle is detected
				if ft.count%2 == 1 {
					toremove++ // Increment removal count if cycle length is odd
				}
			}
		}
	}
	if (m - toremove)%2 == 1 {
		toremove++ // Adjust removal count if total nodes minus removed nodes is odd
	}
	fmt.Println(toremove) // Print the final removal count
}

// <END-OF-CODE>
