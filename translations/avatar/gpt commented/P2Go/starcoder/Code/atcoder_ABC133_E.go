package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a type for a graph using map to store adjacency lists
type graph map[int][]int

// Define a recursive function to perform depth-first search (DFS) and count valid colorings
func dfs(g graph, fro, to, f int) int {
	caseNum := f  // Initialize case number with the current color
	colorNum := K - 1 if f == K else K - 2  // Determine the number of available colors for the next node

	// Iterate through all adjacent nodes in the graph
	for _, u := range g[fro] {
		if u == to {  // Skip the node we came from to avoid cycles
			continue
		}
		pat := dfs(g, u, fro, colorNum)  // Recursively call DFS for the adjacent node
		if pat == 0 {  // If no valid coloring is found, break out
			caseNum = 0
			break
		}
		caseNum = caseNum * pat % mod  // Update the case number with the valid patterns found
		colorNum -= 1  // Decrease the available colors for the next node

	}

	return caseNum  // Return the total valid colorings found
}

func main() {
	// Read the number of nodes (N) and the number of colors (K) from input
	reader := bufio.NewReader(os.Stdin)
	N, K, _ := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	N, K = strconv.Atoi(N), strconv.Atoi(K)

	// Build the graph by reading N-1 edges
	g := make(graph)
	for i := 0; i < N-1; i++ {
		a, b := strings.Split(strings.TrimSpace(readLine(reader)), " ")
		a, b = strconv.Atoi(a), strconv.Atoi(b)
		g[a-1] = append(g[a-1], b-1)  // Add edge from a to b (0-indexed)
		g[b-1] = append(g[b-1], a-1)  // Add edge from b to a (0-indexed)

	}

	// Start the DFS from the root node (0) with no parent (-1) and K colors
	ans := dfs(g, 0, -1, K)

	// Print the final answer which is the number of valid colorings
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

