package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of nodes in the tree
	var N int
	fmt.Fscan(reader, &N)

	// Initialize adjacency list for the tree
	adj := make([][]int, N+1)

	// Read edges and build the adjacency list
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	// Initialize a queue for BFS and mark the starting node
	que := []int{1}

	// Array to keep track of visited nodes
	seen := make([]int, N+1)
	seen[1] = 1 // Mark the root node as seen

	// Array to store parent of each node
	par := make([]int, N+1)

	// Array to count the number of children for each node
	child_num := make([]int, N+1)

	// Perform BFS to populate parent and child count information
	for len(que) > 0 {
		v := que[0] // Get the current node
		que = que[1:]
		for _, u := range adj[v] { // Iterate through adjacent nodes
			if seen[u] == 0 { // If the node has not been visited
				seen[u] = 1 // Mark it as seen
				par[u] = v  // Set the parent of the node
				child_num[v]++ // Increment the child count for the parent
				que = append(que, u) // Add the node to the queue for further exploration
			}
		}
	}

	// Initialize a slice to process leaf nodes
	seq := []int{}

	// Identify all leaf nodes (nodes with no children)
	for i := 1; i <= N; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}

	// Process the leaf nodes in reverse order
	for len(seq) > 0 {
		c := seq[len(seq)-1] // Get the current leaf node
		seq = seq[:len(seq)-1]
		seen[c] = 0 // Mark the leaf node as unseen
		if seen[par[c]] == 0 { // Check if the parent is unseen
			fmt.Println("First") // If so, print 'First' and exit
			return
		}
		seen[par[c]] = 0 // Mark the parent as unseen
		child_num[par[par[c]]]-- // Decrement the child count of the grandparent
		if child_num[par[par[c]]] == 0 { // If the grandparent has no children left
			seq = append(seq, par[par[c]]) // Add the grandparent to the sequence for processing
		}
	}

	// If all nodes are processed without triggering 'First', print 'Second'
	fmt.Println("Second")
}
