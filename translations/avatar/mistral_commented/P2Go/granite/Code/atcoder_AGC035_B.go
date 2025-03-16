
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize variables and data structures
	var (
		N, M int
		edges []int
		degs  []int
		parity []int
		flag   []bool
		Q      [][2]int
	)

	// Read input number of vertices N and number of edges M
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &N, &M)

	// Initialize empty sets for each vertex representing its adjacent vertices
	edges = make([]int, N)
	degs = make([]int, N)
	parity = make([]int, N)
	flag = make([]bool, N)

	// Read edges from input and add them to their respective sets and update their degrees
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &a, &b)
		a--
		b--
		edges[a] |= 1 << b
		edges[b] |= 1 << a
		degs[a]++
		degs[b]++
	}

	// Check if number of edges is even, if not print -1 and exit
	if M%2!= 0 {
		fmt.Println(-1)
		return
	}

	// Initialize empty list Q to store vertices based on their degrees
	Q = make([][2]int, N)

	// Iterate through all vertices and add them to Q based on their degrees
	for i := 0; i < N; i++ {
		Q[i] = [2]int{degs[i], i}
	}

	// Sort Q based on degrees
	sort.Slice(Q, func(i, j int) bool {
		return Q[i][0] < Q[j][0]
	})

	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0][1]
		Q = Q[1:]
		// Skip if vertex is already visited
		if flag[u] {
			continue
		}
		// Mark vertex as visited
		flag[u] = true
		// Iterate through all adjacent vertices and print their edges and update their parity
		for v := 0; v < N; v++ {
			// Skip if vertex is already visited
			if flag[v] {
				continue
			}
			// Print edge and update parity of both vertices
			if parity[u]!= 0 && edges[u]&(1<<v)!= 0 {
				fmt.Printf("%d %d\n", u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Printf("%d %d\n", v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			// Decrease degree of adjacent vertex and add it to Q
			degs[v]--
			if degs[v] > 0 {
				Q = append(Q, [2]int{degs[v], v})
			}
		}
	}
}

