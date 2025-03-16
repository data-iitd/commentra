package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Set the recursion limit for the function call stack to 1 million
func init() {
	var limit int = 1000000
}

// Define the depth-first search function 'dfs'
func dfs(links [][]int, n, k int, v, p int) (int, int) {
	// Initialize variables for height from leaf node and cut count
	heightFromLeaf := 0
	cutCount := 0

	// Iterate through neighbors of the current node 'v'
	for _, u := range links[v] {
		// Skip if the neighbor is not a valid node (0)
		if u == 0 {
			continue
		}

		// Recursively call the 'dfs' function for the neighbor 'u'
		hgt, cut := dfs(links, n, k, u, v)

		// Update the height from leaf and cut count
		if heightFromLeaf < hgt {
			heightFromLeaf = hgt
		}
		cutCount += cut
	}

	// Update the height from leaf and cut count for the current node 'v'
	heightFromLeaf++

	// If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
	// then this node is a cut vertex and we need to add 1 to the cut count
	if p != 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}

	// Return the height from leaf and cut count for the current node 'v'
	return heightFromLeaf, cutCount
}

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	k, _ := strconv.Atoi(readLine(reader))
	var aaa []int
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(readLine(reader))
		aaa = append(aaa, a)
	}

	// Initialize the 'links' list with slices for each node
	links := make([][]int, n)
	for i := range links {
		links[i] = []int{}
	}

	// Process the input edges and add them to the 'links' list
	for i, a := range aaa {
		a--
		links[a] = append(links[a], i)
	}

	// Call the 'dfs' function with the initial parameters
	hgt, ans := dfs(links, n, k, 0, 0)

	// If the first node is not a root node, add 1 to the answer
	if aaa[0] != 1 {
		ans++
	}

	// Print the final answer
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
