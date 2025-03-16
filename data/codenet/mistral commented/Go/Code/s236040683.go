// Package main is the entry point of the program.
package main

import (
	"bufio" // We use bufio package for reading input.
	"fmt"   // We use fmt package for formatted I/O.
	"os"    // We use os package for accessing the operating system.
	"strconv" // We use strconv package for converting strings to integers.
)

// out is a custom function for printing output.
func out(x ...interface{}) {
	fmt.Println(x...)
}

// sc is a buffer scanner for reading input.
var sc = bufio.NewScanner(os.Stdin)

// getInt reads and converts an integer from the input.
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// getString reads and returns a string from the input.
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Node is a custom data structure for representing a node in the graph.
type Node struct {
	to []int
}

// main is the entry point of the program.
func main() {
	// Set up the scanner to read words instead of lines.
	sc.Split(bufio.ScanWords)

	// Read the number of nodes N and edges M from the input.
	N, M := getInt(), getInt()

	// Create a slice n of size N to store the nodes.
	n := make([]Node, N)

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for i := 0; i < M; i++ {
		// Read the from and to nodes from the input.
		from, to := getInt()-1, getInt()-1

		// Add the edge to the to slice of the from node.
		n[from].to = append(n[from].to, to)

		// Add the edge to the to slice of the to node.
		n[to].to = append(n[to].to, from)
	}

	// Print the number of neighbors for each node.
	for i := 0; i < N; i++ {
		// Print the number of neighbors of the current node.
		out(len(n[i].to))
	}
}

// 