package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int64 // An edge has source, destination, and cost.
}

type Graph struct {
	vcnt, ecnt int // Number of vertices and edges in the graph.
	e          []Edge // Array to store edges.
	id         []int // Array to store the index of each vertex in the sorted edge list.
}

// Function to read the graph from the standard input.
func readGraph() Graph {
	var n int64
	fmt.Scan(&n)

	g := Graph{
		vcnt: int(n),
		ecnt: int(2*n - 2),
		e:    make([]Edge, 0, 2*n-2),
		id:   make([]int, n+1),
	}

	for i := int64(0); i < n-1; i++ {
		var x, y, c int64
		fmt.Scan(&x, &y, &c)
		g.e = append(g.e, Edge{s: x, g: y, c: c})
		g.e = append(g.e, Edge{s: y, g: x, c: c})
	}

	// Sort the edges based on their source vertex.
	sort.Slice(g.e, func(i, j int) bool {
		if g.e[i].s != g.e[j].s {
			return g.e[i].s < g.e[j].s
		}
		return g.e[i].g < g.e[j].g
	})

	// Initialize the id array.
	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < int64(i) {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt

	return g
}

// Function to find the diameter of the tree using DFS algorithm.
func dfs(g Graph, s int, tyokkeitemp []int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + int(g.e[i].c)
			dfs(g, int(g.e[i].g), tyokkeitemp)
		}
	}
}

func findDiameter(g Graph) int {
	tyokkeitemp := make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1 // Initialize the root vertex depth to 1.
	dfs(g, 0, tyokkeitemp)

	// Find the maximum depth.
	M, Mi := 0, 0
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}

	return M - 1 // Return the diameter which is the maximum depth minus 1.
}

// Main function to read the graph and print the diameter.
func main() {
	g := readGraph()
	fmt.Println(findDiameter(g))
}
