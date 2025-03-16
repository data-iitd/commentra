package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Set recursion limit to prevent stack overflow
const N = 1000000

var (
	graph [N]int
	N, K  int
)

func main() {
	// Read the number of nodes and the number of colors
	fmt.Scanf("%d %d\n", &N, &K)

	// Construct the graph by reading edges
	for i := 0; i < N-1; i++ {
		a, b := readInt(), readInt()
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}

	// Set the modulo value to prevent overflow
	mod := int(1e9) + 7

	// Define the DFS function to calculate the number of valid colorings
	var dfs func(fro, to, f int) int
	dfs = func(fro, to, f int) int {
		caseNum := f  // Initialize the number of valid colorings with the initial number of colors
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, u := range graph[fro] {
			if u == to {
				continue
			}
			pat := dfs(u, fro, colorNum)  // Recursively call dfs for the neighbor
			if pat == 0 {
				caseNum = 0  // If no valid colorings, set the current number to 0
				break
			}
			caseNum = (caseNum * pat) % mod  // Multiply the current number of valid colorings by the recursive result
			colorNum--
		}
		return caseNum
	}

	ans := dfs(0, -1, K)  // Call the dfs function starting from the root node with the initial number of colors
	fmt.Println(ans)  // Print the final result
}

// Read a single integer
func readInt() int {
	var n int
	fmt.Scanf("%d\n", &n)
	return n
}

