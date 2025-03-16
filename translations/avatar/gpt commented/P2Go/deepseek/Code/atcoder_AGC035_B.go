package main

import (
	"container/heap"
	"fmt"
	"sort"
)

// Define a priority queue (min-heap)
type PriorityQueue [][]int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i][0] < pq[j][0]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.([]int)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize adjacency list for edges, degree count, parity, and visited flag
	edges := make([][]int, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)

	// Read edges and populate the adjacency list and degree counts
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a]++
		degs[b]++
	}

	// If the number of edges is odd, it's impossible to pair them
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize a priority queue with degrees of nodes
	pq := &PriorityQueue{}
	for i := 0; i < N; i++ {
		heap.Push(pq, []int{degs[i], i})
	}

	// Process the nodes in the priority queue
	for pq.Len() > 0 {
		_, u := heap.Pop(pq).([]int)

		// If the node has already been processed, skip it
		if flag[u] {
			continue
		}

		flag[u] = true

		// Iterate through the neighbors of the current node
		for _, v := range edges[u] {
			edges[v] = remove(edges[v], u)
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			heap.Push(pq, []int{degs[v], v})
		}
	}
}

// Helper function to remove an element from a slice
func remove(slice []int, s int) []int {
	return append(slice[:s], slice[s+1:]...)
}
