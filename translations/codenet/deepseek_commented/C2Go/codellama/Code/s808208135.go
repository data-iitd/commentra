package main

import (
	"fmt"
)

// Define a structure to store connection details
type Date struct {
	go, back, cost int
}

// Define the maximum number of nodes and the distance array
var n int
var d [100000]int
var a [500000]Date

// Declare the root function
func root(b int) {
	// Initialize all distances to INF except the root node (node 0)
	for i := 0; i < n; i++ {
		d[i] = 100000
	}
	d[0] = 0

	// Use a while loop to update distances based on connections
	flag := 1
	for i := 0; i < b; i++ {
		if a[i].cost+d[a[i].back] < d[a[i].go] {
			d[a[i].go] = a[i].cost + d[a[i].back]
			flag = 1
		}
	}
}

func main() {
	// Declare variables for iteration and input
	var i, j, k, u, count int

	// Read the number of nodes
	fmt.Scan(&n)

	// Read each node's connections and store them in the array 'a'
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)
		for j = 0; j < k; j++ {
			a[count].back = u
			fmt.Scan(&a[count].go, &a[count].cost)
			count++
		}
	}

	// Call the root function to initialize distances
	root(count)

	// Print the shortest distances from the root node to each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

