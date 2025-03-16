package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Set the maximum recursion limit to handle deep recursions
const maxDepth = 1000000

// DFS function to perform depth-first search
func dfs(links []map[int]bool, n, k, v, p int) (int, int) {
	// Initialize height from the leaf node and cut count
	heightFromLeaf := 0
	cutCount := 0

	// Iterate through all connected nodes (children) of the current node
	for u := range links[v] {
		// Skip if the child node is 0 (indicating no further connections)
		if u == 0 {
			continue
		}

		// Recursively perform DFS on the child node and get its height and cut count
		hgt, cut := dfs(links, n, k, u, v)

		// Update the maximum height from the leaf node
		heightFromLeaf = max(heightFromLeaf, hgt)

		// Accumulate the cut count from the child nodes
		cutCount += cut
	}

	// Increment the height from the leaf node as we return to the parent
	heightFromLeaf += 1

	// Check if the current height matches k and we are not at the root node
	if p!= 0 && heightFromLeaf == k {
		// Reset height from leaf to 0 and increment cut count
		heightFromLeaf = 0
		cutCount += 1
	}

	// Return the height from the leaf and the total cut count
	return heightFromLeaf, cutCount
}

// Read input values for n (number of nodes), k (target height), and the rest of the connections
func readInput() (int, int, []int) {
	// Read the first line of input
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	// Split the line into individual values
	values := strings.Split(line, " ")

	// Convert the values to integers
	n, k := int(values[0]), int(values[1])

	// Create a list of sets to represent the graph (tree) connections
	links := make([]map[int]bool, n)

	// Populate the links based on the input connections
	for i := 0; i < n; i++ {
		links[i] = make(map[int]bool)
	}

	// Read the rest of the input
	for i := 0; i < n-1; i++ {
		// Read the next line of input
		line, _ := bufio.NewReader(os.Stdin).ReadString('\n')

		// Split the line into individual values
		values := strings.Split(line, " ")

		// Convert the values to integers
		a, b := int(values[0]), int(values[1])

		// Adjust for 0-based indexing
		a -= 1
		b -= 1

		// Add the connection to the graph
		links[a][b] = true
		links[b][a] = true
	}

	// Return the input values
	return n, k, links
}

// Print the final answer (total cuts)
func printAnswer(ans int) {
	// Print the final answer (total cuts)
	fmt.Println(ans)
}

// Find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function
func main() {
	// Read input values for n (number of nodes), k (target height), and the rest of the connections
	n, k, links := readInput()

	// Perform DFS starting from the root node (0) and get the total cuts
	_, ans := dfs(links, n, k, 0, 0)

	// If the first node is not the root, increment the answer
	if links[0][1] {
		ans += 1
	}

	// Print the final answer (total cuts)
	printAnswer(ans)
}

