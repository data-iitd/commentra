package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// out is a helper function to print output to the console.
func out(x ...interface{}) {
	fmt.Println(x...)
}

// Create a new scanner to read input from standard input.
var sc = bufio.NewScanner(os.Stdin)

// getInt reads an integer from standard input and returns it.
// It panics if the input cannot be converted to an integer.
func getInt() int {
	sc.Scan() // Read the next token from input
	i, e := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if e != nil {
		panic(e) // Panic if there is an error during conversion
	}
	return i // Return the integer value
}

// getString reads a string from standard input and returns it.
func getString() string {
	sc.Scan() // Read the next token from input
	return sc.Text() // Return the string value
}

// Node represents a graph node with a slice of connected nodes.
type Node struct {
	to []int // Slice to hold indices of connected nodes
}

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the number of nodes (N) and edges (M) from input
	N, M := getInt(), getInt()
	// Create a slice of Node structures to represent the graph
	n := make([]Node, N)

	// Read M edges and populate the graph
	for i := 0; i < M; i++ {
		from, to := getInt()-1, getInt()-1 // Read the edge endpoints (0-indexed)
		n[from].to = append(n[from].to, to) // Add the connection from 'from' to 'to'
		n[to].to = append(n[to].to, from) // Add the connection from 'to' to 'from' (undirected graph)
	}

	// Output the degree (number of connections) of each node
	for i := 0; i < N; i++ {
		out(len(n[i].to)) // Print the number of connections for node i
	}
}
