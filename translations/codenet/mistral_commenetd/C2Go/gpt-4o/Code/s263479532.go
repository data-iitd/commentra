package main

import (
	"fmt"
	"math"
)

const (
	MAX = 100
	INF = math.MaxInt32
	NIL = -1
	WHITE = 0
	BLACK = 2
)

func prim(n int, G [][]int) int { // Function to implement Prim's Algorithm
	var u, v, mincost, sum int
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)

	for i := 0; i < n; i++ { // Initialize the arrays d, pi, and color with initial values
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	d[0] = 0 // Set the initial distance of the first vertex to 0

	for {
		mincost = INF // Initialize mincost to the maximum possible value
		for i := 0; i < n; i++ { // Find the unvisited vertex with the minimum distance
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == INF { // If all vertices have been visited, break the loop
			break
		}

		color[u] = BLACK // Mark the current vertex as visited

		for v = 0; v < n; v++ { // Update the distances of adjacent vertices
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	for i := 0; i < n; i++ { // Calculate the total weight of the MST
		if d[i] != INF {
			sum += d[i]
		}
	}

	return sum
}

func main() {
	var n int
	fmt.Scan(&n) // Read the number of vertices from the user
	G := make([][]int, n)
	for i := 0; i < n; i++ { // Initialize the 2D array G with input values
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	fmt.Println(prim(n, G)) // Call the prim function and print the result
}

// <END-OF-CODE>
