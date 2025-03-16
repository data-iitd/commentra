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
	parent  int
}

func (n *Node) setParent(K, parent, use int, nodes []*Node) {
	n.pattern = int64(K - use)
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

func (m *Main) solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	N := m.nextInt(scanner)
	K := m.nextInt(scanner)
	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i}
	}
	for i := 0; i < N-1; i++ {
		a := m.nextInt(scanner) - 1
		b := m.nextInt(scanner) - 1
		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}
	nodes[0].setParent(K, -1, 0, nodes)
	patterns := int64(1)
	for _, node := range nodes {
		patterns = (patterns * node.pattern) % 1_000_000_007
	}
	fmt.Println(patterns)
}

func (m *Main) nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

type Main struct{}

func main() {
	main := &Main{}
	main.solve()
}

