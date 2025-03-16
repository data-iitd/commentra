package main

import (
	"fmt"
	"math"
)

const (
	N   = 100000
	INF = 1000000
)

type Date struct {
	go    int
	back  int
	cost  int
}

var (
	n   int
	d   [N]int
	a   [500000]Date // Array to store the adjacency list and cost for each edge
)

func root(b int) {
	for i := 0; i < n; i++ { // Initialize the shortest distance array with infinite values
		d[i] = INF
	}

	d[0] = 0 // Set the shortest distance to the source vertex to 0

	flag := true // Variable to indicate if there are still vertices with updated shortest distances

	for flag { // While there are still vertices with updated shortest distances
		flag = false // Assume no vertices have updated shortest distances

		for i := 0; i < b; i++ { // Iterate through all the edges
			if a[i].cost+d[a[i].back] < d[a[i].go] { // If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
				d[a[i].go] = a[i].cost + d[a[i].back] // Update the shortest distance to the current vertex
				flag = true // Set the flag to indicate that there are still vertices with updated shortest distances
			}
		}
	}
}

func main() {
	var count int // Variable to keep track of the number of edges

	fmt.Scan(&n) // Read the number of vertices

	for i := 0; i < n; i++ { // Iterate through each vertex
		var u, k int
		fmt.Scan(&u, &k) // Read the number of edges and their destinations

		for j := 0; j < k; j++ { // Iterate through each edge
			a[count].back = u // Set the back pointer to the current vertex
			fmt.Scan(&a[count].go, &a[count].cost) // Read the destination vertex and the cost
			count++ // Increment the edge counter
		}
	}

	root(count) // Call the Dijkstra's algorithm function

	for i := 0; i < n; i++ { // Print the shortest distance from the source to each vertex
		fmt.Printf("%d %d\n", i, d[i])
	}
}

// <END-OF-CODE>
