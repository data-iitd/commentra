package main

import (
	"fmt"
	"sort"
)

const maxn = 1e5 + 5

// Node structure to represent a node with coordinates and an ID
type Node struct {
	x, y, id int
}

// Edge structure to represent an edge with two nodes and a weight
type Edge struct {
	u, v, val int
}

// Union-Find structure
type UnionFind struct {
	par []int
}

// Initialize the union-find structure
func (uf *UnionFind) init(n int) {
	uf.par = make([]int, n+1)
	for i := 0; i <= n; i++ {
		uf.par[i] = i // Each node is its own parent initially
	}
}

// Find the representative parent of a node
func (uf *UnionFind) findpar(x int) int {
	if uf.par[x] != x {
		uf.par[x] = uf.findpar(uf.par[x]) // Path compression
	}
	return uf.par[x]
}

// Unite two nodes in the union-find structure
func (uf *UnionFind) unite(x, y int) {
	x = uf.findpar(x)
	y = uf.findpar(y)
	if x != y {
		uf.par[x] = y // Union the sets by making one parent of the other
	}
}

// Comparison function to sort nodes based on their x-coordinate
type ByX []Node

func (a ByX) Len() int           { return len(a) }
func (a ByX) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByX) Less(i, j int) bool { return a[i].x < a[j].x }

// Comparison function to sort nodes based on their y-coordinate
type ByY []Node

func (a ByY) Len() int           { return len(a) }
func (a ByY) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByY) Less(i, j int) bool { return a[i].y < a[j].y }

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize the union-find structure
	uf := UnionFind{}
	uf.init(n)

	node := make([]Node, n+1)
	e := make([]Edge, 0)

	// Read the coordinates of each node and assign an ID
	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y)
		node[i].id = i // Assign ID to the node
	}

	// Sort nodes based on their x-coordinate
	sort.Sort(ByX(node[1:]))

	// Create edges based on x-coordinates
	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x})
	}

	// Sort nodes based on their y-coordinate
	sort.Sort(ByY(node[1:]))

	// Create edges based on y-coordinates
	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y})
	}

	// Sort edges based on their weight
	sort.Slice(e, func(i, j int) bool {
		return e[i].val < e[j].val
	})

	var ans int64 = 0 // Variable to store the total weight of the minimum spanning tree
	// Process each edge in sorted order
	for _, edge := range e {
		u, v, val := edge.u, edge.v, edge.val
		// If u and v are already connected, skip this edge
		if uf.findpar(u) == uf.findpar(v) {
			continue
		}
		uf.unite(u, v) // Union the two nodes
		ans += int64(val) // Add the weight of this edge to the total
	}

	// Output the total weight of the minimum spanning tree
	fmt.Println(ans)
}

// <END-OF-CODE>
