package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Read the number of nodes (N) and edges (M) from input
func readInput() (int, int) {
	var N, M int
	fmt.Fscan(os.Stdin, &N, &M)
	return N, M
}

// Initialize adjacency list for edges, degree count, parity, and visited flag
var (
	edges [100001][]int
	degs  [100001]int
	parity [100001]int
	flag  [100001]bool
)

// Read edges and populate the adjacency list and degree counts
func readEdges() {
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Fscan(os.Stdin, &a, &b)
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a]++
		degs[b]++
	}
}

// If the number of edges is odd, it's impossible to pair them
func checkParity() bool {
	return M%2 == 0
}

// Initialize a priority queue with degrees of nodes
type node struct {
	deg int
	idx int
}

func (n node) Less(o node) bool {
	return n.deg < o.deg
}

func (n node) Swap(o node) {
	n.deg, o.deg = o.deg, n.deg
	n.idx, o.idx = o.idx, n.idx
}

func (n *node) Push(x interface{}) {
	*n = x.(node)
}

func (n *node) Pop() interface{} {
	x := *n
	*n = node{}
	return x
}

func initQ() *node {
	q := make(nodeHeap, 0)
	for i, d := range degs {
		q = append(q, node{d, i})
	}
	heap.Init(&q)
	return &q[0]
}

type nodeHeap []node

func (h nodeHeap) Len() int {
	return len(h)
}

func (h nodeHeap) Less(i, j int) bool {
	return h[i].deg < h[j].deg
}

func (h nodeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *nodeHeap) Push(x interface{}) {
	*h = append(*h, x.(node))
}

func (h *nodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Process the nodes in the priority queue
func processQ(q *node) {
	u := q.idx
	flag[u] = true
	for i, v := range edges[u] {
		edges[v] = remove(edges[v], u)
		if parity[u]!= 0 && i == 0 {
			fmt.Printf("%d %d\n", u+1, v+1)
			parity[u] = 1 - parity[u]
		} else {
			fmt.Printf("%d %d\n", v+1, u+1)
			parity[v] = 1 - parity[v]
		}
		degs[v]--
		heap.Push(q, node{degs[v], v})
	}
}

func remove(s []int, e int) []int {
	for i, v := range s {
		if v == e {
			s = append(s[:i], s[i+1:]...)
			return s
		}
	}
	return s
}

func main() {
	N, M = readInput()
	readEdges()
	if!checkParity() {
		fmt.Println(-1)
		return
	}
	q := initQ()
	for q.deg > 0 {
		processQ(q)
	}
}

