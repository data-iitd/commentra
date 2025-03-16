package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declaring global variables
var (
	numNode int
	numEdge int
	connect [1000000]int
	visited [1000000]int
	odd     [1000000]bool
	print   strings.Builder
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &numNode)
	fmt.Fscan(reader, &numEdge)

	// Initializing adjacency lists for each node
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0)
	}

	// Reading edges and populating the adjacency lists
	for i := 0; i < numEdge; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		connect[a-1] = append(connect[a-1], b-1)
		connect[b-1] = append(connect[b-1], a-1)
	}

	// Checking if the number of edges is odd
	if numEdge%2!= 0 {
		fmt.Println(-1)
		return
	}

	// Initializing arrays for DFS
	for i := 0; i < numNode; i++ {
		visited[i] = 0
		odd[i] = false
	}

	// Performing DFS starting from node 0
	dfs(0, -1)

	// Outputting the result
	fmt.Println(print.String())
}

// DFS method to traverse the graph
func dfs(crt, parent int) {
	visited[crt] = 1
	crtConnect := connect[crt]

	// Traversing each child node of the current node
	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 { // Skipping if the child is the parent or already visited
			continue
		} else if visited[child] == 2 { // Handling the case where the child is part of an already visited cycle
			print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] =!odd[crt]
		} else { // Recursively calling dfs for unvisited child nodes
			dfs(child, crt)
			if odd[child] { // Updating the print and odd arrays based on the child's result
				print.WriteString(fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] =!odd[child]
			} else {
				print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] =!odd[crt]
			}
		}
	}
	visited[crt] = 2
}

// ReadLine reads a line from the reader
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

