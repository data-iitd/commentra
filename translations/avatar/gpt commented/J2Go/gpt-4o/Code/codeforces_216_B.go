package main

import (
	"fmt"
)

type Graph struct {
	adjacencyList [][]int
	seen          []bool
	count         int
}

const (
	path  = 0
	cycle = 1
)

// Depth-First Search (DFS) method to explore the graph
func (g *Graph) dfs(child, par int) int {
	if g.seen[child] {
		return cycle
	}
	g.seen[child] = true

	for _, i := range g.adjacencyList[child] {
		if i != par {
			g.count++ // Increment the count of nodes visited
			if g.dfs(i, child) == cycle {
				return cycle // Check for cycles
			}
		}
	}
	return path
}

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	// Create an instance of Graph
	graph := Graph{
		adjacencyList: make([][]int, m+1),
		seen:          make([]bool, m+1),
	}

	// Read the edges and populate the graph
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		graph.adjacencyList[x] = append(graph.adjacencyList[x], y)
		graph.adjacencyList[y] = append(graph.adjacencyList[y], x)
	}

	// Variable to count the number of nodes to remove
	toremove := 0

	// Iterate through all nodes to check for unvisited nodes
	for i := 1; i <= m; i++ {
		if !graph.seen[i] {
			graph.count = 0 // Reset count for the new component
			if graph.dfs(i, 0) == cycle {
				if graph.count%2 == 1 {
					toremove++
				}
			}
		}
	}

	// Adjust the number of nodes to remove if the remaining nodes are odd
	if (m - toremove)%2 == 1 {
		toremove++
	}

	// Output the result: number of nodes to remove
	fmt.Println(toremove)
}

// <END-OF-CODE>
