// Set the recursion limit for the function call stack to 1 million
package main

import "fmt"

func main() {
	// Read input from standard input
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	var aaa []int
	for i := 0; i < n; i++ {
		var a int
		fmt.Scanf("%d", &a)
		aaa = append(aaa, a)
	}

	// Initialize the 'links' list with sets for each node
	links := make([]map[int]bool, n)
	for i := 0; i < n; i++ {
		links[i] = make(map[int]bool)
	}

	// Process the input edges and add them to the 'links' list
	for i, a := range aaa {
		a--
		links[a][i] = true
	}

	// Call the 'dfs' function with the initial parameters
	ans := dfs(links, n, k, 0, 0)

	// If the first node is not a root node, add 1 to the answer
	if aaa[0]!= 1 {
		ans += 1
	}

	// Print the final answer
	fmt.Println(ans)
}

func dfs(links []map[int]bool, n, k, v, p int) int {
	// Initialize variables for height from leaf node and cut count
	height_from_leaf := 0
	cut_count := 0

	// Iterate through neighbors of the current node 'v'
	for u := range links[v] {
		// Skip if the neighbor is not a valid node (0)
		if u == 0 {
			continue
		}

		// Recursively call the 'dfs' function for the neighbor 'u'
		hgt, cut := dfs(links, n, k, u, v)

		// Update the height from leaf and cut count
		height_from_leaf = max(height_from_leaf, hgt)
		cut_count += cut
	}

	// Update the height from leaf and cut count for the current node 'v'
	height_from_leaf += 1

	// If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
	// then this node is a cut vertex and we need to add 1 to the cut count
	if p!= 0 && height_from_leaf == k {
		height_from_leaf = 0
		cut_count += 1
	}

	// Return the height from leaf and cut count for the current node 'v'
	return height_from_leaf, cut_count
}

// 