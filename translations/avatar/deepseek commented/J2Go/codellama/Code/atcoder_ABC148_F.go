
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Read the input values for N, u, and v
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	u, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	v, _ := strconv.Atoi(scanner.Text())

	// Step 2: Initialize the adjacency list for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}

	// Step 3: Read the edges of the graph and populate the adjacency list
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
	}

	// Step 4: Initialize the distance array for the first DFS traversal starting from node u
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = -1
	}
	d[u] = 0

	// Step 5: Perform DFS from node u to populate the distance array d
	dfs(u, d, edges)

	// Step 6: Initialize the distance array for the second DFS traversal starting from node v
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = -1
	}
	e[v] = 0

	// Step 7: Perform DFS from node v to populate the distance array e
	dfs(v, e, edges)

	// Step 8: Find the maximum value of e[i] where d[i] < e[i]
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}

	// Step 9: Print the result based on the maximum value found
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

// Helper method to perform DFS and populate the distance array
func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == -1 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

// 