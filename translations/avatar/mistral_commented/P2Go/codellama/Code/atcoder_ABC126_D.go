
package main

import (
	"fmt"
	"math"
)

// Define a Node struct
type Node struct {
	val         int
	color       bool
	adjacencies [][]int
}

// Initialize the root node
func (n *Node) init() {
	n.val = 0
	n.color = true
}

// Read input and initialize nodes
func main() {
	var n int
	fmt.Scan(&n)
	nodes := make([]Node, n)
	for i := range nodes {
		nodes[i].init()
	}

	// Read edges and add adjacencies to nodes
	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		node_u := &nodes[u-1]
		node_v := &nodes[v-1]
		node_u.val = u
		node_v.val = v
		node_u.adjacencies = append(node_u.adjacencies, []int{node_v, w})
		node_v.adjacencies = append(node_v.adjacencies, []int{node_u, w})
	}

	// Set the root node and color it
	root := &nodes[0]
	root.color = true

	// Traverse the graph and color nodes based on their distance from the root
	visited := make(map[*Node]bool)
	var traverse func(node *Node, distance int)
	traverse = func(node *Node, distance int) {
		// Check if node has already been visited
		if visited[node] {
			return
		}
		// Mark node as visited
		visited[node] = true
		// Color node based on its distance from the root
		for _, adj := range node.adjacencies {
			adj_node := adj[0]
			adj_distance := adj[1]
			if (distance+adj_distance)%2 == 0 {
				adj_node.color = root.color
			} else {
				adj_node.color = !root.color
			}
			traverse(adj_node, distance+adj_distance)
		}
	}

	// Traverse the graph starting from the root
	traverse(root, 0)

	// Print the color of each node
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

