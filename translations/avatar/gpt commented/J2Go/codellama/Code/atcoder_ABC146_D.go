package main

import (
	"fmt"
	"math"
)

// Number of nodes in the graph
var n int
// Adjacency list representation of the graph, where each node points to a list of edges
var g [][]Edge
// Array to store the answer for each edge
var ans []int

func main() {
	// Create a Scanner object for input
	sc := new(Scanner)

	// Read the number of nodes
	n = sc.nextInt()

	// Initialize the adjacency list for the graph
	g = make([][]Edge, n)
	for i := 0; i < n; i++ {
		g[i] = make([]Edge, 0)
	}

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		// Read the two endpoints of the edge, adjusting for 0-based indexing
		a := sc.nextInt() - 1
		b := sc.nextInt() - 1
		// Add the edge to both endpoints' adjacency lists
		g[a] = append(g[a], Edge{i, b})
		g[b] = append(g[b], Edge{i, a})
	}

	// Initialize the answer array to store results for each edge
	ans = make([]int, n-1)

	// Perform a depth-first search starting from node 0
	dfs(0, -1, -1)

	// Find the maximum value in the ans array
	max := 0
	for _, temp := range ans {
		max = int(math.Max(float64(max), float64(temp)))
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
	for _, e := range g[to] {
		// Skip the edge leading back to the parent node
		if e.To == parents {
			continue
		}
		// If the current color is the same as the edge color, increment it
		if k == color {
			k++
		}
		// Assign the color to the edge
		ans[e.Id] = k
		// Recursively call dfs for the connected node
		dfs(e.To, k, to)
		k++ // Increment color for the next edge
	}
}

// Class to represent an edge in the graph
type Edge struct {
	Id   int
	To   int
}

// Scanner class to read input
type Scanner struct {
}

func (s *Scanner) nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

// END-OF-CODE
