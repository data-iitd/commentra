
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare a global adjacency list named G with a maximum size of 100000
var G [100000][]int

// Declare a global boolean array named used to keep track of visited vertices
var used [100000]bool

// Declare a global array named grundy to store the Grundy numbers of vertices
var grundy [100000]int

// Define a recursive depth-first search function named dfs
func dfs(v int) {
	used[v] = true // Set the visited status of the current vertex to true
	grundy[v] = 0 // Initialize the Grundy number of the current vertex to 0
	for _, w := range G[v] { // Iterate through all the neighbors of the current vertex
		if!used[w] { // If the neighbor has not been visited yet
			dfs(w) // Recursively call the dfs function for the neighbor
			grundy[v] ^= (grundy[w] + 1) // Update the Grundy number of the current vertex based on the neighbor's Grundy number
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of vertices: ")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for i := 0; i < N-1; i++ {
		fmt.Print("Enter the endpoints of an edge: ")
		x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		y, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		x--
		y--
		G[x] = append(G[x], y) // Add an edge from x to y to the adjacency list
		G[y] = append(G[y], x) // Add a reciprocal edge from y to x to the adjacency list
	}
	dfs(0) // Call the dfs function starting from vertex 0
	if grundy[0]!= 0 { // Check if the Grundy number of the root vertex is non-zero
		fmt.Println("Alice") // If so, print "Alice" to the standard output
	} else { // Otherwise
		fmt.Println("Bob") // Print "Bob" to the standard output
	}
}

