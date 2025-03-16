package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for the number of nodes (n) and edges (m)
	var n, m int

	// Read the number of nodes and edges from standard input
	fmt.Scanf("%d%d", &n, &m)

	// Initialize an array to track connections (r0) and set all values to false
	r0 := make([]bool, n)

	// Initialize an array to store nodes connected to node n (r1) and a counter for it
	r1 := make([]int, n)
	var nr1 int

	// Process each edge input
	for i := 0; i < m; i++ {
		var a, b int

		// Read the endpoints of the edge
		fmt.Scanf("%d%d", &a, &b)

		// Ensure a is the smaller node and b is the larger node
		if a > b {
			a, b = b, a
		}

		// Mark the connection from node a to node b in r0
		if a == 1 {
			r0[b-1] = true
		}

		// If b is the last node (n), store a-1 in r1
		if b == n {
			r1[nr1] = a - 1
			nr1++
		}
	}

	// Initialize a result variable to determine if a connection is possible
	var res bool

	// Check if any of the nodes connected to node n are also connected to node 1
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true
		}
	}

	// Output the result based on the value of res
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

