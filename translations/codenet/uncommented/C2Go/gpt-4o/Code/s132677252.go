package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1000000007

type Node struct {
	one  int32
	zero int32
}

type GraphEdge struct {
	vertex int32
	next   int32
}

type DirectedGraph struct {
	edge          []GraphEdge
	start         []int32
	pointer       int32
	vertexNum     int32
	edgeMaxSize   int32
}

func newGraph(vertexNum int32) *DirectedGraph {
	g := &DirectedGraph{
		edge:        make([]GraphEdge, 1),
		start:      make([]int32, vertexNum),
		pointer:     0,
		vertexNum:   vertexNum,
		edgeMaxSize: 1,
	}
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

func (g *DirectedGraph) addEdge(from, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]GraphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	g.edge[g.pointer] = GraphEdge{vertex: to, next: g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

func modPow(r, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = (int64(t) * int64(s)) % mod
		}
		s = (int64(s) * int64(s)) % mod
		n >>= 1
	}
	return t
}

func merge(a []Node, n int32) Node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := int32(0); i < n; i++ {
		one = (one*a[i].zero + zero*a[i].one) % mod
		zero = (zero * a[i].zero) % mod
		total = (total * (int64(a[i].zero) + int64(a[i].one))) % mod
	}
	return Node{one: int32(one), zero: int32((total + mod - one) % mod)}
}

type Deque struct {
	array []Node
	front int
	last  int
	mask  int
}

func newDeque() *Deque {
	len := 2
	return &Deque{
		array: make([]Node, len),
		front: 0,
		last:  0,
		mask:  len - 1,
	}
}

func (d *Deque) getSize() int {
	return (d.last + (^d.front + 1)) & d.mask
}

func (d *Deque) realloc() {
	newArray := make([]Node, 2*(d.mask+1))
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

func (d *Deque) pushFront(v Node) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b *Deque) int {
	d := a.getSize() - b.getSize()
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	}
	return 1
}

func run() {
	var n int32
	fmt.Scanf("%d", &n)
	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)

	for i := int32(1); i <= n; i++ {
		fmt.Scanf("%d", &p[i])
		g.addEdge(p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}

	dp := make([]*Deque, n+1)
	child := make([]*Deque, n+1)
	lst := make([]Node, n+1)

	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(Node{one: 1, zero: 1})
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
				return cmpDequeSize(child[i], child[j]) < 0
			})
			for d := int32(0); d < int32(child[1].getSize()); d++ {
				j := int32(0)
				for ; j < len && d < int32(child[j].getSize()); j++ {
					lst[j] = child[j].array[(child[j].front+d)&child[j].mask]
				}
				child[0].array[(child[0].front+d)&child[0].mask] = merge(lst[:j], j)
			}
			for j := int32(1); j < len; j++ {
				child[j] = nil // Freeing the deque
			}
		}
		dp[v] = child[0]
		dp[v].pushFront(Node{one: 1, zero: 1})
	}

	var ans int64 = 0
	for i := int32(0); i < int32(dp[0].getSize()); i++ {
		ans += (int64(modPow(2, n+1-cnt[i])) * int64(dp[0].array[(dp[0].front+i)&dp[0].mask].one)) % mod)
	}
	fmt.Printf("%d\n", ans%mod)
}

func main() {
	run()
}

// <END-OF-CODE>
