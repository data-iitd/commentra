
package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	pattern  int64
	index    int
	children []int
	parent   int
}

func (n *Node) setParent(k, parent, use int, nodes []*Node) {
	n.pattern = int64(k - use)
	n.parent = parent
	count := 1
	if parent!= -1 {
		count++
	}
	for _, child := range n.children {
		if child == n.parent {
			continue
		}
		nodes[child].setParent(k, n.index, count, nodes)
		count++
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 1_000_000_007
	var n, k int
	fmt.Fscan(scanner, &n, &k)
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{index: i}
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscan(scanner, &a, &b)
		a--
		b--
		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}
	nodes[0].setParent(k, -1, 0, nodes)
	patterns := int64(1)
	for i := 0; i < n; i++ {
		patterns = (patterns * nodes[i].pattern) % MOD
	}
	fmt.Println(patterns)
}

