package main

import (
	"fmt"
)

type Node struct {
	val         int
	color       bool
	adjacencies [][]*NodeWeight
}

type NodeWeight struct {
	node     *Node
	distance int
}

var visited = make(map[*Node]bool)

func main() {
	// Set the maximum recursion depth
	// Go does not have a direct equivalent to Python's recursion limit,
	// but we can manage stack depth through careful design.

	var n int
	fmt.Scan(&n)

	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{val: 0, color: true}
	}

	// Read edges and add adjacencies to nodes
	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		nodeU := nodes[u-1]
		nodeV := nodes[v-1]
		nodeU.val = u
		nodeV.val = v
		nodeU.adjacencies = append(nodeU.adjacencies, &NodeWeight{node: nodeV, distance: w})
		nodeV.adjacencies = append(nodeV.adjacencies, &NodeWeight{node: nodeU, distance: w})
	}

	// Set the root node and color it
	root := nodes[0]
	root.color = true

	// Traverse the graph and color nodes based on their distance from the root
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

func traverse(node *Node, distance int) {
	// Check if node has already been visited
	if visited[node] {
		return
	}
	// Mark node as visited
	visited[node] = true
	// Color node based on its distance from the root
	for _, adj := range node.adjacencies {
		adjNode := adj.node
		adjDistance := adj.distance
		if (distance + adjDistance) % 2 == 0 {
			adjNode.color = node.color
		} else {
			adjNode.color = !node.color
		}
		traverse(adjNode, distance + adjDistance)
	}
}

// <END-OF-CODE>
