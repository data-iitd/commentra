package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	pattern  int
	index    int
	children []int
	parent   int
}

func (n *Node) setParent(K int, parent int, use int, nodes []*Node) {
	n.pattern = K - use
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
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	N, _ := strconv.Atoi(in.Text())
	in.Scan()
	K, _ := strconv.Atoi(in.Text())
	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = &Node{index: i}
	}
	for i := 0; i < N-1; i++ {
		in.Scan()
		a, _ := strconv.Atoi(in.Text())
		in.Scan()
		b, _ := strconv.Atoi(in.Text())
		nodes[a-1].children = append(nodes[a-1].children, b-1)
		nodes[b-1].children = append(nodes[b-1].children, a-1)
	}
	nodes[0].setParent(K, -1, 0, nodes)
	patterns := 1
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1_000_000_007
	}
	fmt.Println(patterns)
}

