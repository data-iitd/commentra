
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a class named Main that implements the Runnable interface
type Main struct {
	graph    [][]int // Declaring an array named graph to store the adjacency list of the graph
	visited  []bool  // Declaring a boolean array named visited to keep track of the visited nodes
	color    []int   // Declaring an integer array named color to store the color of each node in the graph
	one      int64   // Declaring an integer variable named one to store the number of nodes in a single connected component
	bipartite int64   // Declaring an integer variable named bipartite to store the number of bipartite connected components
	count    int64   // Declaring an integer variable named count to store the total number of nodes in the graph
	mujun    bool    // Declaring a boolean variable named mujun to check if there is an odd cycle in the graph
}

// Defining the run method to be executed when the thread is started
func (this *Main) run() {
	scan := bufio.NewScanner(os.Stdin) // Creating a Scanner object to read the input from the standard input
	n, _ := strconv.Atoi(scan.Text())  // Reading the number of nodes in the graph from the input
	m, _ := strconv.Atoi(scan.Text())  // Reading the number of edges in the graph from the input
	this.graph = make([][]int, n)      // Initializing the graph array with n sub-arrays
	for i := 0; i < n; i++ {
		this.graph[i] = make([]int, 0) // Initializing each sub-array with an empty array
	}
	for i := 0; i < m; i++ { // Iterating through each edge in the graph
		u, _ := strconv.Atoi(scan.Text()) // Reading the source node of the edge from the input
		v, _ := strconv.Atoi(scan.Text()) // Reading the destination node of the edge from the input
		this.graph[u-1] = append(this.graph[u-1], v-1) // Adding the destination node to the adjacency list of the source node
		this.graph[v-1] = append(this.graph[v-1], u-1) // Adding the source node to the adjacency list of the destination node
	}
	this.visited = make([]bool, n) // Initializing the visited array with false values
	this.color = make([]int, n)    // Initializing the color array with -1 values
	for i := 0; i < n; i++ {
		this.color[i] = -1 // Setting all the initial colors to -1
	}
	for i := 0; i < n; i++ { // Iterating through each node in the graph
		if this.visited[i] {
			continue // Skipping the node if it has already been visited
		}
		this.count++ // Incrementing the count of nodes in the graph
		this.mujun = false // Resetting the mujun flag
		kind := this.dfs(i, 0) // Calling the depth-first search algorithm to find the connected component and its bipartiteness
		if kind == 1 {
			this.one++ // Incrementing the count of nodes in a single connected component if it is a single connected component
		} else if!this.mujun {
			this.bipartite++ // Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
		}
	}
	total := this.one * (2*n - this.one) // Calculating the total number of edges in the graph
	total += (this.count - this.one) * (this.count - this.one) // Calculating the number of edges in the isolated nodes
	total += this.bipartite * this.bipartite // Calculating the number of edges in the bipartite connected components
	fmt.Println(total) // Printing the total number of edges in the graph
}

// Defining the depth-first search algorithm to find the connected component and its bipartiteness
func (this *Main) dfs(a, c int) int {
	if this.visited[a] { // Checking if the current node has already been visited
		if this.color[a] >= 0 && this.color[a]!= c {
			this.mujun = true // Setting the mujun flag if there is an odd cycle in the graph
		}
		return 0 // Returning 0 if the current node is already visited
	}
	this.visited[a] = true // Marking the current node as visited
	this.color[a] = c      // Setting the color of the current node
	total := 1             // Initializing the total number of nodes in the connected component to 1
	for _, b := range this.graph[a] {
		total += this.dfs(b, 1-c) // Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
	}
	return total // Returning the total number of nodes in the connected component
}

func main() {
	var this Main // Creating a new object of the Main class
	this.run()    // Starting the thread to execute the run method of the Main class
}

