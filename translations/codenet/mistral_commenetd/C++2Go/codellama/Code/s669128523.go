/*
 depth first search algorithm implementation in Go
 not lying in the stack
 */
package main

import "fmt"

const (
	N = 100 /* maximum number of vertices in the graph */
	WHITE = 0 /* unvisited vertex */
	GRAY = 1 /* vertex is being explored */
	BLACK = 2 /* vertex has been explored */
)

var (
	M [N][N]int /* adjacency matrix and number of vertices */
	n int
	color [N]int /* arrays for depth first search */
	d [N]int
	f [N]int
	tt int
)

/*
 depth first search visit function
 sets the color, depth and finishing time of a vertex
 */
func dfs_visit(u int) {
	var v int
	color[u] = GRAY /* mark the current vertex as being explored */
	d[u] = tt + 1 /* record the discovery time */
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue /* if there is no edge between u and v, skip */
		}
		if color[v] == WHITE {
			dfs_visit(v) /* recursively call dfs_visit for the neighbor v */
		}
	}
	color[u] = BLACK /* mark the current vertex as explored */
	f[u] = tt + 1 /* record the finishing time */
}

/*
 depth first search function
 initializes the arrays and performs the DFS traversal
 */
func dfs() {
	var u int
	for i := 0; i < n; i++ {
		color[i] = WHITE /* initialize all vertices as unvisited */
	}
	tt = 0

	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfs_visit(u) /* call dfs_visit for the first unvisited vertex */
		}
	}

	/* print the results */
	for i := 0; i < n; i++ {
		fmt.Println(i + 1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	fmt.Scan(&n) /* read the number of vertices */

	/* initialize the adjacency matrix with zeros */
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}

	/* read the edges and fill the adjacency matrix */
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Scan(&v)
			v--
			M[u][v] = 1
		}
	}

	/* perform depth first search */
	dfs()

}

