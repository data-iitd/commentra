
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node struct to store the node information
type Node struct {
	pattern  int64
	index    int
	children []int
	parent   int
}

// NewNode creates a new node
func NewNode(i int) *Node {
	return &Node{
		pattern:  0,
		index:    i,
		children: make([]int, 0),
		parent:   -1,
	}
}

// SetParent sets the parent of the node recursively
func (n *Node) SetParent(K int, parent int, use int, nodes []*Node) {
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
		nodes[child].SetParent(K, n.index, count, nodes)
		count++
	}
}

// Solve the problem
func solve() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	N, _ := strconv.Atoi(in.Text())
	in.Scan()
	K, _ := strconv.Atoi(in.Text())
	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = NewNode(i)
	}
	for i := 0; i < N-1; i++ {
		in.Scan()
		a, _ := strconv.Atoi(in.Text())
		in.Scan()
		b, _ := strconv.Atoi(in.Text())
		nodes[a-1].children = append(nodes[a-1].children, b-1)
		nodes[b-1].children = append(nodes[b-1].children, a-1)
	}
	in.Split(bufio.ScanWords)
	nodes[0].SetParent(K, -1, 0, nodes)
	patterns := int64(1)
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1_000_000_007
	}
	fmt.Println(patterns)
}

func main() {
	solve()
}

