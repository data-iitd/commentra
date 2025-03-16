
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

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
		g.edge = append(g.edge, &directedEdge{})
	}
	g.edge[g.pointer] = &directedEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

const mod = 1000000007

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

type dpNode struct {
	one  int32
	zero int32
}

func merge(a []*dpNode, n int32) dpNode {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := int32(0); i < n; i++ {
		one = (one * a[i].zero + zero * a[i].one) % mod
		zero = zero * a[i].zero % mod
		total = total * (a[i].zero + a[i].one) % mod
	}
	return dpNode{int32(one), int32((total + mod - one) % mod)}
}

type Deque struct {
	array  []*dpNode
	front  int32
	last   int32
	mask   int32
}

func newDeque() *Deque {
	const len = 2
	d := &Deque{}
	d.array = make([]*dpNode, len)
	d.front = 0
	d.last = 0
	d.mask = len - 1
	return d
}

func (d *Deque) getSize() int32 {
	return (d.last + (^d.front + 1)) & d.mask
}

func (d *Deque) realloc() {
	newArray := make([]*dpNode, 2*(d.mask+1))
	k := int32(0)
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2 * d.mask + 1
}

func (d *Deque) getAt(x int32) *dpNode {
	return d.array[(d.front+x)&d.mask]
}

func (d *Deque) assignAt(x int32, v *dpNode) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *Deque) pushFront(v *dpNode) {
	if (d.last+1)&d.mask == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b interface{}) int {
	pa := a.(*Deque)
	pb := b.(*Deque)
	d := pa.getSize() - pb.getSize()
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	} else {
		return 1
	}
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
		addEdge(g, p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*Deque, n+1)
	child := make([]*Deque, n+1)
	lst := make([]*dpNode, n+1)
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(&dpNode{1, 1})
			continue
		}
		len := int32(0)
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			sort.Slice(child[:len], cmpDequeSize)
			for d := int32(0); d < child[1].getSize(); d++ {
				j := int32(0)
				for ; j < len && d < child[j].getSize(); j++ {
					lst[j] = child[j].getAt(d)
				}
				dp[v].assignAt(d, merge(lst[:j], j))
			}
			for j := int32(1); j < len; j++ {
				dp[v].last = dp[v].front
			}
		}
		dp[v] = child[0]
		dp[v].pushFront(&dpNode{1, 1})
	}
	ans := int64(0)
	for i := int32(0); i < dp[0].getSize(); i++ {
		ans += int64(modPow(2, n+1-cnt[i])) * int64(dp[0].getAt(i).one) % mod
	}
	fmt.Println(ans % mod)
}

func main() {
	run()
}

