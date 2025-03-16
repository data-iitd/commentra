

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Read the input values for N, u, and v
	N, _ := strconv.Atoi(read())
	u, _ := strconv.Atoi(read())
	v, _ := strconv.Atoi(read())
	u--
	v--

	// Step 2: Initialize the adjacency list for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}

	// Step 3: Read the edges of the graph and populate the adjacency list
	for i := 0; i < N-1; i++ {
		a, _ := strconv.Atoi(read())
		b, _ := strconv.Atoi(read())
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Step 4: Initialize the distance array for the first DFS traversal starting from node u
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = 100000000
	}
	d[u] = 0

	// Step 5: Perform DFS from node u to populate the distance array d
	dfs(u, d, edges)

	// Step 6: Initialize the distance array for the second DFS traversal starting from node v
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = 100000000
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
		if d[nu] == 100000000 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

// Helper method to read input from the standard input
func read() string {
	buf := make([]byte, 0)
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		buf = scanner.Bytes()
	}
	return string(buf)
}

