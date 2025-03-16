package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of nodes N
	var N int
	fmt.Scan(&N)

	// Initialize adjacency list to store the graph
	adj := make([][]int, N+1)
	for i := range adj {
		adj[i] = make([]int, 0)
	}

	// Read N-1 edges and populate the adjacency list
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	// Initialize deque for BFS and seen array to track visited nodes
	que := make([]int, 0)
	seen := make([]int, N+1)
	que = append(que, 1)
	seen[1] = 1

	// Array to store parent nodes
	par := make([]int, N+1)

	// Array to count the number of children for each node
	child_num := make([]int, N+1)

	// Perform BFS to find parent and child relationships
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				child_num[v] += 1
				que = append(que, u)
			}
		}
	}

	// Find leaf nodes (nodes with no children)
	seq := make([]int, 0)
	for i := 1; i <= N; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}

	// Process leaf nodes to determine the winning strategy
	for len(seq) > 0 {
		c := seq[0]
		seq = seq[1:]
		seen[c] = 0
		if seen[par[c]] == 0 {
			fmt.Println("First")
			return
		}
		seen[par[c]] = 0
		child_num[par[par[c]]] -= 1
		if child_num[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}

	// If no winning strategy is found for the first player, print 'Second'
	fmt.Println("Second")
}

