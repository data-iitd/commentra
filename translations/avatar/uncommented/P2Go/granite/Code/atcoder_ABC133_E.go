
package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

var (
	MOD = 100000007
)

type Edge struct {
	To   int
	Next *Edge
}

type Node struct {
	Edges *list.List
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{Edges: list.New()}
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		a--
		b--
		nodes[a].Edges.PushBack(&Edge{To: b})
		nodes[b].Edges.PushBack(&Edge{To: a})
	}
	fmt.Println(solve(nodes, k))
}

func solve(nodes []*Node, k int) int {
	var dfs func(node *Node, parent *Node, color int) int
	dfs = func(node *Node, parent *Node, color int) int {
		if color == k {
			color--
		}
		ways := 1
		for e := node.Edges.Front(); e!= nil; e = e.Next() {
			next := e.Value.(*Edge).To
			if next == parent {
				continue
			}
			ways = ways * dfs(nodes[next], node, color-1) % MOD
		}
		return ways
	}
	return dfs(nodes[0], nil, k)
}

