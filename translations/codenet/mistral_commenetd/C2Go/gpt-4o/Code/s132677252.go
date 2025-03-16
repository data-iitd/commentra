package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1000000007

type node struct {
	one  int32
	zero int32
}

type deque struct {
	array []node
	front int
	last  int
	mask  int
}

func newDeque() *deque {
	len := 2
	d := &deque{
		array: make([]node, len),
		front: 0,
		last:  0,
		mask:  len - 1,
	}
	return d
}

func (d *deque) getSize() int {
	return (d.last + (d.mask + 1 - d.front)) & d.mask
}

func (d *deque) realloc() {
	newArray := make([]node, 2*(d.mask+1))
	k := 0
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

func (d *deque) pushFront(v node) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func (d *deque) getAt(x int) node {
	return d.array[(d.front+x)&d.mask]
}

func merge(lst []node, j int) node {
	// Implement the merge logic based on your requirements
	// This is a placeholder implementation
	return node{one: 0, zero: 0}
}

func modPow(r int32, n int32) int32 {
	t := int64(1)
	s := int64(r)
	for n > 0 {
		if n&1 != 0 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return int32(t)
}

type graphEdge struct {
	vertex int32
	next   int32
}

type directedGraph struct {
	edge         []graphEdge
	start        []int32
	pointer      int32
	vertexNum    int32
	edgeMaxSize  int32
}

func newGraph(vertexNum int32) *directedGraph {
	g := &directedGraph{
		edge:        make([]graphEdge, 1),
		start:       make([]int32, vertexNum),
		pointer:     0,
		vertexNum:   vertexNum,
		edgeMaxSize: 1,
	}
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

func (g *directedGraph) addEdge(from int32, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	g.edge[g.pointer] = graphEdge{vertex: to, next: g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

func run() {
	var n int32
	fmt.Scan(&n)

	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1

	g := newGraph(n + 1)

	for i := int32(1); i <= n; i++ {
		fmt.Scan(&p[i])
		g.addEdge(p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}

	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)

	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(node{one: 1, zero: 1})
			continue
		}

		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}

		if len > 1 {
			sort.Slice(child[:len], func(i, j int) bool {
				return child[i].getSize() > child[j].getSize()
			})

			for d := 0; d < int(child[1].getSize()); d++ {
				j := 0
				for j < len && d < int(child[j].getSize()) {
					lst[j] = child[j].getAt(d)
					j++
				}
				dp[0].pushFront(merge(lst[:j], j))
			}
			for j := 1; j < len; j++ {
				// Free memory for child[j] if needed
			}
		}
		dp[v] = child[0]
		dp[v].pushFront(node{one: 1, zero: 1})
	}

	ans := int64(0)
	for i := 0; i < int(dp[0].getSize()); i++ {
		ans += (int64(modPow(2, n+1-cnt[int32(i)])) * int64(dp[0].getAt(i).one)) % mod
	}
	fmt.Println(ans % mod)
}

func main() {
	run()
}

// <END-OF-CODE>
