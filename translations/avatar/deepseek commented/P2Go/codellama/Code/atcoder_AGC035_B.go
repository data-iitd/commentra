package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

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
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	Q := make([][2]int, 0)
	for i, d := range degs {
		Q = append(Q, [2]int{d, i})
	}
	heap.Init(Q)

	// Step 4: Main Loop
	// Process nodes from the heap
	for len(Q) > 0 {
		_, u := heap.Pop(Q).([2]int)

		// If the node has already been processed, skip to the next iteration
		if flag[u[1]] {
			continue
		}

		// Mark the node as processed
		flag[u[1]] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[u[1]] {
			edges[v] = append(edges[v][:u[1]], edges[v][u[1]+1:]...)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u[1]] != 0 {
				fmt.Println(u[1]+1, v+1)
				parity[u[1]] = 1 - parity[u[1]]
			} else {
				fmt.Println(v+1, u[1]+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			heap.Push(Q, [2]int{degs[v], v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// A heap implementation for the [2]int type
type IntHeap [][2]int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
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
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	Q := make([][2]int, 0)
	for i, d := range degs {
		Q = append(Q, [2]int{d, i})
	}
	heap.Init(Q)

	// Step 4: Main Loop
	// Process nodes from the heap
	for len(Q) > 0 {
		_, u := heap.Pop(Q).([2]int)

		// If the node has already been processed, skip to the next iteration
		if flag[u[1]] {
			continue
		}

		// Mark the node as processed
		flag[u[1]] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[u[1]] {
			edges[v] = append(edges[v][:u[1]], edges[v][u[1]+1:]...)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u[1]] != 0 {
				fmt.Println(u[1]+1, v+1)
				parity[u[1]] = 1 - parity[u[1]]
			} else {
				fmt.Println(v+1, u[1]+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			heap.Push(Q, [2]int{degs[v], v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// A heap implementation for the [2]int type
type IntHeap [][2]int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
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
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	Q := make([][2]int, 0)
	for i, d := range degs {
		Q = append(Q, [2]int{d, i})
	}
	heap.Init(Q)

	// Step 4: Main Loop
	// Process nodes from the heap
	for len(Q) > 0 {
		_, u := heap.Pop(Q).([2]int)

		// If the node has already been processed, skip to the next iteration
		if flag[u[1]] {
			continue
		}

		// Mark the node as processed
		flag[u[1]] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[u[1]] {
			edges[v] = append(edges[v][:u[1]], edges[v][u[1]+1:]...)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u[1]] != 0 {
				fmt.Println(u[1]+1, v+1)
				parity[u[1]] = 1 - parity[u[1]]
			} else {
				fmt.Println(v+1, u[1]+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			heap.Push(Q, [2]int{degs[v], v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// A heap implementation for the [2]int type
type IntHeap [][2]int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
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
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	Q := make([][2]int, 0)
	for i, d := range degs {
		Q = append(Q, [2]int{d, i})
	}
	heap.Init(Q)

	// Step 4: Main Loop
	// Process nodes from the heap
	for len(Q) > 0 {
		_, u := heap.Pop(Q).([2]int)

		// If the node has already been processed, skip to the next iteration
		if flag[u[1]] {
			continue
		}

		// Mark the node as processed
		flag[u[1]] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[u[1]] {
			edges[v] = append(edges[v][:u[1]], edges[v][u[1]+1:]...)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[u[1]] != 0 {
				fmt.Println(u[1]+1, v+1)
				parity[u[1]] = 1 - parity[u[1]]
			} else {
				fmt.Println(v+1, u[1]+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			heap.Push(Q, [2]int{degs[v], v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

// A heap implementation for the [2]int type
type IntHeap [][2]int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
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
	// Read each edge and update adjacency lists and 