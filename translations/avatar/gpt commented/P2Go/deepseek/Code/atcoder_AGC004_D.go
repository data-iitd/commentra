package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Set the maximum recursion limit to handle deep recursions
func setRecursionLimit() {
	// Go does not have a built-in recursion limit, so we don't need to do anything here
}

func dfs(links [][]int, n, k int, v, p int) (int, int) {
	// Initialize height from the leaf node and cut count
	heightFromLeaf := 0
	cutCount := 0
	
	// Iterate through all connected nodes (children) of the current node
	for _, u := range links[v] {
		// Skip if the child node is 0 (indicating no further connections)
		if u == 0 {
			continue
		}
		
		// Recursively perform DFS on the child node and get its height and cut count
		hgt, cut := dfs(links, n, k, u, v)
		
		// Update the maximum height from the leaf node
		if heightFromLeaf < hgt {
			heightFromLeaf = hgt
		}
		
		// Accumulate the cut count from the child nodes
		cutCount += cut
	}
	
	// Increment the height from the leaf node as we return to the parent
	heightFromLeaf++
	
	// Check if the current height matches k and we are not at the root node
	if p != 0 && heightFromLeaf == k {
		// Reset height from leaf to 0 and increment cut count
		heightFromLeaf = 0
		cutCount++
	}
	
	// Return the height from the leaf and the total cut count
	return heightFromLeaf, cutCount
}

func main() {
	setRecursionLimit()
	
	// Read input values for n (number of nodes), k (target height), and the rest of the connections
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	values := []int{}
	for _, s := range input {
		if s >= '0' && s <= '9' {
			values = append(values, int(s-'0'))
		}
	}
	n := values[0]
	k := values[1]
	aaa := values[2:]
	
	// Create a list of slices to represent the graph (tree) connections
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		links[i] = []int{}
	}
	
	// Populate the links based on the input connections
	for i, a := range aaa {
		a-- // Adjust for 0-based indexing
		links[a] = append(links[a], i+1)
	}
	
	// Perform DFS starting from the root node (0) and get the total cuts
	_, ans := dfs(links, n, k, 0, 0)
	
	// If the first node is not the root, increment the answer
	if aaa[0] != 1 {
		ans++
	}
	
	// Print the final answer (total cuts)
	fmt.Println(ans)
}
