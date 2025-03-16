
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Set the recursion limit to prevent overflow
	var recursionLimit int = 1000000

	// Step 2: Define the DFS function
	var dfs func(links [][]int, n int, k int, v int, p int) (int, int)
	dfs = func(links [][]int, n int, k int, v int, p int) (int, int) {
		heightFromLeaf := 0 // Initialize the height from the leaf node
		cutCount := 0       // Initialize the count of cuts
		for _, u := range links[v] {
			// Skip if the node is the root (0)
			if u == 0 {
				continue
			}
			hgt, cut := dfs(links, n, k, u, v) // Recursively call DFS
			heightFromLeaf = max(heightFromLeaf, hgt) // Update the height from the leaf
			cutCount += cut // Count the number of cuts
		}
		heightFromLeaf += 1 // Increment the height from the leaf node
		if p != 0 && heightFromLeaf == k { // Step 4: Check if a cut is needed
			heightFromLeaf = 0 // Reset the height
			cutCount += 1 // Increment the cut count
		}
		return heightFromLeaf, cutCount // Step 5: Return the height and cut count
	}

	// Step 6: Read input data
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	links := make([][]int, n)
	for i := 0; i < n; i++ {
		links[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		a -= 1
		links[a] = append(links[a], i+1)
	}

	// Step 7: Build the tree
	for i, a := range aaa {
		a -= 1
		links[a] = append(links[a], i)
	}

	// Step 8: Perform DFS starting from the root
	_, ans := dfs(links, n, k, 0, 0)

	// Step 9: Adjust the answer if necessary
	if aaa[0] != 1 {
		ans += 1
	}

	// Step 10: Output the final result
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 