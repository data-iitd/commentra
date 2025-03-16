
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

type directedEdge struct {
	vertex int32
	next   int32
}

type directedGraph struct {
	edge         []*directedEdge
	start        []int32
	pointer      int32
	vertex_num  int32
	edge_max_size int32
}

func newGraph(vertex_num int32) *directedGraph {
	g := &directedGraph{}
	g.edge = make([]*directedEdge, 1)
	g.start = make([]int32, vertex_num)
	g.pointer = 0
	g.vertex_num = vertex_num
	g.edge_max_size = 1
	for i := int32(0); i < vertex_num; i++ {
		g.start[i] = -1
	}
	return g
}

func addEdge(g *directedGraph, from int32, to int32) {
	if g.pointer == g.edge_max_size {
		g.edge_max_size *= 2
		g.edge = append(g.edge, make([]*directedEdge, g.edge_max_size-g.pointer)...)
	}
	g.edge[g.pointer] = &directedEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

func modPow(r int32, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 == 1 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return t
}

type node struct {
	one  int32
	zero int32
}

type deque struct {
	array  []*node
	front  int
	last   int
	mask   int
}

func newDeque() *deque {
	const len = 2
	d := &deque{}
	d.array = make([]*node, len)
	d.front = 0
	d.last = 0
	d.mask = len - 1
	return d
}

func (d *deque) getSize() int {
	return (d.last + d.mask - d.front + 1) & d.mask
}

func (d *deque) getAt(x int) *node {
	return d.array[(d.front+x)&d.mask]
}

func (d *deque) assignAt(x int, v *node) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *deque) pushFront(v *node) {
	if (d.last+1)&d.mask == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func (d *deque) realloc() {
	array := make([]*node, 2*d.mask+1)
	k := 0
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = array
	d.front = 0
	d.last = k
	d.mask = 2 * d.mask + 1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int32
	fmt.Fscanf(reader, "%d\n", &n)
	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)
	for i := int32(1); i <= n; i++ {
		fmt.Fscanf(reader, "%d\n", &p[i])
		addEdge(g, p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]*node, n+1)
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(&node{one: 1, zero: 1})
			continue
		}
		len := 0
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			for i := 0; i < len; i++ {
				child[i].pushFront(&node{one: 1, zero: 1})
			}
			for i := 0; i < len; i++ {
				for j := 0; j < child[i].getSize(); j++ {
					lst[j] = child[i].getAt(j)
				}
				child[0].assignAt(i, merge(lst, len))
			}
			for j := 1; j < len; j++ {
				child[j].clear()
			}
		}
		dp[v] = child[0]
		dp[v].pushFront(&node{one: 1, zero: 1})
	}
	ans := int64(0)
	for i := 0; i < dp[0].getSize(); i++ {
		ans += int64(modPow(2, n+1-cnt[i])) * int64(dp[0].getAt(i).one)
		ans %= mod
	}
	fmt.Println(ans)
}

func merge(lst []*node, len int) *node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := 0; i < len; i++ {
		one = (one * lst[i].zero + zero * lst[i].one) % mod
		zero = (zero * lst[i].zero) % mod
		total = (total * (lst[i].zero + lst[i].one)) % mod
	}
	return &node{one: int32(one), zero: int32((total + mod - one) % mod)}
}
