package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	pattern  int64
	index    int
	children []int
	parent   int
}

func (n *Node) setParent(K, parent, use int, nodes []*Node) {
	n.pattern = int64(K - use)
	n.parent = parent
	count := 1
	if parent != -1 {
		count++
	}
	for _, n := range n.children {
		if n == n.parent {
			continue
		}
		nodes[n].setParent(K, n.index, count, nodes)
		count++
	}
}

func (main *Main) solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	K, _ := strconv.Atoi(scanner.Text())
	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i}
	}
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		a--
		b--
		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}
	nodes[0].setParent(K, -1, 0, nodes)
	var patterns int64 = 1
	for _, node := range nodes {
		patterns = (patterns * node.pattern) % 1_000_000_007
	}
	fmt.Println(patterns)
}

func main() {
	mainInstance := &Main{}
	mainInstance.solve()
}

