package main

import (
	"container/heap"
	"fmt"
	"sort"
)

// Define a custom type for the heap
type Node struct {
	degree int
	index  int
}

type MinHeap []*Node

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].degree < h[j].degree }
func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].index = i
	h[j].index = j
}

func (h *MinHeap) Push(x interface{}) {
	node := x.(*Node)
	node.index = len(*h)
	*h = append(*h, node)
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	node := old[n-1]
	node.index = -1
	*h = old[0 : n-1]
	return node
}

func main() {
	// Step 1: Input Reading and Initialization
	// Read the number of nodes N and the number of edges M
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize adjacency lists for each node
	edges := make([][]int, N)

	// Initialize degrees for each node
	degs := make([]int, N)

	// Initialize parity for each node
	parity := make([]int, N)

	// Initialize flag to mark visited nodes
	flag := make([]bool, N)

	// Step 2: Edge and Degree Calculation
	// Read each edge and update adjacency lists and degree lists
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a] += 1
		degs[b] += 1
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	h := &MinHeap{}
	for i := 0; i < N; i++ {
		heap.Push(h, &Node{degree: degs[i], index: i})
	}

	// Step 4: Main Loop
	// Process nodes from the heap
	for h.Len() > 0 {
		node := heap.Pop(h).(*Node)
		u := node.index

		// If the node has already been processed, skip to the next iteration
		if flag[u] {
			continue
		}

		// Mark the node as processed
		flag[u] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[u] {
			edges[v] = remove(edges[v], u)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v] -= 1
			heap.Push(h, &Node{degree: degs[v], index: v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// Helper function to remove an element from a slice
func remove(slice []int, s int) []int {
	return append(slice[:s], slice[s+1:]...)
}

