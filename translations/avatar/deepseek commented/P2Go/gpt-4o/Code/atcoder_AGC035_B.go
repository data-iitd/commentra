package main

import (
	"container/heap"
	"fmt"
)

type Node struct {
	degree int
	index  int
}

type MinHeap []Node

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].degree < h[j].degree }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Node))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	// Step 1: Input Reading and Initialization
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize adjacency lists for each node
	edges := make([]map[int]struct{}, N)
	for i := range edges {
		edges[i] = make(map[int]struct{})
	}

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
		edges[a-1][b-1] = struct{}{}
		edges[b-1][a-1] = struct{}{}
		degs[a-1]++
		degs[b-1]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	Q := &MinHeap{}
	for i, d := range degs {
		heap.Push(Q, Node{degree: d, index: i})
	}

	// Step 4: Main Loop
	// Process nodes from the heap
	for Q.Len() > 0 {
		u := heap.Pop(Q).(Node).index

		// If the node has already been processed, skip to the next iteration
		if flag[u] {
			continue
		}

		// Mark the node as processed
		flag[u] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for v := range edges[u] {
			delete(edges[v], u)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			heap.Push(Q, Node{degree: degs[v], index: v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// <END-OF-CODE>
