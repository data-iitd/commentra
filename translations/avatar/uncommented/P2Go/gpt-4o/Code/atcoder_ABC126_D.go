package main

import (
	"fmt"
)

type Node struct {
	val   int
	color bool
	a     [][]int // adjacency list with [node index, weight]
}

var nodes []*Node
var nodeSet = make(map[*Node]struct{})

func traverse(node *Node, distance int) {
	if _, exists := nodeSet[node]; exists {
		return
	}
	nodeSet[node] = struct{}{}

	for _, pair := range node.a {
		adjNode := nodes[pair[0]]
		dis := pair[1]
		if (distance + dis) % 2 == 0 {
			adjNode.color = node.color
		} else {
			adjNode.color = !node.color
		}
		traverse(adjNode, distance + dis)
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	nodes = make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}

	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		node1 := nodes[u-1]
		node2 := nodes[v-1]
		node1.val = u
		node2.val = v
		node1.a = append(node1.a, []int{v - 1, w})
		node2.a = append(node2.a, []int{u - 1, w})
	}

	root := nodes[0]
	root.color = true
	traverse(root, 0)

	for i := 0; i < n; i++ {
		if nodes[i].color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

// <END-OF-CODE>
