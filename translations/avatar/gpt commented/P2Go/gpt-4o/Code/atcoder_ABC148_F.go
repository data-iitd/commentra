package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7
const INF = 1e18

var g [][]int
var taDist []int
var aoDist []int

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, ta, ao int
	fmt.Fscan(reader, &n, &ta, &ao)
	ta-- // Adjusting to zero-based index
	ao-- // Adjusting to zero-based index

	g = make([][]int, n)

	// Read the edges of the graph and populate the adjacency list
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a-- // Adjusting to zero-based index
		b-- // Adjusting to zero-based index
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	// Initialize distance arrays for ta and ao
	taDist = make([]int, n)
	aoDist = make([]int, n)
	for i := range taDist {
		taDist[i] = -1 // Use -1 to indicate unvisited
		aoDist[i] = -1 // Use -1 to indicate unvisited
	}
	taDist[ta] = 0 // Distance to itself is 0
	aoDist[ao] = 0 // Distance to itself is 0

	// Perform DFS from ao to calculate distances
	aoDFS(ao)

	// Perform DFS from ta to calculate distances
	taDFS(ta)

	// Initialize result variable to track the maximum distance
	res := 0

	// Calculate the maximum distance where ta's distance is less than or equal to ao's distance
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] {
			continue // Skip if ta is further away than ao
		}
		res = max(res, aoDist[i]) // Update result with the maximum distance
	}

	// Print the result, subtracting 1 to adjust for zero-based indexing
	fmt.Fprintln(writer, res-1)
}

func aoDFS(node int) {
	for _, v := range g[node] {
		if aoDist[v] != -1 { // Skip if already visited
			continue
		}
		aoDist[v] = aoDist[node] + 1 // Update distance
		aoDFS(v)                      // Recursive DFS call
	}
}

func taDFS(node int) {
	for _, v := range g[node] {
		if taDist[v] != -1 { // Skip if already visited
			continue
		}
		taDist[v] = taDist[node] + 1 // Update distance
		taDFS(v)                     // Recursive DFS call
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
