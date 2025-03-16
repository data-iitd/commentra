package main

import (
	"fmt"
	"unsafe"
)

type binaryHeap struct {
	array    unsafe.Pointer
	heapSize int
	maxSize  int
	valSize  int
	cmp      func(a, b unsafe.Pointer) int
}

func newBinaryHeap(valSize int, cmp func(a, b unsafe.Pointer) int) *binaryHeap {
	h := &binaryHeap{
		array:    unsafe.Pointer(newSlice(valSize, 1)),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:      cmp,
	}
	return h
}

func (h *binaryHeap) getHeapSize() int {
	return h.heapSize
}

func (h *binaryHeap) isEmpty() bool {
	return h.heapSize == 0
}

func (h *binaryHeap) freeHeap() {
	free(h.array)
	free(h)
}

func (h *binaryHeap) initHeap() {
	h.heapSize = 0
}

func heapFuncSwap(a, b unsafe.Pointer, valSize int) {
	if valSize%8 == 0 {
		pa := (*[1 << 30]byte)(a)
		pb := (*[1 << 30]byte)(b)
		for i := 0; i < valSize; i++ {
			pa[i], pb[i] = pb[i], pa[i]
		}
	} else {
		pa := (*byte)(a)
		pb := (*byte)(b)
		for i := 0; i < valSize; i++ {
			pa[i], pb[i] = pb[i], pa[i]
		}
	}
}

func heapFuncCopy(dst, src unsafe.Pointer, valSize int) {
	if valSize%8 == 0 {
		ps := (*[1 << 30]byte)(src)
		pd := (*[1 << 30]byte)(dst)
		for i := 0; i < valSize; i++ {
			pd[i] = ps[i]
		}
	} else {
		ps := (*byte)(src)
		pd := (*byte)(dst)
		for i := 0; i < valSize; i++ {
			pd[i] = ps[i]
		}
	}
}

func (h *binaryHeap) push(val unsafe.Pointer) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = unsafe.Pointer(resizeSlice(h.array, h.valSize, h.maxSize+1))
	}
	h.heapSize++
	arr := (*[1 << 30]byte)(h.array)
	k := h.heapSize
	valSize := h.valSize
	cmp := h.cmp
	heapFuncCopy(unsafe.Pointer(uintptr(arr) + uintptr(k)*uintptr(valSize)), val, valSize)
	for k > 1 {
		parent := k / 2
		if cmp(unsafe.Pointer(uintptr(arr)+uintptr(parent)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize))) <= 0 {
			return
		}
		heapFuncSwap(unsafe.Pointer(uintptr(arr)+uintptr(parent)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize)), valSize)
		k = parent
	}
}

func (h *binaryHeap) pop(res unsafe.Pointer) {
	arr := (*[1 << 30]byte)(h.array)
	valSize := h.valSize
	if res != nil {
		heapFuncCopy(res, unsafe.Pointer(uintptr(arr)+uintptr(valSize)), valSize)
	}
	heapFuncCopy(unsafe.Pointer(uintptr(arr)+uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(h.heapSize)*uintptr(valSize)), valSize)
	h.heapSize--
	cmp := h.cmp
	n := h.heapSize
	k := 1
	for 2*k+1 <= n {
		c := cmp(unsafe.Pointer(uintptr(arr)+uintptr(2*k)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(2*k+1)*uintptr(valSize)))
		next := 2*k + (c <= 0 ? 0 : 1)
		if cmp(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(next)*uintptr(valSize))) <= 0 {
			return
		}
		heapFuncSwap(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(next)*uintptr(valSize)), valSize)
		k = next
	}
	if 2*k <= n {
		if cmp(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(2*k)*uintptr(valSize))) > 0 {
			heapFuncSwap(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(valSize)), unsafe.Pointer(uintptr(arr)+uintptr(2*k)*uintptr(valSize)), valSize)
		}
	}
}

func (h *binaryHeap) top(res unsafe.Pointer) {
	arr := (*[1 << 30]byte)(h.array)
	valSize := h.valSize
	if res != nil {
		heapFuncCopy(res, unsafe.Pointer(uintptr(arr)+uintptr(valSize)), valSize)
	}
}

type unionFind struct {
	parent []int
	size   int
}

func newUnionFind(size int) *unionFind {
	u := &unionFind{
		parent: make([]int, size),
		size:   size,
	}
	u.initUnionFind()
	return u
}

func (u *unionFind) initUnionFind() {
	for i := 0; i < u.size; i++ {
		u.parent[i] = -1
	}
}

func (u *unionFind) root(x int) int {
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

func (u *unionFind) same(x, y int) bool {
	return u.root(x) == u.root(y)
}

func (u *unionFind) getSize(x int) int {
	return -u.parent[u.root(x)]
}

func (u *unionFind) unite(x, y int) {
	x = u.root(x)
	y = u.root(y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

type segmentTree struct {
	array    unsafe.Pointer
	size     int
	valSize  int
	func_    func(a, b unsafe.Pointer)
}

func newSegmentTree(ini unsafe.Pointer, n int, valSize int, f func(a, b unsafe.Pointer)) *segmentTree {
	k := 1
	for k < n {
		k *= 2
	}
	s := &segmentTree{
		array:    calloc(2 * k * valSize),
		size:     k,
		valSize:  valSize,
		func_:    f,
	}
	for i := k; i < 2*k; i++ {
		segmentTreeMemcpy(s.array, ini, valSize)
	}
	for i := k - 1; i > 0; i-- {
		f(unsafe.Pointer(uintptr(s.array)+uintptr(i)*uintptr(valSize)), unsafe.Pointer(uintptr(s.array)+uintptr(2*i)*uintptr(valSize)), unsafe.Pointer(uintptr(s.array)+uintptr(2*i+1)*uintptr(valSize)))
	}
	return s
}

func segmentTreeMemcpy(dst, src unsafe.Pointer, size int) {
	pd := (*[1 << 30]byte)(dst)
	ps := (*[1 << 30]byte)(src)
	for i := 0; i < size; i++ {
		pd[i] = ps[i]
	}
}

func (s *segmentTree) update(k int, val unsafe.Pointer) {
	k += s.size
	arr := (*[1 << 30]byte)(s.array)
	size := s.valSize
	for k > 0 {
		s.func_(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(size)), val, val)
		k >>= 1
	}
}

func (s *segmentTree) updateTmp(k int, val unsafe.Pointer) {
	k += s.size
	arr := (*[1 << 30]byte)(s.array)
	size := s.valSize
	for k > 0 {
		s.func_(unsafe.Pointer(uintptr(arr)+uintptr(k)*uintptr(size)), val, val)
		k >>= 1
	}
}

func (s *segmentTree) updateAll() {
	arr := (*[1 << 30]byte)(s.array)
	size := s.valSize
	for i := s.size - 1; i > 0; i-- {
		s.func_(unsafe.Pointer(uintptr(arr)+uintptr(i)*uintptr(size)), unsafe.Pointer(uintptr(arr)+uintptr(2*i)*uintptr(size)), unsafe.Pointer(uintptr(arr)+uintptr(2*i+1)*uintptr(size)))
	}
}

func (s *segmentTree) find(l, r int, res unsafe.Pointer) {
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
	arr := (*[1 << 30]byte)(s.array)
	size := s.valSize
	segmentTreeMemcpy(res, unsafe.Pointer(uintptr(arr)+uintptr(lindex[0])*uintptr(size)), size)
	for i := 1; i < len(lindex); i++ {
		s.func_(res, res, unsafe.Pointer(uintptr(arr)+uintptr(lindex[i])*uintptr(size)))
	}
	for i := len(rindex) - 1; i >= 0; i-- {
		s.func_(res, res, unsafe.Pointer(uintptr(arr)+uintptr(rindex[i])*uintptr(size)))
	}
}

type i32 int32
type i64 int64

type indexVal struct {
	index int
	val   int
}

func cmpIndexVal(a, b unsafe.Pointer) int {
	d := (*indexVal)(a).val - (*indexVal)(b).val
	return d
}

type segmentNode struct {
	index int
	val   i64
}

func funcSegmentNode(c, a, b unsafe.Pointer) {
	p := (*segmentNode)(a)
	q := (*segmentNode)(b)
	if p.val < q.val {
		*(*segmentNode)(c) = *p
	} else {
		*(*segmentNode)(c) = *q
	}
}

type edge struct {
	a int
	b int
	c i64
}

func cmpEdge(a, b unsafe.Pointer) int {
	d := (*edge)(a).c - (*edge)(b).c
	return d
}

func run() {
	var n, d int
	fmt.Scan(&n, &d)
	a := make([]int, n)
	p := make([]indexVal, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		p[i] = indexVal{i, a[i]}
	}
	qsort(unsafe.Pointer(&p[0]), int(n), int(unsafe.Sizeof(indexVal{})), cmpIndexVal)
	ini := segmentNode{n, i64(n+2)*1000000000 + 1}
	l := newSegmentTree(&ini, n, int(unsafe.Sizeof(segmentNode{})), funcSegmentNode)
	r := newSegmentTree(&ini, n, int(unsafe.Sizeof(segmentNode{})), funcSegmentNode)
	for i := 0; i < n; i++ {
		v := p[i].index
		t := segmentNode{v, i64(a[v] + i64(n-1-v)*i64(d))}
		l.updateTmp(v, &t)
		t.index = v
		t.val = i64(a[v] + i64(v)*i64(d))
		r.updateTmp(v, &t)
	}
	l.updateAll()
	r.updateAll()
	h := newBinaryHeap(int(unsafe.Sizeof(edge{})), cmpEdge)
	for i := 0; i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t segmentNode
			l.find(0, v, &t)
			push(h, &edge{v, t.index, i64(p[i].val + t.val)})
		}
	}
