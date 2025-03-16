package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node represents a node in the graph
type Node struct {
	val   int
	color bool
	a     [][2]int
}

// Read the number of nodes from input
func readNodes() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Read edges and construct the graph
func readEdges(nodes []Node) {
	for i := 0; i < len(nodes)-1; i++ {
		var u, v, w int
		fmt.Scanf("%d %d %d", &u, &v, &w)
		node1 := nodes[u-1]
		node2 := nodes[v-1]
		node1.val = u
		node2.val = v
		node1.a = append(node1.a, [2]int{node2, w})
		node2.a = append(node2.a, [2]int{node1, w})
	}
}

// Set the root node and initialize its color
func setRoot(nodes []Node) Node {
	root := nodes[0]
	root.color = true
	return root
}

// Define a recursive function to traverse the graph
func traverse(node Node, distance int) {
	nodeSet := make(map[int]bool)
	nodeSet[node.val] = true
	for _, pair := range node.a {
		adjNode := pair[0]
		dis := pair[1]
		if _, ok := nodeSet[adjNode.val]; ok {
			continue
		}
		if (distance + dis) % 2 == 0 {
			adjNode.color = node.color
		} else {
			adjNode.color =!node.color
		}
		traverse(adjNode, distance+dis)
}

// Start the traversal from the root node with an initial distance of 0
func main() {
	n := readNodes()
	nodes := make([]Node, n)
	readEdges(nodes)
	root := setRoot(nodes)
	traverse(root, 0)
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

