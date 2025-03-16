
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize the scanner to read input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of nodes (N) and the two specific nodes (u and v)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	u, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	v, _ := strconv.Atoi(sc.Text())
	u-- // Convert to zero-based index
	v-- // Convert to zero-based index

	// Create an adjacency list to represent the edges of the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}

	// Read the edges and populate the adjacency list
	for i := 0; i < N-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		a-- // Convert to zero-based index
		b-- // Convert to zero-based index
		edges[a] = append(edges[a], b) // Add edge from a to b
		edges[b] = append(edges[b], a) // Add edge from b to a (undirected graph)
	}

	// Initialize distance array for the first node (u)
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = 100000000 // Set initial distances to infinity
	}
	d[u] = 0 // Distance to itself is 0

	// Perform DFS from node u to calculate distances
	dfs(u, d, edges)

	// Initialize distance array for the second node (v)
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = 100000000 // Set initial distances to infinity
	}
	e[v] = 0 // Distance to itself is 0

	// Perform DFS from node v to calculate distances
	dfs(v, e, edges)

	// Find the maximum distance from node u to any node that is closer to v
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] { // Check if node i is closer to u than to v
			if e[i] > q { // Update q if the distance to v is greater
				q = e[i]
			}
		}
	}

	// Output the result based on the maximum distance found
	if q <= 0 {
		fmt.Println(0) // If no valid distance found, print 0
	} else {
		fmt.Println(q - 1) // Print the maximum distance minus 1
	}
}

// Depth-first search (DFS) to calculate distances from a given node
func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == 100000000 { // If the node has not been visited
			d[nu] = d[u] + 1 // Update the distance
			dfs(nu, d, edges) // Recursively visit the next node
		}
	}
}

// END-OF-CODE