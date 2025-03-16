
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initializing the visited list and other variables
	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0
	g := make([][]int, n+1)

	// Function to perform DFS traversal from a given vertex 'x'
	dfs := func(x int) bool {
		// Creating an empty stack and initializing a flag
		stk := make([]int, 0)
		flag := true

		// Pushing the current vertex 'x' into the stack with color '1'
		stk = append(stk, x)
		stk = append(stk, 1)

		// Traversing the graph until the stack is empty
		for len(stk) > 0 {
			u := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			col := stk[len(stk)-1]

			// If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
			if vis[u]!= 0 {
				flag = flag && (vis[u] == col)
				continue
			}

			// Mark the current vertex 'u' as visited with the current color 'col'
			vis[u] = col

			// Recursively traverse all the adjacent vertices of 'u'
			for _, v := range g[u] {
				stk = append(stk, v)
				stk = append(stk, 3-col)
			}
		}

		// Return the flag indicating whether all vertices in the connected component have the same color or not
		return flag
	}

	// Adding edges to the graph
	for i := 0; i < m; i++ {
		u, v := readInt()
		// Adding an edge between vertices 'u' and 'v' in both the adjacency lists
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	// Finding the number of isolated vertices and connected components
	for i := 1; i <= n; i++ {
		// If the current vertex 'i' is not visited yet
		if vis[i] == 0 {
			// If the current vertex 'i' has no edges, then it is an isolated vertex
			if len(g[i]) == 0 {
				ci++
			} else {
				// Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
				if dfs(i) {
					cb++
				} else {
					cc++
				}
			}
		}
	}

	// Calculating and printing the final answer
	fmt.Println(ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb)
}

func readInt() (int, error) {
	var num int
	var err error
	reader := bufio.NewReader(os.Stdin)
	str, err := reader.ReadString('\n')
	if err!= nil {
		return 0, err
	}
	num, err = strconv.Atoi(strings.TrimSpace(str))
	if err!= nil {
		return 0, err
	}
	return num, nil
}

