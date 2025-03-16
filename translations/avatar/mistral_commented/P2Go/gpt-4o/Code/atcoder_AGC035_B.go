package main

import (
	"container/heap"
	"fmt"
)

type Edge struct {
	vertex int
}

type MinHeap []Edge

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].vertex < h[j].vertex }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Edge))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize adjacency list for each vertex
	edges := make([]map[int]struct{}, N)
	for i := range edges {
		edges[i] = make(map[int]struct{})
	}

	// Initialize degree array
	degs := make([]int, N)

	// Initialize parity array
	parity := make([]int, N)

	// Initialize visited flag array
	flag := make([]bool, N)

	// Read edges and populate adjacency list and degrees
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b--
		edges[a][b] = struct{}{}
		edges[b][a] = struct{}{}
		degs[a]++
		degs[b]++
	}

	// Check if number of edges is even
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize min heap
	Q := &MinHeap{}
	for i, d := range degs {
		heap.Push(Q, Edge{vertex: d})
	}

	// Iterate until the heap is empty
	for Q.Len() > 0 {
		// Get vertex with minimum degree
		u := heap.Pop(Q).(Edge).vertex
		if flag[u] {
			continue
		}
		flag[u] = true

		// Iterate through adjacent vertices
		for v := range edges[u] {
			if flag[v] {
				continue
			}
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			heap.Push(Q, Edge{vertex: degs[v]})
		}
	}
}

// <END-OF-CODE>
