
package main

import "fmt"

func main() {
	// Read input: number of nodes N and color limit K
	var N, K int
	fmt.Scanf("%d %d", &N, &K)

	// Initialize an empty graph using map
	graph := make(map[int][]int)

	// Read edges between nodes and add them to the graph
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}

	// Define a recursive function dfs to calculate the answer
	mod := 1000000007
	var dfs func(fro, to, f int) int
	dfs = func(fro, to, f int) int {
		// Initialize case number and color number
		caseNum := 1
		if f == K {
			caseNum = 0
		}
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}

		// Iterate through the neighbors of the current node
		for _, u := range graph[fro] {
			// Skip the target node
			if u == to {
				continue
			}

			// Recursively call dfs on the neighbor and update case number
			pat := dfs(u, fro, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = caseNum * pat % mod
			colorNum -= 1
		}

		// Return the final case number
		return caseNum
	}

	// Call the dfs function with initial values and print the result
	ans := dfs(0, -1, K)
	fmt.Println(ans)
}

