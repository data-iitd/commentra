package main

import (
	"container/heap"
	"fmt"
	"sort"
)

// Define a custom type for the priority queue
type Vertex struct {
	index int
	degree int
}

type PriorityQueue []Vertex

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].degree < pq[j].degree
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	vertex := x.(Vertex)
	vertex.index = n
	*pq = append(*pq, vertex)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	vertex := old[n-1]
	vertex.index = -1 // for safety
	*pq = old[0 : n-1]
	return vertex
}

func main() {
	// Take input number of vertices N and number of edges M
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize empty sets for each vertex representing its adjacent vertices
	edges := make([][]int, N)

	// Initialize degree array to keep track of number of edges for each vertex
	degs := make([]int, N)

	// Initialize parity array to keep track of parity of each vertex
	parity := make([]int, N)

	// Initialize flag array to keep track of visited vertices
	flag := make([]bool, N)

	// Read edges from input and add them to their respective sets and update their degrees
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		// Add edge between vertices a and b in both their sets
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		// Update degrees of both vertices
		degs[a-1]++
		degs[b-1]++
	}

	// Check if number of edges is even, if not print -1 and exit
	if M % 2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize empty list Q to store vertices based on their degrees
	pq := &PriorityQueue{}

	// Iterate through all vertices and add them to Q based on their degrees
	for i := 0; i < N; i++ {
		heap.Push(pq, Vertex{i, degs[i]})
	}

	// Iterate through Q until it is empty
	for pq.Len() > 0 {
		// Get vertex with minimum degree from Q
		vertex := heap.Pop(pq).(Vertex)
		u := vertex.index
		// Skip if vertex is already visited
		if flag[u] {
			continue
		}
		// Mark vertex as visited
		flag[u] = true
		// Iterate through all adjacent vertices and print their edges and update their parity
		for _, v := range edges[u] {
			// Skip if vertex is already visited
			if flag[v] {
				continue
			}
			// Print edge and update parity of both vertices
			if parity[u] != 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			// Decrease degree of adjacent vertex and add it to Q
			degs[v]--
			heap.Push(pq, Vertex{v, degs[v]})
		}
	}
}
