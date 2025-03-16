

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Define the structure for the edge and graph.
type Edge struct {
	s, g, c int
}
type Graph struct {
	vcnt, ecnt int
	e           []Edge
	id          []int
}

// Comparison function for sort.Slice to sort edges based on their source vertex.
func (e Edge) Less(i, j int) bool {
	if e[i].s < e[j].s {
		return true
	}
	if e[i].s > e[j].s {
		return false
	}
	if e[i].g < e[j].g {
		return true
	}
	return false
}

// Function to find the diameter of the tree using DFS algorithm.
// *tyokkeitemp is an array to store the depth of each vertex from the root.
func tyokkeidfs(s int, tyokkeitemp []int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g, tyokkeitemp)
		}
	}
}
func tyokkei() int {
	// Allocate memory for tyokkeitemp array.
	tyokkeitemp := make([]int, g.vcnt+10)
	// Initialize the root vertex depth to 1.
	tyokkeitemp[0] = 1
	// Perform DFS from the root vertex.
	tyokkeidfs(0, tyokkeitemp)
	// Find the maximum depth.
	M, Mi := 0, 0
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	// Return the diameter which is the maximum depth minus 1.
	return M - 1
}

// Main function to read the graph and print the diameter.
func main() {
	// Read the graph from the standard input.
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	g.vcnt = n
	g.ecnt = 2*n - 2
	g.e = make([]Edge, g.ecnt+10)
	g.id = make([]int, g.vcnt+10)
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &x, &y, &c)
		// Add an edge from x to y and y to x with the given cost.
		g.e[i].s = x
		g.e[i].g = y
		g.e[i].c = c
		g.e[i+g.ecnt].s = y
		g.e[i+g.ecnt].g = x
		g.e[i+g.ecnt].c = c
	}
	// Sort the edges using sort.Slice.
	sort.Slice(g.e, func(i, j int) bool {
		return g.e[i].Less(g.e[j])
	})
	// Set the number of edges.
	g.ecnt *= 2
	// Initialize the id array.
	p := 0
	for i := 0; i < g.vcnt; i++ {
		// Find the index of the current vertex in the sorted edge list.
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	// Set the last index as a sentinel.
	g.id[g.vcnt] = g.ecnt
	// Print the diameter of the tree.
	fmt.Println(tyokkei())
}

