
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of nodes N from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Read the indices u and v of the two nodes from the standard input
	scanner.Scan()
	u, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	v, _ := strconv.Atoi(scanner.Text())

	// Initialize the adjacency lists for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}

	// Read the edges of the graph from the standard input and add them to the adjacency lists
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		// Add the edge between nodes a and b to both adjacency lists
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Initialize the distance arrays d and e for depth-first search
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = -1
	}
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = -1
	}

	// Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
	dfs(u, d, edges)
	dfs(v, e, edges)

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
		if d[nu] == -1 {
			// Mark the current node as visited and update the distance of its neighbors
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

