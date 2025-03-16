
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function starts here
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of nodes in the graph:")
	// Read the number of nodes N from the standard input
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the indices of the two nodes:")
	// Read the indices u and v of the two nodes from the standard input
	u, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	v, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize the adjacency lists for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}

	// Read the edges of the graph from the standard input and add them to the adjacency lists
	fmt.Println("Enter the edges of the graph:")
	for i := 0; i < N-1; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		// Add the edge between nodes a and b to both adjacency lists
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
	}

	// Initialize the distance arrays d and e for depth-first search
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = 1000000000
	}
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = 1000000000
	}

	// Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
	dfs(u-1, d, edges)
	dfs(v-1, e, edges)

	// Find the maximum difference between the distances of any node from u and v
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}

	// Print the result: the maximum difference between the distances of any node from u and v
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

// Depth-first search recursive helper method
func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == 1000000000 {
			// Mark the current node as visited and update the distance of its neighbors
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

