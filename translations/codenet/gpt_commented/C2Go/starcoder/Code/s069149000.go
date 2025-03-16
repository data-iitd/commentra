package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for infinity
const INF = 100000

// Define the maximum number of vertices
const MAX = 101

// Define a constant for a non-existent parent
const NIL = -6

// Define color for unvisited nodes
const WHITE = 0

// Define color for nodes being visited
const GRAY = 1

// Define color for visited nodes
const BLACK = 2

// Adjacency matrix to represent the graph
var G [MAX][MAX]int

// Number of vertices in the graph
var n int

// Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
func prim(){
	var i, j int
	var d [MAX]int
	var pi [MAX]int
	var color [MAX]int
	var min, u, v, sum int

	// Initialize the arrays
	for i = 0; i < n; i++{
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	d[0] = 0

	// Main loop of Prim's algorithm
	for{
		min = INF
		u = NIL

		// Find the vertex with the minimum distance that hasn't been visited
		for i = 0; i < n; i++{
			if color[i]!= BLACK && d[i] < min{
				min = d[i]
				u = i
			}
		}

		// If no vertex is found, break out of the loop
		if u == NIL{
			break
		}

		color[u] = BLACK

		// Update the distances and parents for adjacent vertices
		for v = 0; v < n; v++{
			if color[v]!= BLACK && G[u][v]!= INF{
				// If the edge weight is less than the current known distance
				if d[v] > G[u][v]{
					d[v] = G[u][v]
					pi[v] = u
					color[v] = GRAY
				}
			}
		}
	}

	// Calculate the total weight of the MST
	for i = 0; i < n; i++{
		if pi[i]!= NIL{
			sum += G[i][pi[i]]
		}
	}

	// Print the total weight of the Minimum Spanning Tree
	fmt.Println(sum)
}

// Main function to read input and execute Prim's algorithm
func main(){
	var e int
	var i, j int

	// Read the number of vertices
	fmt.Scanf("%d", &n)

	// Read the adjacency matrix representation of the graph
	for i = 0; i < n; i++{
		for j = 0; j < n; j++{
			fmt.Scanf("%d", &e)
			if e == -1{
				G[i][j] = INF
			} else {
				G[i][j] = e
			}
		}
	}

	// Call the Prim's algorithm function to find the MST
	prim()
}

