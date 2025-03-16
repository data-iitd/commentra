
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Constants for the maximum number of vertices in the graph.
const MN = 520

// BitMatching template structure for solving Bipartite Graph Matching problem.
type BitMatching struct {
	G [2 * MN][]int // Adjacency list for the graph.
	match [2 * MN]int // Stores the matching result for each vertex.
	used [2 * MN]bool // Stores whether a vertex is being processed or not.
}

// Initializes the graph data structures.
func (bm *BitMatching) init() {
	for i := 0; i < 2*MN; i++ {
		bm.G[i] = bm.G[i][:0] // Clears the adjacency list for the current vertex.
	}
}

// Adds an edge between two vertices in the graph.
func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+MN) // Adds the destination vertex to the adjacency list of the source vertex.
	bm.G[b+MN] = append(bm.G[b+MN], a) // Adds the source vertex to the adjacency list of the destination vertex.
}

// Performs Depth First Search (DFS) algorithm to find a matching between vertices.
func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true // Marks the current vertex as being processed.

	for i := 0; i < len(bm.G[v]); i++ {
		u := bm.G[v][i] // Gets the neighboring vertex.
		w := bm.match[u] // Gets the matching vertex.

		if w < 0 || (!bm.used[w] && bm.dfs(w)) { // If the neighboring vertex is not matched or can be matched, update the matching result.
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false // If no matching is found, return false.
}

// Executes the Bipartite Graph Matching algorithm.
func (bm *BitMatching) exec() int {
	res := 0 // Initializes the result variable.
	for i := 0; i < 2*MN; i++ {
		bm.match[i] = -1 // Initializes the matching array with -1.
	}

	for v := 0; v < MN; v++ { // Iterates through all vertices in the graph.
		if bm.match[v] < 0 { // If the current vertex is not matched, perform DFS to find a matching.
			for i := 0; i < 2*MN; i++ {
				bm.used[i] = false // Initializes the used array with false.
			}
			if bm.dfs(v) {
				res++
			}
		}
	}
	return res // Returns the number of matched vertices.
}

// Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
func gcd(a, b int) int {
	if b == 0 {
		return a // Base case: if b is 0, return a.
	}
	return gcd(b, a%b) // Recursive case: call gcd with b and the remainder of a divided by b.
}

// Reads input data and performs the Bipartite Graph Matching algorithm.
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		var n, m int // Reads the number of vertices and edges in the graph.
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &n, &m)

		if n == 0 {
			break // If the number of vertices is 0, breaks the loop.
		}

		bm := new(BitMatching) // Instantiates the BitMatching template structure with the given constant.
		bm.init() // Initializes the graph data structures.

		a := make([]int, n) // Reads the input data for vertices a.
		b := make([]int, m) // Reads the input data for vertices b.

		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i], _ = strconv.Atoi(scanner.Text())
		}

		for i := 0; i < m; i++ {
			scanner.Scan()
			b[i], _ = strconv.Atoi(scanner.Text())
		}

		for i := 0; i < n; i++ { // Iterates through all vertices a.
			for j := 0; j < m; j++ { // Iterates through all vertices b.
				if gcd(a[i], b[j]) != 1 { // If the GCD of a[i] and b[j] is not 1, adds an edge between them.
					bm.add(i, j)
				}
			}
		}

		fmt.Println(bm.exec()) // Executes the Bipartite Graph Matching algorithm and prints the result.
	}
}

