

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	pattern int64
	index   int
	children []int
	parent   int
}

func (n *Node) setParent(K, parent, use int, nodes []*Node) {
	n.pattern = int64(K - use)
	n.parent = parent
	count := 1
	if parent!= -1 {
		count++
	}
	for _, child := range n.children {
		if child == n.parent {
			continue
		}
		nodes[child].setParent(K, n.index, count, nodes)
		count++
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 1_000_000_007
	var N, K int
	fmt.Fscan(scanner, &N, &K)
	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i}
	}
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(scanner, &a, &b)
		a--
		b--
		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}
	nodes[0].setParent(K, -1, 0, nodes)
	patterns := int64(1)
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % MOD
	}
	fmt.Println(patterns)
}

