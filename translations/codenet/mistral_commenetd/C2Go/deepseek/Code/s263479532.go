package main

import (
	"fmt"
)

const (
	MAX  = 100
	INF  = 999999
	NIL  = -1
	WHITE = 0
	BLACK = 2
)

func prim() int { // Function to implement Prim's Algorithm
	var u, i, v, mincost, sum int
	var d = make([]int, n)
	var pi = make([]int, n)
	var color = make([]int, n)

	for u = 0; u < n; u++ { // Initialize the arrays d, pi, and color with initial values
		d[u] = INF
		pi[u] = NIL
		color[u] = WHITE
	}

	d[0] = 0 // Set the initial distance of the first vertex to 0

	for { // The main loop of Prim's Algorithm
		mincost = INF // Initialize mincost to the maximum possible value

		for i = 0; i < n; i++ { // Find the unvisited vertex with the minimum distance
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == INF {
			break // If all vertices have been visited, break the loop
		}

		color[u] = BLACK // Mark the current vertex as visited

		for v = 0; v < n; v++ { // Update the distances of adjacent vertices
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	for i = 0; i < n; i++ { // Calculate and print the total weight of the MST
		if d[i] != INF {
			sum += d[i]
		}
	}

	return sum
}

var n int
var G [MAX][MAX]int

func main() {
	var i, j int

	fmt.Scan(&n) // Read the number of vertices from the user
	for i = 0; i < n; i++ { // Initialize the 2D array G with input values
		for j = 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	fmt.Println(prim()) // Call the prim function and print the result
}

