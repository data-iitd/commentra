package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read number of vertices
	var N int
	fmt.Fscan(reader, &N)

	// Initialize adjacency list with empty slices for each vertex
	adj := make([][]int, N+1)

	// Read edges and add them to the adjacency list
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		// Add edge between vertices a and b in both directions
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	// Initialize empty slice for BFS traversal
	que := []int{}

	// Mark starting vertex as visited and add it to the queue
	que = append(que, 1)

	// Initialize slices to store parent, seen, and child count for each vertex
	seen := make([]int, N+1)
	par := make([]int, N+1)
	child_num := make([]int, N+1)

	// BFS traversal starting from the starting vertex
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		// Iterate through neighbors of the current vertex
		for _, u := range adj[v] {
			// If neighbor is not yet visited, mark it as visited, update parent and child count
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				child_num[v]++
				que = append(que, u)
			}
		}
	}

	// Initialize empty slice for storing vertices in topological order
	seq := []int{}

	// Find vertices with no incoming edges and add them to the sequence
	for i := 1; i <= N; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}

	// Topological sort using the sequence of vertices with no incoming edges
	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		// If parent of the current vertex is not yet processed, print "First" and exit
		if seen[par[c]] == 0 {
			fmt.Println("First")
			return
		}
		// Mark parent as not visited and update child count of its parent
		seen[par[c]] = 0
		child_num[par[par[c]]]--
		// If the parent of the parent has no children, add it to the sequence
		if child_num[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}

	// Print "Second" if all vertices have been processed
	fmt.Println("Second")
}

