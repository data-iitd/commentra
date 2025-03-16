
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Define a constant for the maximum number of nodes
const maxn = 1e5 + 5

// Structure to represent a node with coordinates and an ID
type Node struct {
	x, y, id int
}

// Structure to represent an edge with two nodes and a weight
type Edge struct {
	u, v, val int
}

// Array to store the parent of each node for union-find
var par [maxn]int
var n int // Number of nodes

// Comparison function to sort nodes based on their x-coordinate
func cmp1(a, b Node) bool {
	return a.x < b.x
}

// Comparison function to sort nodes based on their y-coordinate
func cmp2(a, b Node) bool {
	return a.y < b.y
}

// Function to initialize the union-find structure
func init() {
	for i := 0; i <= n; i++ {
		par[i] = i // Each node is its own parent initially
	}
}

// Function to find the representative parent of a node
func findpar(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = findpar(par[x]) // Path compression
	return par[x]
}

// Function to unite two nodes in the union-find structure
func unite(x, y int) {
	x = findpar(x)
	y = findpar(y)
	if x == y {
		return
	}
	par[x] = y // Union the sets by making one parent of the other
}

func main() {
	// Read the number of nodes
	fmt.Scan(&n)

	// Initialize the union-find structure
	init()

	// Read the coordinates of each node and assign an ID
	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y)
		node[i].id = i // Assign ID to the node
	}

	// Sort nodes based on their x-coordinate
	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp1(node[i], node[j])
	})

	cnt := 0 // Counter for edges
	// Create edges based on x-coordinates
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
		cnt++
	}

	// Sort nodes based on their y-coordinate
	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp2(node[i], node[j])
	})
	// Create edges based on y-coordinates
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
		cnt++
	}

	// Sort edges based on their weight
	sort.Slice(e, func(i, j int) bool {
		return e[i].val < e[j].val
	})

	ans := int64(0) // Variable to store the total weight of the minimum spanning tree
	// Process each edge in sorted order
	for i := 0; i < cnt; i++ {
		u, v, val := e[i].u, e[i].v, e[i].val
		// If u and v are already connected, skip this edge
		if findpar(u) == findpar(v) {
			continue
		}
		unite(u, v) // Union the two nodes
		ans += int64(val) // Add the weight of this edge to the total
	}

	// Output the total weight of the minimum spanning tree
	fmt.Println(ans)
}

