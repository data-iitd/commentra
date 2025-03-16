// Importing necessary libraries and setting recursion limit
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to take input as an integer
func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to take input as a list
func inpl() []int {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	return a
}

// Initialize an adjacency list
var g [][]int

// Read edges and add them to the graph
func readEdges() {
	n := inp()
	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		a, b := inpl()
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
}

// Initialize distance arrays for both nodes
var ta_dist []int
var ao_dist []int

// Initialize distances for starting and ending nodes
func initDist() {
	ta_dist = make([]int, len(g))
	ao_dist = make([]int, len(g))
	ta_dist[ta] = 0
	ao_dist[ao] = 0
}

// Depth First Search from starting node to calculate distances from starting node
func ta_dfs(node int) {
	for _, v := range g[node] {
		if ta_dist[v] != 0 {
			continue
		}
		ta_dist[v] = ta_dist[node] + 1
		ta_dfs(v)
	}
}

// Depth First Search from ending node to calculate distances from ending node
func ao_dfs(node int) {
	for _, v := range g[node] {
		if ao_dist[v] != 0 {
			continue
		}
		ao_dist[v] = ao_dist[node] + 1
		ao_dfs(v)
	}
}

// Perform Depth First Search from starting and ending nodes
func performDfs() {
	ao_dfs(ao)
	ta_dfs(ta)
}

// Calculate the answer
func calculate() int {
	res := 0
	for i := 0; i < len(g); i++ {
		if ta_dist[i] == 0 || ao_dist[i] == 0 || ta_dist[i] > ao_dist[i] {
			continue
		}
		if res < ao_dist[i] {
			res = ao_dist[i]
		}
	}
	return res - 1
}

// Print the answer
func printAnswer(res int) {
	fmt.Println(res)
}

// Main function
func main() {
	// Read edges and add them to the graph
	readEdges()

	// Initialize distance arrays for both nodes
	initDist()

	// Perform Depth First Search from starting and ending nodes
	performDfs()

	// Calculate the answer
	res := calculate()

	// Print the answer
	printAnswer(res)
}

