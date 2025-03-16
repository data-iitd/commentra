
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func dfs(links [][]int, n, k, v, p int) (int, int) {
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
		heightFromLeaf = max(heightFromLeaf, hgt)

		// Accumulate the cut count from the child nodes
		cutCount += cut
	}

	// Increment the height from the leaf node as we return to the parent
	heightFromLeaf += 1

	// Check if the current height matches k and we are not at the root node
	if p != 0 && heightFromLeaf == k {
		// Reset height from leaf to 0 and increment cut count
		heightFromLeaf = 0
		cutCount += 1
	}

	// Return the height from the leaf and the total cut count
	return heightFromLeaf, cutCount
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	// Read input values for n (number of nodes), k (target height), and the rest of the connections
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	links := make([][]int, n)
	for i := range links {
		links[i] = make([]int, n)
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		a-- // Adjust for 0-based indexing
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		b-- // Adjust for 0-based indexing
		links[a][b] = 1
		links[b][a] = 1
	}

	// Perform DFS starting from the root node (0) and get the total cuts
	_, ans := dfs(links, n, k, 0, 0)

	// If the first node is not the root, increment the answer
	if links[0][1] != 0 {
		ans++
	}

	// Print the final answer (total cuts)
	fmt.Println(ans)
}

