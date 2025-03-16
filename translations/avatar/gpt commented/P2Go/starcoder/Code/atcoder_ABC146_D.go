package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Use fast input method
var reader = bufio.NewReader(os.Stdin)

func main() {
	// Read the number of nodes
	N, _ := strconv.Atoi(readLine())
	// Initialize the graph as a list of deques
	G := make([][]int, N)
	for i := 0; i < N; i++ {
		G[i] = make([]int, 0)
	}
	// Initialize a dictionary to store edge colors
	E := make(map[int]int)
	
	// Read edges and build the graph
	for i := 0; i < N - 1; i++ {
		a, b := readArray(2)
		a, b = a - 1, b - 1
		G[a] = append(G[a], b)  // Add edge from a to b
		G[b] = append(G[b], a)  // Add edge from b to a
		E[a*N+b] = 0  // Initialize edge color to 0
	}
	
	// Perform BFS starting from node 0
	K := bfs(0, N, G, E)
	
	// Print the maximum color used
	fmt.Println(K)
	// Print the colors assigned to each edge
	for _, value := range E {
		fmt.Println(value)
	}
}

// Read a single line from stdin
func readLine() string {
	bytes, _ := reader.ReadBytes('\n')
	return strings.TrimRight(string(bytes), "\r\n")
}

// Read a space separated array of integers from stdin
func readArray(size int) []int {
	var line string
	var items []int
	for i := 0; i < size; i++ {
		line, _ = reader.ReadString(' ')
		items = append(items, parseInt(line))
	}
	return items
}

// Parse integer from string
func parseInt(str string) int {
	i, _ := strconv.Atoi(str)
	return i
}

// 