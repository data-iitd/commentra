package main

import (
	"fmt"
)

const N = 100 // maximum number of vertices in the graph
const (
	WHITE = 0 // unvisited vertex
	GRAY  = 1 // vertex is being explored
	BLACK = 2 // vertex has been explored
)

var (
	M    [N][N]int // adjacency matrix
	n    int       // number of vertices
	color [N]int   // color of vertices
	d     [N]int   // discovery time
	f     [N]int   // finishing time
	tt    int      // time counter
)

// dfsVisit function sets the color, depth, and finishing time of a vertex
func dfsVisit(u int) {
	color[u] = GRAY // mark the current vertex as being explored
	tt++
	d[u] = tt      // record the discovery time
	for v := 0; v < n; v++ {
		if M[u][v] == 0 {
			continue // if there is no edge between u and v, skip
		}
		if color[v] == WHITE {
			dfsVisit(v) // recursively call dfsVisit for the neighbor v
		}
	}
	color[u] = BLACK // mark the current vertex as explored
	tt++
	f[u] = tt       // record the finishing time
}

// dfs function initializes the arrays and performs the DFS traversal
func dfs() {
	for i := 0; i < n; i++ {
		color[i] = WHITE // initialize all vertices as unvisited
	}
	tt = 0

	for u := 0; u < n; u++ {
		if color[u] == WHITE {
			dfsVisit(u) // call dfsVisit for the first unvisited vertex
		}
	}

	// print the results
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	fmt.Scan(&n) // read the number of vertices

	// initialize the adjacency matrix with zeros
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}

	// read the edges and fill the adjacency matrix
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u-- // convert to zero-based index
		for j := 0; j < k; j++ {
			fmt.Scan(&v)
			v-- // convert to zero-based index
			M[u][v] = 1
		}
	}

	// perform depth first search
	dfs()
}

// <END-OF-CODE>
