package main

import (
	"fmt"
	"math/rand"
	"time"
)

type BinaryHeap struct {
	array    []byte
	heapSize int
	maxSize  int
	valSize  int
	cmp      func(a, b []byte) int
}

func NewBinaryHeap(valSize int, cmp func(a, b []byte) int) *BinaryHeap {
	h := &BinaryHeap{
		array:   make([]byte, valSize*(1+1)),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:      cmp,
	}
	return h
}

func (h *BinaryHeap) GetHeapSize() int {
	return h.heapSize
}

func (h *BinaryHeap) IsEmpty() bool {
	return h.heapSize == 0
}

func (h *BinaryHeap) FreeHeap() {
	free(h.array)
	free(h)
}

func (h *BinaryHeap) InitHeap() {
	h.heapSize = 0
}

func heapFuncSwap(a, b []byte, valSize int) {
	if valSize&7 == 0 {
		for i := 0; i < valSize/8; i++ {
			tmp := a[i]
			a[i] = b[i]
			b[i] = tmp
		}
	} else {
		for i := 0; i < valSize; i++ {
			tmp := a[i]
			a[i] = b[i]
			b[i] = tmp
		}
	}
}

func heapFuncCopy(dst, src []byte, valSize int) {
	if valSize&7 == 0 {
		for i := 0; i < valSize/8; i++ {
			dst[i] = src[i]
		}
	} else {
		for i := 0; i < valSize; i++ {
			dst[i] = src[i]
		}
	}
}

func (h *BinaryHeap) Push(val []byte) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = realloc(h.array, h.valSize*(h.maxSize+1))
	}
	h.heapSize++
	array := h.array
	k := h.heapSize
	valSize := h.valSize
	cmp := h.cmp
	heapFuncCopy(array[k*valSize:], val, valSize)
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*valSize:], array[k*valSize:]) <= 0 {
			return
		}
		heapFuncSwap(array[parent*valSize:], array[k*valSize:], valSize)
		k = parent
	}
}

func (h *BinaryHeap) Pop(res []byte) {
	array := h.array
	valSize := h.valSize
	if res != nil {
		heapFuncCopy(res, array[:valSize], valSize)
	}
	heapFuncCopy(array[:valSize], array[valSize:], valSize)
	h.heapSize--
	cmp := h.cmp
	n := h.heapSize
	k := 1
	for 2*k+1 <= n {
		c := cmp(array[2*k*valSize:], array[(2*k+1)*valSize:])
		next := 2*k + (c <= 0 ? 0 : 1)
		if cmp(array[k*valSize:], array[next*valSize:]) <= 0 {
			return
		}
		heapFuncSwap(array[k*valSize:], array[next*valSize:], valSize)
		k = next
	}
	if 2*k <= n && cmp(array[k*valSize:], array[2*k*valSize:]) > 0 {
		heapFuncSwap(array[k*valSize:], array[2*k*valSize:], valSize)
	}
}

func (h *BinaryHeap) Top(res []byte) {
	array := h.array
	valSize := h.valSize
	if res != nil {
		heapFuncCopy(res, array[:valSize], valSize)
	}
}

type UnionFind struct {
	parent []int
	size   int
}

func InitUnionFind(u *UnionFind) {
	for i := 0; i < u.size; i++ {
		u.parent[i] = -1
	}
}

func NewUnionFind(size int) *UnionFind {
	u := &UnionFind{
		parent: make([]int, size),
		size:   size,
	}
	InitUnionFind(u)
	return u
}

func (u *UnionFind) FreeUnionFind() {
	free(u.parent)
	free(u)
}

func (u *UnionFind) Root(x int) int {
	index := []int{}
	for u.parent[x] >= 0 {
		index = append(index, x)
		x = u.parent[x]
	}
	for i := 0; i < len(index); i++ {
		u.parent[index[i]] = x
	}
	return x
}

func (u *UnionFind) Same(x, y int) bool {
	return u.Root(x) == u.Root(y)
}

func (u *UnionFind) GetSize(x int) int {
	return -u.parent[u.Root(x)]
}

func (u *UnionFind) Unite(x, y int) {
	x = u.Root(x)
	y = u.Root(y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

type SegmentTree struct {
	array    []byte
	size     int
	valSize  int
	func_    func(a, b, c []byte)
}

func segmentTreeMemcpy(dst, src []byte) {
	copy(dst, src)
}

func NewSegmentTree(ini []byte, n, valSize int, f func(a, b, c []byte)) *SegmentTree {
	k := 1
	for k < n {
		k *= 2
	}
	s := &SegmentTree{
		array:   make([]byte, 2*k*valSize),
		size:    k,
		valSize: valSize,
		func_:   f,
	}
	copy(s.array[k*valSize:], ini)
	for i := k - 1; i > 0; i-- {
		f(s.array[i*valSize:], s.array[2*i*valSize:], s.array[(2*i+1)*valSize:])
	}
	return s
}

func (s *SegmentTree) Update(k int, val []byte) {
	k += s.size
	for i := k; i > 1; i >>= 1 {
		s.func_(s.array[i*s.valSize:], s.array[i^1*s.valSize:], val)
	}
	copy(s.array[k*s.valSize:], val)
}

func (s *SegmentTree) UpdateTmp(k int, val []byte) {
	k += s.size
	copy(s.array[k*s.valSize:], val)
}

func (s *SegmentTree) UpdateAll() {
	for i := s.size - 1; i > 0; i-- {
		s.func_(s.array[i*s.valSize:], s.array[2*i*s.valSize:], s.array[(2*i+1)*s.valSize:])
	}
}

func (s *SegmentTree) Find(l, r int, res []byte) {
	lindex := []int{}
	rindex := []int{}
	for l += s.size; l < r; l >>= 1 {
		if l&1 != 0 {
			lindex = append(lindex, l)
			l++
		}
		if r&1 != 0 {
			r--
			rindex = append(rindex, r)
		}
	}
	if len(lindex) == 0 {
		lindex = append(lindex, rindex[0])
	}
	segmentTreeMemcpy(res, s.array[lindex[0]*s.valSize:])
	for i := 1; i < len(lindex); i++ {
		s.func_(res, res, s.array[lindex[i]*s.valSize:])
	}
	for i := len(rindex) - 1; i >= 0; i-- {
		s.func_(res, res, s.array[rindex[i]*s.valSize:])
	}
}

type i32 int
type i64 int64

type IndexVal struct {
	index int
	val   int
}

func cmpIndexVal(a, b interface{}) int {
	d := a.(IndexVal).val - b.(IndexVal).val
	return d
}

type SegmentNode struct {
	index int
	val   i64
}

func funcSegmentNode(c, a, b interface{}) {
	p := a.(SegmentNode)
	q := b.(SegmentNode)
	if p.val < q.val {
		*(*SegmentNode)(c) = p
	} else {
		*(*SegmentNode)(c) = q
	}
}

type Edge struct {
	a int
	b int
	c i64
}

func cmpEdge(a, b interface{}) int {
	d := a.(Edge).c - b.(Edge).c
	return d
}

func run() {
	var n, d int
	fmt.Scan(&n, &d)
	a := make([]int, n)
	p := make([]IndexVal, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		p[i] = IndexVal{i, a[i]}
	}
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(p), func(i, j int) {
		p[i], p[j] = p[j], p[i]
	})
	ini := SegmentNode{n, (i64)(n + 2) * 1000000000 + 1}
	l := NewSegmentTree([]byte(ini), n, int(unsafe.Sizeof(ini)), funcSegmentNode)
	r := NewSegmentTree([]byte(ini), n, int(unsafe.Sizeof(ini)), funcSegmentNode)
	for i := 0; i < n; i++ {
		l.UpdateTmp(i, []byte(SegmentNode{i, (i64)(a[i] + (i64)(n - 1 - i) * d)}))
		r.UpdateTmp(i, []byte(SegmentNode{i, (i64)(a[i] + (i64)i * d)}))
	}
	l.UpdateAll()
	r.UpdateAll()
	h := NewBinaryHeap(int(unsafe.Sizeof(Edge{})), cmpEdge)
	for i := 0; i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t SegmentNode
			l.Find(0, v, []byte(t))
			h.Push([]byte(Edge{v, t.index, (i64)(p[i].val + t.val - (i64)(n - 1 - v) * d)}))
		}
		if v+1 < n {
			var t SegmentNode
			r.Find(v+1, n, []byte(t))
			h.Push([]byte(Edge{v, t.index, (i64)(p[i].val + t.val - (i64)v * d)}))
		}
		l.Update(v, []byte(ini))
		r.Update(v, []byte(ini))
	}
	var sum i64
	u := NewUnionFind(n)
	for u.GetSize(0) < n {
		var e Edge
		h.Pop([]byte(e))
		if u.Same(e.a, e.b) {
			continue
		}
		u.Unite(e.a, e.b)
		sum += e.c
	}
	fmt.Printf("%d\n", sum)
}

func main() {
	run()
}

