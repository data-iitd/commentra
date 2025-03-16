
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	pattern int
	index   int
	children []int
	parent  int
}

func (n *Node) setParent(K int, parent int, use int, nodes []Node) {
	n.pattern = K - use
	n.parent = parent
	count := 1
	if parent != -1 {
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

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	var K int
	scanner.Scan()
	K, _ = strconv.Atoi(scanner.Text())
	nodes := make([]Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = Node{index: i}
	}
	for i := 0; i < N-1; i++ {
		var a, b int
		scanner.Scan()
		a, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ = strconv.Atoi(scanner.Text())
		nodes[a-1].children = append(nodes[a-1].children, b-1)
		nodes[b-1].children = append(nodes[b-1].children, a-1)
	}
	scanner.Scan()
	nodes[0].setParent(K, -1, 0, nodes)
	patterns := 1
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1000000007
	}
	fmt.Println(patterns)
}

func main() {
	solve()
}

