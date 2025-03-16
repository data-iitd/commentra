
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables to store the connectivity information for each node.
var connect [ ] []int

// Global variables to store the visited status and odd component for each node.
var visited [ ] int
var odd [ ] bool

// Global variable to store the output.
var print strings.Builder

// Function to read input from the standard input stream.
func readInput() {
	sc := bufio.NewScanner(os.Stdin)
	numNode, _ := strconv.Atoi(sc.Text())
	numEdge, _ := strconv.Atoi(sc.Text())

	// Initializing the connect array to store the list of neighbors for each node.
	connect = make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}

	// Reading the edges and adding them to the connect array.
	for i := 0; i < numEdge; i++ {
		a, _ := strconv.Atoi(sc.Text())
		b, _ := strconv.Atoi(sc.Text())
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}
}

// Function to check if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
func checkOdd(numEdge int) {
	if numEdge%2!= 0 {
		fmt.Println(-1)
		os.Exit(0)
	}
}

// Function to perform bipartite traversal.
func dfs(crt, parent int) {
	// Marking the current node as visited.
	visited[crt] = 1

	// Iterating through the neighbors of the current node.
	for _, child := range connect[crt] {
		// Skipping the neighbor if it is the parent node or already visited.
		if child == parent || visited[child] == 1 {
			continue
		}

		// If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
		// Otherwise, we swap the components and continue the traversal.
		if visited[child] == 2 {
			print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] =!odd[crt]
		} else {
			dfs(child, crt)
			if odd[child] {
				print.WriteString(fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] =!odd[child]
			} else {
				print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] =!odd[crt]
			}
		}
	}

	// Marking the current node as visited with component 2.
	visited[crt] = 2
}

// Main function where the program starts execution.
func main() {
	readInput()
	checkOdd(len(connect[0]))

	// Initializing the visited, odd, and print arrays and objects.
	visited = make([]int, len(connect))
	odd = make([]bool, len(connect))
	print = strings.Builder{}

	// Calling the dfs method with the first node and -1 as the parent node.
	dfs(0, -1)

	// Printing the output.
	fmt.Println(print.String())
}

