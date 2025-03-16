package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	N   = 100000
	INF = 1000000
)

// Define a structure to store connection details
type Date struct {
	go   int
	back int
	cost int
}

// Define the maximum number of nodes and the distance array
var n int
var d [N]int
var a [500000]Date

// Declare the root function
func root(b int)

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

// Function to initialize distances and update them based on connections
func root(b int) {
	var i, flag int

	// Initialize all distances to INF except the root node (node 0)
	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0

	// Use a while loop to update distances based on connections
	for flag != 0 {
		flag = 0
		for i = 0; i < b; i++ {
			if a[i].cost + d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = 1
			}
		}
	}
}

