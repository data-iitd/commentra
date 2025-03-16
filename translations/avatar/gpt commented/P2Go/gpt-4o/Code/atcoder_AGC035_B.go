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
	var N, M int
	fmt.Scan(&N, &M)

	edges := make([]map[int]struct{}, N)
	for i := range edges {
		edges[i] = make(map[int]struct{})
	}
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		edges[a][b] = struct{}{}
		edges[b][a] = struct{}{}
		degs[a]++
		degs[b]++
	}

	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	Q := &MinHeap{}
	for i, d := range degs {
		heap.Push(Q, Node{degree: d, index: i})
	}

	for Q.Len() > 0 {
		u := heap.Pop(Q).(Node).index

		if flag[u] {
			continue
		}

		flag[u] = true

		for v := range edges[u] {
			delete(edges[v], u) // Remove the edge from v to u
			if parity[u] != 0 {
				fmt.Println(u+1, v+1) // Print the edge in one format
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1) // Print the edge in the alternate format
				parity[v] = 1 - parity[v]
			}
			degs[v]-- // Decrement the degree of neighbor v
			heap.Push(Q, Node{degree: degs[v], index: v}) // Push updated degree back to the queue
		}
	}
}

// <END-OF-CODE>
