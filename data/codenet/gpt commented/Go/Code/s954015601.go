// 深さ優先探索
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
func genid(a, b int) int {
	if b < a {
		a, b = b, a
	}
	return a*100000 + b
}

func main() {
	// Read the number of nodes in the graph
	N := readInt()

	// Initialize a slice to hold the edges and an adjacency list for the graph
	ab := make([][2]int, N-1)
	edges := make([][]int, N)

	// Read edges from input and populate the adjacency list
	for i := 0; i < N-1; i++ {
		a := readInt() - 1 // Convert to zero-based index
		b := readInt() - 1 // Convert to zero-based index
		ab[i][0], ab[i][1] = a, b
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Map to store colors assigned to edges
	colors := make(map[int]int)
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	q := make([][3]int, 0)
	q = append(q, [3]int{0, -1, -1}) // Start DFS from node 0 with no used color and no parent

	// Perform DFS to assign colors to edges
	for len(q) != 0 {
		currentNode, usedColor, parentNode := q[len(q)-1][0], q[len(q)-1][1], q[len(q)-1][2]
		q = q[:len(q)-1] // Pop the last element from the stack
		color := 1 // Start coloring from color 1

		// Iterate through child nodes of the current node
		for _, childNode := range edges[currentNode] {
			if childNode == parentNode {
				continue // Skip the parent node to avoid backtracking
			}
			if color == usedColor {
				color++ // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, childNode)] = color
			// Push the child node onto the stack for further exploration
			q = append(q, [3]int{childNode, color, currentNode})
			color++ // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	K := -1
	for i := 0; i < N; i++ {
		t := len(edges[i]) // Degree of the current node
		if t > K {
			K = t // Update maximum degree if current node's degree is greater
		}
	}
	fmt.Println(K) // Print the maximum degree

	// Print the colors assigned to each edge
	for i := 0; i < N-1; i++ {
		fmt.Println(colors[genid(ab[i][0], ab[i][1])])
	}
}

// Constants for input buffer size
const (
	ioBufferSize = 1 * 1024 * 1024 // 1 MB
)

// stdinScanner initializes a buffered scanner for reading input
var stdinScanner = func() *bufio.Scanner {
	result := bufio.NewScanner(os.Stdin)
	result.Buffer(make([]byte, ioBufferSize), ioBufferSize)
	result.Split(bufio.ScanWords)
	return result
}()

// readString reads a string from standard input
func readString() string {
	stdinScanner.Scan()
	return stdinScanner.Text()
}

// readInt reads an integer from standard input and handles any conversion errors
func readInt() int {
	result, err := strconv.Atoi(readString())
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return result
}
