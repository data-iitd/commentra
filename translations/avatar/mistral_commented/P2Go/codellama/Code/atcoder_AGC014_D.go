// Import necessary packages
package main

import (
	"fmt"
	"os"
)

// Function to read input
func input() []byte {
	return []byte(os.Stdin.ReadString('\n'))
}

// Define number of vertices in the graph
const N = 100000

// Initialize adjacency list with empty lists for each vertex
var adj [N + 1][]int

// Read edges and add them to the adjacency list
func readEdges() {
	for i := 0; i < N-1; i++ {
		a, b := 0, 0
		fmt.Sscanf(string(input()), "%d %d", &a, &b)
		// Add edge between vertices a and b in both directions
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
}

// Initialize empty deque for BFS traversal
var que []int

// Mark starting vertex as visited and add it to the queue
func init() {
	que = append(que, 1)
}

// Initialize lists to store parent, seen, and child count for each vertex
var seen [N + 1]int
var par [N + 1]int
var childNum [N + 1]int

// BFS traversal starting from the starting vertex
func bfs() {
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		// Iterate through neighbors of the current vertex
		for _, u := range adj[v] {
			// If neighbor is not yet visited, mark it as visited, update parent and child count
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				childNum[v]++
				que = append(que, u)
			}
		}
	}
}

// Initialize empty deque for storing vertices in topological order
var seq []int

// Find vertices with no incoming edges and add them to the sequence
func findVertices() {
	for i := 1; i <= N; i++ {
		if childNum[i] == 0 {
			seq = append(seq, i)
		}
	}
}

// Topological sort using the sequence of vertices with no incoming edges
func topoSort() {
	for len(seq) > 0 {
		c := seq[0]
		seq = seq[1:]
		// If parent of the current vertex is not yet processed, print "First" and exit
		if seen[par[c]] == 0 {
			fmt.Println("First")
			os.Exit(0)
		}
		// Mark parent as not visited and update child count of its parent
		seen[par[c]] = 0
		childNum[par[par[c]]]--
		// If the parent of the parent has no children, add it to the sequence
		if childNum[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
}

// Main function
func main() {
	readEdges()
	bfs()
	findVertices()
	topoSort()
	fmt.Println("Second")
}

