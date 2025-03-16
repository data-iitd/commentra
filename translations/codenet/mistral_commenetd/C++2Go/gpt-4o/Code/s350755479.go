package main

import (
	"fmt"
	"sort"
)

const maxn = 1e5 + 5 // maximum number of nodes in the graph

type Node struct {
	x, y, id int // x and y coordinates, id of each node
}

type Edge struct {
	u, v, val int // u and v are the ids of the nodes connected by the edge, the value of the edge
}

var par [maxn]int // parent array to keep track of the parent of each node in the disjoint set data structure
var n int         // number of nodes in the graph

// Initialization function for the disjoint set data structure
func initDSU() {
	for i := 0; i <= n; i++ {
		par[i] = i // each node initially belongs to its own set
	}
}

// Function to find the representative of a set
func findpar(x int) int {
	if par[x] != x {
		par[x] = findpar(par[x]) // path compression is used to reduce the height of the tree
	}
	return par[x]
}

// Function to merge two sets
func unite(x, y int) {
	x = findpar(x)
	y = findpar(y)
	if x != y {
		par[x] = y // merge by making the root of set y as the parent of the root of set x
	}
}

func main() {
	fmt.Scan(&n) // read the number of nodes in the graph

	initDSU() // initialize the disjoint set data structure

	node := make([]Node, n+1)
	e := make([]Edge, 0)

	// Read the coordinates of each node and assign an id to it
	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y)
		node[i].id = i // id is just the index of the node in the node array
	}

	// Sort the nodes based on their x-coordinates
	sort.Slice(node[1:], func(i, j int) bool {
		return node[i+1].x < node[j+1].x
	})

	// Create edges between adjacent nodes based on their x-coordinates
	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x})
	}

	// Sort the nodes based on their y-coordinates
	sort.Slice(node[1:], func(i, j int) bool {
		return node[i+1].y < node[j+1].y
	})

	// Create edges between adjacent nodes based on their y-coordinates
	for i := 2; i <= n; i++ {
		e = append(e, Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y})
	}

	// Sort the edges based on their values
	sort.Slice(e, func(i, j int) bool {
		return e[i].val < e[j].val
	})

	ans := int64(0) // initialize the answer to 0
	// Process each edge in the sorted order
	for _, edge := range e {
		u, v, val := edge.u, edge.v, edge.val
		// Skip if the nodes are already in the same set
		if findpar(u) == findpar(v) {
			continue
		}
		// Merge the sets of the nodes and add the value of the edge to the answer
		unite(u, v)
		ans += int64(val)
	}

	fmt.Println(ans) // print the final answer
}

// <END-OF-CODE>
