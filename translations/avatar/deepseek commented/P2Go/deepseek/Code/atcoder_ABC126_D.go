package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define the Node struct to represent each node in the graph
type Node struct {
	val   int
	color bool
	edges []*Edge
}

// Define the Edge struct to represent the edge between two nodes
type Edge struct {
	node   *Node
	weight int
}

// Read the number of nodes in the graph
var n int
fmt.Scan(&n)

// Create a slice to store all nodes
nodes := make([]*Node, n)
for i := 0; i < n; i++ {
	nodes[i] = &Node{}
}

// Read each edge in the graph and establish connections between nodes
for i := 0; i < n-1; i++ {
	var u, v, w int
	fmt.Scan(&u, &v, &w)
	node1 := nodes[u-1]
	node2 := nodes[v-1]
	node1.edges = append(node1.edges, &Edge{node2, w})
	node2.edges = append(node2.edges, &Edge{node1, w})
}

// Set the root node to the first node in the slice
root := nodes[0]

// Set the color of the root node to true
root.color = true

// Initialize a map to keep track of visited nodes
visited := make(map[*Node]bool)

// Define the traverse function to recursively traverse the graph
var traverse func(*Node, int)
traverse = func(node *Node, distance int) {
	if visited[node] {
		return
	}
	visited[node] = true
	for _, edge := range node.edges {
		adjNode := edge.node
		dis := edge.weight
		if (distance+dis)%2 == 0 {
			adjNode.color = root.color
		} else {
			adjNode.color = !root.color
		}
		traverse(adjNode, distance+dis)
	}
}

// Call the traverse function starting from the root node with a distance of 0
traverse(root, 0)

// Print the color of each node
for _, node := range nodes {
	if node.color {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

