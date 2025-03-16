package main

import (
	"bufio"
	"fmt"
	"os"
)

var G [100000][]int // Declare an adjacency list named G with a maximum size of 100000
var used [100000]bool // Declare a boolean array named used to keep track of visited vertices
var grundy [100000]int // Declare an array named grundy to store the Grundy numbers of vertices

func dfs(v int) { // Define a recursive depth-first search function named dfs
	used[v] = true // Set the visited status of the current vertex to true
	grundy[v] = 0 // Initialize the Grundy number of the current vertex to 0
	for i := 0; i < len(G[v]); i++ { // Iterate through all the neighbors of the current vertex
		w := G[v][i] // Assign the neighbor to a temporary variable w
		if !used[w] { // If the neighbor has not been visited yet
			dfs(w) // Recursively call the dfs function for the neighbor
			grundy[v] ^= (grundy[w]+1) // Update the Grundy number of the current vertex based on the neighbor's Grundy number
		}
	}
}

func main() { // Define the main function
	in := bufio.NewReader(os.Stdin) // Create a new buffered reader for standard input
	out := bufio.NewWriter(os.Stdout) // Create a new buffered writer for standard output
	defer out.Flush() // Flush the buffered writer when the function returns

	var N int // Declare an integer variable named N to store the number of vertices
	fmt.Fscan(in, &N) // Read the number of vertices from the standard input
	for i := 0; i < N-1; i++ { // Iterate through all the edges except the last one
		var x, y int // Declare two integer variables named x and y to store the endpoints of an edge
		fmt.Fscan(in, &x, &y) // Read the endpoints of an edge from the standard input
		x-- // Decrease the index of x by 1 to make it zero-indexed
		y-- // Decrease the index of y by 1 to make it zero-indexed
		G[x] = append(G[x], y) // Add an edge from x to y to the adjacency list
		G[y] = append(G[y], x) // Add a reciprocal edge from y to x to the adjacency list
	}
	dfs(0) // Call the dfs function starting from vertex 0
	if grundy[0] != 0 { // Check if the Grundy number of the root vertex is non-zero
		fmt.Fprintln(out, "Alice") // If so, print "Alice" to the standard output
	} else { // Otherwise
		fmt.Fprintln(out, "Bob") // Print "Bob" to the standard output
	}
}

