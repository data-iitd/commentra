package main

import (
	"fmt"
)

const (
	MAX   = 101
	WHITE = 0
	BLACK = 2
	GRAY  = 1
)

var (
	time  int
	n     int
	g     [MAX][MAX]int // adjacency matrix
	d     [MAX]int      // depth array
	f     [MAX]int      // finish array
	color [MAX]int      // color array
)

func visit(u int) {
	color[u] = GRAY // mark the current vertex as 'gray'
	time++
	d[u] = time    // assign depth value to the current vertex

	for i := 0; i < n; i++ { // iterate through all the adjacent vertices of 'u'
		if g[u][i] == 0 { // if there is no edge between 'u' and 'i'
			continue
		}
		if color[i] == WHITE { // if 'i' is not yet visited
			visit(i) // recursively call DFS on 'i'
		}
	}

	color[u] = BLACK // mark the current vertex as 'black'
	time++
	f[u] = time // assign finish value to the current vertex
}

func dfs() {
	for i := 0; i < n; i++ { // iterate through all the vertices in the graph
		if color[i] == WHITE { // if 'i' is not yet visited
			visit(i) // recursively call DFS on 'i'
		}
	}

	for i := 0; i < n; i++ { // print the depth, finish, and vertex number for each vertex
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var x, y, z int

	fmt.Scan(&n) // read the number of vertices in the graph

	for i := 0; i < n; i++ { // iterate through each vertex in the graph
		fmt.Scan(&x, &y) // read the number of edges and their destinations for the current vertex

		for j := 0; j < y; j++ { // iterate through all the edges for the current vertex
			fmt.Scan(&z) // read the destination vertex for the current edge
			g[x-1][z-1] = 1 // mark that there is an edge between 'x' and 'z'
		}
	}

	dfs() // call DFS function to perform DFS on the entire graph
}

// <END-OF-CODE>
