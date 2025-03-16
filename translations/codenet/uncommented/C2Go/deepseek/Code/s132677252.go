package main

import (
	"fmt"
	"math/big"
)

type i32 int32
type i64 int64

type graphEdge struct {
	vertex int32
	next   int32
}

type graph struct {
	edge        []graphEdge
	start       []int32
	pointer     int32
	vertexNum   int32
	edgeMaxSize int32
}

func newGraph(vertexNum int32) *graph {
	g := &graph{
		edge:        []graphEdge{graphEdge{}},
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

func (g *graph) addEdge(from, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

const mod = 1000000007

func modPow(r, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = t * s % mod
		}
		s = s * s % mod
		n >>= 1
	}
	return t
}

type node struct {
	one  int32
	zero int32
}

func merge(a []node, n int32) node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := int32(0); i < n; i++ {
		one = (one*int64(a[i].zero) + int64(a[i].one)*zero) % mod
		zero = zero * int64(a[i].zero) % mod
		total = total * int64(a[i].zero + a[i].one) % mod
	}
	return node{int32(one), (int32(total + mod - one) % mod)}
}

type dequeVal node

type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

func newDeque() *deque {
	d := &deque{
		array: []dequeVal{{}, {}},
		front: 0,
		last:  0,
		mask:  1,
	}
	return d
}

func (d *deque) free() {
	d.array = nil
	d.front = 0
	d.last = 0
	d.mask = 0
}

func (d *deque) size() int {
	return (d.last + (^d.front + 1)) & d.mask
}

func (d *deque) realloc() {
	newArray := make([]dequeVal, 2*(d.mask+1))
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

func (d *deque) getAt(x int) dequeVal {
	return d.array[(d.front+x)&d.mask]
}

func (d *deque) assignAt(x int, v dequeVal) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *deque) pushFront(v dequeVal) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b interface{}) int {
	p := a.(*deque)
	q := b.(*deque)
	d := p.size() - q.size()
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

func run() {
	var n int32
	fmt.Scanf("%"