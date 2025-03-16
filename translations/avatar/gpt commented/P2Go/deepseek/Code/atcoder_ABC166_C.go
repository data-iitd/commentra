package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	// Read the values of n (number of nodes) and m (number of edges) from input
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Create a list of nodes from 1 to n
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}

	// Read the health points for each node from input
	scanner.Scan()
	h := []int{}
	for _, num := range strings.Split(scanner.Text(), " ") {
		health, _ := strconv.Atoi(num)
		h = append(h, health)
	}

	// Create a map to represent the graph as an adjacency list
	// Each node will map to a list of its connected nodes (edges)
	path := make(map[int][]int)

	// Read m edges from input and populate the adjacency list
	for i := 0; i < m; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		path[a] = append(path[a], b)
		path[b] = append(path[b], a)
	}

	// Initialize a counter for nodes that have no neighbors with equal or higher health points
	c := 0

	// Iterate through each node and its connected nodes
	for i := 1; i <= n; i++ {
		f := 0 // Flag to check if any neighbor has equal or higher health points
		for _, j := range path[i] {
			// Check if the current node's health is less than or equal to any of its neighbors
			if h[i-1] <= h[j-1] {
				f = 1 // Set flag if a neighbor with equal or higher health is found
				break // No need to check further neighbors
			}
		}
		// If no neighbors have equal or higher health points, increment the counter
		if f == 0 {
			c += 1
		}
	}

	// Print the count of nodes that have no neighbors with equal or higher health points
	fmt.Println(c)
}
