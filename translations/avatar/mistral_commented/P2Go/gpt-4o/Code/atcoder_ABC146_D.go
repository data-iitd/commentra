package main

import (
	"container/list"
	"fmt"
)

func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	// Initialize visited array and queue
	visited := make([]int, N)
	queue := list.New()

	// Initialize variables for coloring nodes
	K := -1
	node2color := make([]int, N)
	for i := range node2color {
		node2color[i] = -1
	}

	// Add starting node to the queue and mark it as visited
	queue.PushBack(v)
	visited[v] = 1

	// BFS algorithm
	for queue.Len() > 0 {
		// Dequeue the next node from the queue
		q := queue.Remove(queue.Front()).(int)

		// Initialize color for the current node
		color := 0

		// Traverse through all neighbors of the current node
		for _, nex := range G[q] {
			// Skip if the neighbor is already visited
			if visited[nex] != 0 {
				continue
			}

			// Mark the neighbor as visited and assign it a color
			visited[nex] = 1
			color++

			// If the color of the current node is same as its neighbor, assign a new color to the neighbor
			if color == node2color[q] {
				color++
			}

			// Update node2color and E map with the new color
			if q < nex {
				E[[2]int{q, nex}] = color
			} else {
				E[[2]int{nex, q}] = color
			}
			node2color[nex] = color

			// Add the neighbor to the queue
			queue.PushBack(nex)
		}

		// Update the maximum color found so far
		if color > K {
			K = color
		}
	}

	// Return the maximum color
	return K
}

func main() {
	// Read number of nodes from the input
	var N int
	fmt.Scan(&N)

	// Initialize graph as a slice of slices and empty map for edges
	G := make([][]int, N)
	E := make(map[[2]int]int)

	// Read edges from the input and add them to the graph
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to zero-based index
		b-- // Convert to zero-based index
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[[2]int{a, b}] = 0
	}

	// Call bfs function and print the result
	K := bfs(0, N, G, E)
	fmt.Println(K)

	// Print colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
