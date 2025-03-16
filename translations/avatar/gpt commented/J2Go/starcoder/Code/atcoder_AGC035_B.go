package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize scanner to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of nodes and edges from input
	numNode, numEdge := readInput(sc)

	// Create an adjacency list to represent the graph
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}

	// Read edges and populate the adjacency list
	for i := 0; i < numEdge; i++ {
		a, b := readInput(sc)
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}

	// Check if the number of edges is odd; if so, output -1 and exit
	if numEdge%2!= 0 {
		fmt.Println(-1)
		return
	}

	// Initialize arrays for tracking visited nodes and odd/even connections
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	print := ""

	// Perform depth-first search starting from node 0
	dfs(connect, visited, odd, 0, -1, &print)

	// Output the result
	fmt.Println(print)
}

// Declare global variables for the graph representation and state tracking
var connect [][]int
var visited []int
var odd []bool
var print string

// Depth-first search method to explore the graph
func dfs(connect [][]int, visited []int, odd []bool, crt int, parent int, print *string) {
	visited[crt] = 1
	crtConnect := connect[crt]

	// Iterate through each child node connected to the current node
	for _, child := range crtConnect {
		// Skip the parent node and already visited nodes
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			// If the child has been fully processed, append the edge to output
			*print += fmt.Sprintf("%d %d\n", crt+1, child+1)
			odd[crt] =!odd[crt]
		} else {
			// Recursively call DFS on the child node
			dfs(connect, visited, odd, child, crt, print)

			// Check the odd/even state of the child node after DFS
			if odd[child] {
				*print += fmt.Sprintf("%d %d\n", child+1, crt+1)
				odd[child] =!odd[child]
			} else {
				*print += fmt.Sprintf("%d %d\n", crt+1, child+1)
				odd[crt] =!odd[crt]
			}
		}
	}
	visited[crt] = 2
}

// Read the number of nodes and edges from input
func readInput(sc *bufio.Scanner) (int, int) {
	sc.Scan()
	numNode, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	numEdge, _ := strconv.Atoi(sc.Text())
	return numNode, numEdge
}

// Read two integers from input
func readInput(sc *bufio.Scanner) (int, int) {
	sc.Scan()
	a, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	b, _ := strconv.Atoi(sc.Text())
	return a, b
}

