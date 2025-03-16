package main

import (
	"fmt"
	"os"
)

var links [][]int
var n, k int

func dfs(v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0

	for _, u := range links[v] {
		if u == 0 { // Skip if the node is the root (0)
			continue
		}
		hgt, cut := dfs(u, v) // Recursively call DFS
		if hgt > heightFromLeaf {
			heightFromLeaf = hgt // Update the height from the leaf
		}
		cutCount += cut // Count the number of cuts
	}
	heightFromLeaf++ // Increment the height from the leaf node

	if p != 0 && heightFromLeaf == k { // Check if a cut is needed
		heightFromLeaf = 0 // Reset the height
		cutCount++         // Increment the cut count
	}
	return heightFromLeaf, cutCount // Return the height and cut count
}

func main() {
	var aaa []int
	fmt.Fscan(os.Stdin, &n, &k) // Read n and k
	aaa = make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(os.Stdin, &aaa[i]) // Read the rest of the input
		aaa[i]--                     // Convert to 0-based index
	}

	links = make([][]int, n) // Initialize the tree structure
	for i, a := range aaa {
		links[a] = append(links[a], i+1) // Build the tree
	}

	_, ans := dfs(0, -1) // Perform DFS starting from the root
	if aaa[0] != 1 {     // Adjust the answer if necessary
		ans++
	}
	fmt.Println(ans) // Output the final result
}

// <END-OF-CODE>
