package main

import (
	"fmt"
	"container/list"
)

func main() {
	main := new(Main)
	main.solve()
}

type Node struct {
	pattern int
	index   int
	children *list.List
	parent   int
}

func (n *Node) setParent(K, parent, use int, nodes []*Node) {
	n.pattern = K - use
	n.parent = parent
	count := 1
	if parent != -1 {
		count++
	}
	for e := n.children.Front(); e != nil; e = e.Next() {
		childIndex := e.Value.(int)
		if childIndex == n.parent {
			continue
		}
		nodes[childIndex].setParent(K, n.index, count, nodes)
		count++
	}
}

func (n *Node) solve() {
	var N, K int
	fmt.Scan(&N, &K)

	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i, children: list.New()}
	}

	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		nodes[a].children.PushBack(b)
		nodes[b].children.PushBack(a)
	}

	nodes[0].setParent(K, -1, 0, nodes)
	patterns := 1
	const mod = 1_000_000_007

	for i := 0; i < N; i++ {
		patterns = (patterns * int(nodes[i].pattern)) % mod
	}

	fmt.Println(patterns)
}

