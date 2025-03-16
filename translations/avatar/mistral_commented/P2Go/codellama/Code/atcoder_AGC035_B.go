// Import necessary libraries
package main

import (
	"fmt"
	"sort"
)

// Define a struct to represent a vertex
type Vertex struct {
	id    int
	deg   int
	edges []int
}

// Define a struct to represent a graph
type Graph struct {
	vertices []Vertex
}

// Define a struct to represent a priority queue
type PriorityQueue struct {
	vertices []Vertex
}

// Define a function to initialize a graph with N vertices
func NewGraph(N int) *Graph {
	// Initialize empty sets for each vertex representing its adjacent vertices
	edges := make([][]int, N)
	// Initialize degree array to keep track of number of edges for each vertex
	degs := make([]int, N)
	// Initialize parity array to keep track of parity of each vertex
	parity := make([]int, N)
	// Initialize flag array to keep track of visited vertices
	flag := make([]bool, N)
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Read edges from input and add them to their respective sets and update their degrees
	for i := 0; i < N-1; i++ {
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
	if N-1%2 != 0 {
		fmt.Println(-1)
		return nil
	}
	// Iterate through all vertices and add them to Q based on their degrees
	for i, d := range degs {
		Q = append(Q, Vertex{i, d, edges[i]})
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Skip if vertex is already visited
		if flag[u.id] {
			continue
		}
		// Mark vertex as visited
		flag[u.id] = true
		// Iterate through all adjacent vertices and print their edges and update their parity
		for i, v := range u.edges {
			// Skip if vertex is already visited
			if flag[v] {
				continue
			}
			// Print edge and update parity of both vertices
			if parity[u.id] != 0 && i == 0 {
				fmt.Println(u.id+1, v+1)
				parity[u.id] = 1 - parity[u.id]
			} else {
				fmt.Println(v+1, u.id+1)
				parity[v] = 1 - parity[v]
			}
			// Decrease degree of adjacent vertex and add it to Q
			degs[v]--
			Q = append(Q, Vertex{v, degs[v], edges[v]})
		}
	}
	return nil
}

// Define a function to initialize a priority queue with N vertices
func NewPriorityQueue(N int) *PriorityQueue {
	return &PriorityQueue{make([]Vertex, 0)}
}

// Define a function to add a vertex to a priority queue
func (pq *PriorityQueue) Push(v Vertex) {
	pq.vertices = append(pq.vertices, v)
}

// Define a function to remove a vertex from a priority queue
func (pq *PriorityQueue) Pop() Vertex {
	v := pq.vertices[0]
	pq.vertices = pq.vertices[1:]
	return v
}

// Define a function to check if a priority queue is empty
func (pq *PriorityQueue) Empty() bool {
	return len(pq.vertices) == 0
}

// Define a function to get the minimum degree vertex from a priority queue
func (pq *PriorityQueue) Min() Vertex {
	return pq.vertices[0]
}

// Define a function to update the degree of a vertex in a priority queue
func (pq *PriorityQueue) Update(v Vertex) {
	for i, u := range pq.vertices {
		if u.id == v.id {
			pq.vertices[i] = v
			break
		}
	}
}

// Define a function to print the edges of a graph
func (g *Graph) PrintEdges() {
	for _, v := range g.vertices {
		for _, u := range v.edges {
			fmt.Println(v.id+1, u+1)
		}
	}
}

// Define a function to print the parity of a graph
func (g *Graph) PrintParity() {
	for _, v := range g.vertices {
		fmt.Println(v.id+1, v.deg)
	}
}

// Define a function to print the vertices of a graph
func (g *Graph) PrintVertices() {
	for _, v := range g.vertices {
		fmt.Println(v.id+1)
	}
}

// Define a function to print the edges of a graph in a specific order
func (g *Graph) PrintEdgesOrdered() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Iterate through all adjacent vertices and print their edges
		for _, v := range u.edges {
			fmt.Println(u.id+1, v+1)
		}
	}
}

// Define a function to print the parity of a graph in a specific order
func (g *Graph) PrintParityOrdered() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print parity of vertex
		fmt.Println(u.id+1, u.deg)
	}
}

// Define a function to print the vertices of a graph in a specific order
func (g *Graph) PrintVerticesOrdered() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print vertex
		fmt.Println(u.id+1)
	}
}

// Define a function to print the edges of a graph in a specific order
func (g *Graph) PrintEdgesOrderedParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Iterate through all adjacent vertices and print their edges
		for _, v := range u.edges {
			fmt.Println(u.id+1, v+1)
		}
	}
}

// Define a function to print the parity of a graph in a specific order
func (g *Graph) PrintParityOrderedParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print parity of vertex
		fmt.Println(u.id+1, u.deg)
	}
}

// Define a function to print the vertices of a graph in a specific order
func (g *Graph) PrintVerticesOrderedParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print vertex
		fmt.Println(u.id+1)
	}
}

// Define a function to print the edges of a graph in a specific order
func (g *Graph) PrintEdgesOrderedParityParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Iterate through all adjacent vertices and print their edges
		for _, v := range u.edges {
			fmt.Println(u.id+1, v+1)
		}
	}
}

// Define a function to print the parity of a graph in a specific order
func (g *Graph) PrintParityOrderedParityParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print parity of vertex
		fmt.Println(u.id+1, u.deg)
	}
}

// Define a function to print the vertices of a graph in a specific order
func (g *Graph) PrintVerticesOrderedParityParity() {
	// Initialize empty list Q to store vertices based on their degrees
	Q := make([]Vertex, 0)
	// Iterate through all vertices and add them to Q based on their degrees
	for _, v := range g.vertices {
		Q = append(Q, v)
	}
	// Heapify Q to get vertices with minimum degrees first
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})
	// Iterate through Q until it is empty
	for len(Q) > 0 {
		// Get vertex with minimum degree from Q
		u := Q[0]
		Q = Q[1:]
		// Print vertex
		fmt.Println(u.id+1)
	}
}

// Define a function to print the edges of a graph in a specif