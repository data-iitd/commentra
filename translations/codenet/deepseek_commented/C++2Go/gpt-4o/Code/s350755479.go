package main

import (
	"fmt"
	"sort"
)

const maxn = 1e5 + 5 // Define a constant for the maximum number of nodes

type Node struct {
	x, y, id int // Define a structure for nodes with x, y coordinates and an id
}

type Edge struct {
	u, v, val int // Define a structure for edges with u, v nodes and a value
}

// Implement sort.Interface for Edge slice to sort by val
type EdgeSlice []Edge

func (e EdgeSlice) Len() int {
	return len(e)
}

func (e EdgeSlice) Less(i, j int) bool {
	return e[i].val < e[j].val
}

func (e EdgeSlice) Swap(i, j int) {
	e[i], e[j] = e[j], e[i]
}

var par [maxn]int // Define an array for storing the parent of each node
var n int        // Define an integer for the number of nodes

func initUnionFind() {
	for i := 0; i <= n; i++ {
		par[i] = i
	}
}

func findpar(x int) int { // Define a function to find the root of a node using path compression
	if par[x] != x {
		par[x] = findpar(par[x])
	}
	return par[x]
}

func unite(x, y int) { // Define a function to merge two sets
	x = findpar(x)
	y = findpar(y)
	if x != y {
		par[x] = y
	}
}

func main() {
	fmt.Scan(&n) // Read the number of nodes

	initUnionFind() // Initialize the parent array

	node := make([]Node, n+1)
	e := make([]Edge, 0)

	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y) // Read the coordinates of each node
		node[i].id = i                   // Assign an id to each node
	}

	sort.Slice(node[1:], func(i, j int) bool { // Sort nodes by x coordinate
		return node[i+1].x < node[j+1].x
	})

	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}) // Create edges based on x differences
	}

	sort.Slice(node[1:], func(i, j int) bool { // Sort nodes by y coordinate
		return node[i+1].y < node[j+1].y
	})

	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}) // Create edges based on y differences
	}

	sort.Sort(EdgeSlice(e)) // Sort all edges by their values

	var ans int64 = 0 // Initialize a variable to store the total weight of the minimum spanning tree
	for _, edge := range e {
		u, v, val := edge.u, edge.v, edge.val
		if findpar(u) == findpar(v) {
			continue // Skip if u and v are already in the same set
		}
		unite(u, v) // Merge u and v
		ans += int64(val) // Add the edge value to the total weight
	}

	fmt.Println(ans) // Output the total weight of the minimum spanning tree
}

// <END-OF-CODE>
