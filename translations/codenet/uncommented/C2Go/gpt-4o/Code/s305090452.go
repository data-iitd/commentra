package main

import (
	"fmt"
	"math"
	"sort"
)

type Heap struct {
	array     []edge
	heapSize  int
	maxSize   int
	cmp       func(a, b edge) int
}

type edge struct {
	a, b int32
	c    int64
}

func newHeap(cmp func(a, b edge) int) *Heap {
	return &Heap{
		array:    make([]edge, 0),
		heapSize: 0,
		maxSize:  1,
		cmp:      cmp,
	}
}

func (h *Heap) push(val edge) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = append(h.array, make([]edge, h.maxSize-len(h.array))...)
	}
	h.heapSize++
	h.array[h.heapSize-1] = val
	h.bubbleUp(h.heapSize - 1)
}

func (h *Heap) pop() edge {
	if h.heapSize == 0 {
		return edge{}
	}
	res := h.array[0]
	h.heapSize--
	h.array[0] = h.array[h.heapSize]
	h.bubbleDown(0)
	return res
}

func (h *Heap) bubbleUp(index int) {
	for index > 0 {
		parent := (index - 1) / 2
		if h.cmp(h.array[parent], h.array[index]) <= 0 {
			return
		}
		h.array[parent], h.array[index] = h.array[index], h.array[parent]
		index = parent
	}
}

func (h *Heap) bubbleDown(index int) {
	for {
		left := 2*index + 1
		right := 2*index + 2
		smallest := index

		if left < h.heapSize && h.cmp(h.array[left], h.array[smallest]) < 0 {
			smallest = left
		}
		if right < h.heapSize && h.cmp(h.array[right], h.array[smallest]) < 0 {
			smallest = right
		}
		if smallest == index {
			break
		}
		h.array[index], h.array[smallest] = h.array[smallest], h.array[index]
		index = smallest
	}
}

type UnionFind struct {
	parent []int32
	size   int32
}

func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size:   size,
	}
	for i := int32(0); i < size; i++ {
		u.parent[i] = -1
	}
	return u
}

func (u *UnionFind) root(x int32) int32 {
	if u.parent[x] < 0 {
		return x
	}
	u.parent[x] = u.root(u.parent[x])
	return u.parent[x]
}

func (u *UnionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y)
}

func (u *UnionFind) unite(x, y int32) {
	xRoot := u.root(x)
	yRoot := u.root(y)
	if xRoot == yRoot {
		return
	}
	if u.parent[xRoot] > u.parent[yRoot] {
		xRoot, yRoot = yRoot, xRoot
	}
	u.parent[xRoot] += u.parent[yRoot]
	u.parent[yRoot] = xRoot
}

type SegmentNode struct {
	index int32
	val   int64
}

type SegmentTree struct {
	array   []SegmentNode
	size    int32
	valSize int32
	funcOp  func(c, a, b *SegmentNode)
}

func newSegmentTree(ini *SegmentNode, n int32, funcOp func(c, a, b *SegmentNode) ) *SegmentTree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &SegmentTree{
		array:   make([]SegmentNode, 2*k),
		size:    k,
		valSize: 1,
		funcOp:  funcOp,
	}
	for i := k; i < 2*k; i++ {
		s.array[i] = *ini
	}
	for i := k - 1; i > 0; i-- {
		s.funcOp(&s.array[i], &s.array[2*i], &s.array[2*i+1])
	}
	return s
}

func (s *SegmentTree) update(k int32, val *SegmentNode) {
	k += s.size
	s.array[k] = *val
	for k >>= 1; k > 0; k >>= 1 {
		s.funcOp(&s.array[k], &s.array[2*k], &s.array[2*k+1])
	}
}

func (s *SegmentTree) find(l, r int32) SegmentNode {
	l += s.size
	r += s.size
	res := s.array[l]
	for l < r {
		if l&1 == 1 {
			s.funcOp(&res, &res, &s.array[l])
			l++
		}
		if r&1 == 1 {
			r--
			s.funcOp(&res, &res, &s.array[r])
		}
		l >>= 1
		r >>= 1
	}
	return res
}

type IndexVal struct {
	index int32
	val   int32
}

func cmpIndexVal(a, b edge) int {
	if a.c == b.c {
		return 0
	}
	if a.c < b.c {
		return -1
	}
	return 1
}

func cmpEdge(a, b edge) int {
	if a.c == b.c {
		return 0
	}
	if a.c < b.c {
		return -1
	}
	return 1
}

func funcSegmentNode(c, a, b *SegmentNode) {
	if a.val < b.val {
		*c = *a
	} else {
		*c = *b
	}
}

func run() {
	var n, d int32
	fmt.Scanf("%d %d", &n, &d)
	a := make([]int32, n)
	p := make([]IndexVal, n)
	for i := int32(0); i < n; i++ {
		fmt.Scanf("%d", &a[i])
		p[i] = IndexVal{i, a[i]}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].val > p[j].val
	})
	ini := SegmentNode{index: n, val: int64(n+2)*1000000000 + 1}
	l := newSegmentTree(&ini, n, funcSegmentNode)
	r := newSegmentTree(&ini, n, funcSegmentNode)
	for i := int32(0); i < n; i++ {
		l.update(i, &SegmentNode{index: i, val: int64(a[i]) + int64(n-1-i)*d})
		r.update(i, &SegmentNode{index: i, val: int64(a[i]) + int64(i)*d})
	}
	heap := newHeap(cmpEdge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			t := l.find(0, v)
			heap.push(edge{v, t.index, p[i].val + t.val - int64(n-1-v)*d})
		}
		if v+1 < n {
			t := r.find(v+1, n)
			heap.push(edge{v, t.index, p[i].val + t.val - int64(v)*d})
		}
		l.update(v, &ini)
		r.update(v, &ini)
	}
	sum := int64(0)
	u := newUnionFind(n)
	for {
		if u.parent[0] == -1 {
			break
		}
		e := heap.pop()
		if u.same(e.a, e.b) {
			continue
		}
		u.unite(e.a, e.b)
		sum += e.c
	}
	fmt.Printf("%d\n", sum)
}

func main() {
	run()
}

// <END-OF-CODE>
