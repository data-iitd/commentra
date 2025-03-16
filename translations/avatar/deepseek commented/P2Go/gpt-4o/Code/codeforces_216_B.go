package main

import (
	"fmt"
	"os"
)

func readInts() ([]int, error) { // Function to read integers from input
	var n int
	var err error
	var nums []int
	for {
		_, err = fmt.Scan(&n)
		if err != nil {
			break
		}
		nums = append(nums, n)
	}
	return nums, err
}

func dfs(g map[int]map[int]struct{}, seen map[int]struct{}, i int) (int, int) { // Depth-First Search
	if _, ok := seen[i]; ok { // If node is already seen, return 0, 0
		return 0, 0
	}
	seen[i] = struct{}{} // Mark the node as seen
	nodes := 1            // Initialize node count
	edges := len(g[i])    // Count edges from the current node
	for j := range g[i] { // Traverse all adjacent nodes
		x, y := dfs(g, seen, j) // Recursively call dfs for each adjacent node
		nodes += x              // Update node count
		edges += y              // Update edge count
	}
	return nodes, edges // Return the count of nodes and edges
}

func solve() bool { // Main function to solve the problem
	var n, m int
	_, err := fmt.Scan(&n, &m) // Read the first line of input
	if err != nil {
		return false // Return false if EOF is encountered
	}
	g := make(map[int]map[int]struct{}) // Initialize an empty graph
	seen := make(map[int]struct{})       // Initialize an empty set to keep track of visited nodes
	for i := 1; i <= n; i++ {            // Initialize the graph with empty sets for each node
		g[i] = make(map[int]struct{})
	}
	for j := 0; j < m; j++ { // Read each edge and add it to the graph
		var a, b int
		_, err := fmt.Scan(&a, &b)
		if err != nil {
			return false
		}
		g[a][b] = struct{}{}
		g[b][a] = struct{}{}
	}
	ans := 0 // Initialize the answer variable
	for i := 1; i <= n; i++ { // Traverse each node in the graph
		if _, ok := seen[i]; !ok { // If the node is not seen, perform DFS
			nodes, edges := dfs(g, seen, i) // Get the count of nodes and edges
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges { // Check the conditions
				ans++ // Increment the answer if the conditions are met
			}
		}
	}
	if (n - ans)%2 == 1 { // Check if the number of disconnected components is odd
		ans++ // Increment the answer if necessary
	}
	fmt.Println(ans) // Print the final answer
	return true      // Return true to continue the loop
}

func main() {
	for solve() { // Continuously call solve until it returns false
	}
}

// <END-OF-CODE>
