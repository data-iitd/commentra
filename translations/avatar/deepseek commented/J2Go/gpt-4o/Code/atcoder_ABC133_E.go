package main

import (
	"fmt"
	"os"
)

type Node struct {
	pattern  int64
	index    int
	children []int
	parent   int
}

func (n *Node) setParent(K int, parent int, use int, nodes []*Node) {
	n.pattern = int64(K - use)
	n.parent = parent
	count := 1
	if parent != -1 {
		count++
	}
	for _, childIndex := range n.children {
		if childIndex == n.parent {
			continue
		}
		nodes[childIndex].setParent(K, n.index, count, nodes)
		count++
	}
}

func solve() {
	var N, K int
	fmt.Scan(&N, &K)

	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i, parent: -1}
	}

	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to zero-based index
		b-- // Convert to zero-based index
		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}

	nodes[0].setParent(K, -1, 0, nodes)

	patterns := int64(1)
	const MOD = 1_000_000_007
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % MOD
	}
	fmt.Println(patterns)
}

func main() {
	solve()
}

// <END-OF-CODE>
