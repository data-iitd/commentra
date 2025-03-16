// 深さ優先探索
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to generate unique id based on two integers
func genid(a, b int) int {
	if b < a {
		a, b = b, a
	}
	// Multiply the larger number by 100000 and add the smaller number
	return a*100000 + b
}

// Main function
func main() {
	// Read the number of edges in the graph
	N := readInt()

	// Initialize an adjacency list and a 2D array to store the edges between nodes
	ab := make([][2]int, N-1)
	edges := make([][]int, N)
	for i := 0; i < N-1; i++ {
		// Read two integers representing the nodes connected by an edge
		a := readInt() - 1
		b := readInt() - 1
		// Store the nodes and their indices in the ab array
		ab[i][0], ab[i][1] = a, b
		// Add the edge to the adjacency list
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Initialize a map to store the colors of each connected component
	colors := make(map[int]int)
	// Initialize a queue to perform DFS
	q := make([][3]int, 0)
	// Add the first node to the queue with initial color and parent node set to -1
	q = append(q, [3]int{0, -1, -1})
	for len(q) != 0 {
		// Dequeue the current node, its color, and its parent node
		currentNode, usedColor, parentNode := q[len(q)-1][0], q[len(q)-1][1], q[len(q)-1][2]
		q = q[:len(q)-1]
		// Set the color of the current node to the next available color
		color := 1
		for _, childNode := range edges[currentNode] {
			if childNode == parentNode {
				continue
			}
			// If the color of the current node is the same as the color of the child node, increment the color
			if color == usedColor {
				color++
			}
			// Assign the color to the child node and add it to the queue with the current node as its parent node
			colors[genid(currentNode, childNode)] = color
			q = append(q, [3]int{childNode, color, currentNode})
			// Increment the color for the next iteration
			color++
		}
	}

	// Initialize a variable to store the maximum number of edges in a connected component
	K := -1
	// Iterate through all nodes in the graph and update the maximum number of edges if necessary
	for i := 0; i < N; i++ {
		t := len(edges[i])
		if t > K {
			K = t
		}
	}
	// Print the maximum number of edges in a connected component
	fmt.Println(K)

	// Iterate through all edges in the graph and print their colors
	for i := 0; i < N-1; i++ {
		fmt.Println(colors[genid(ab[i][0], ab[i][1])])
	}
}

// Constants for input buffer size and standard input scanner
const (
	ioBufferSize = 1 * 1024 * 1024 // 1 MB
)

// Function to read from standard input using a pre-initialized scanner
var stdinScanner = func() *bufio.Scanner {
	result := bufio.NewScanner(os.Stdin)
	result.Buffer(make([]byte, ioBufferSize), ioBufferSize)
	result.Split(bufio.ScanWords)
	return result
}()

// Function to read a single string from standard input
func readString() string {
	stdinScanner.Scan()
	return stdinScanner.Text()
}

// Function to read a single integer from standard input
func readInt() int {
	result, err := strconv.Atoi(readString())
	if err != nil {
		panic(err)
	}
	return result
}
