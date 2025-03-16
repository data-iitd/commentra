package main

import (
	"fmt"
	"math"
	"sort"
	"unsafe"
)

type Heap struct {
	array     []byte
	heapSize  int
	maxSize   int
	valSize   int
	cmp       func(a, b unsafe.Pointer) int
}

func NewBinaryHeap(valSize int, cmpF func(a, b unsafe.Pointer) int) *Heap {
	h := &Heap{
		array:   make([]byte, valSize*(1+1)),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:     cmpF,
	}
	return h
}

func (h *Heap) GetHeapSize() int {
	return h.heapSize
}

func (h *Heap) IsEmpty() bool {
	return h.heapSize == 0
}

func (h *Heap) FreeHeap() {
	h.array = nil
}

func (h *Heap) InitHeap() {
	h.heapSize = 0
}

func heapFuncSwap(a, b unsafe.Pointer, valSize int) {
	for i := 0; i < valSize; i++ {
		*(*byte)(unsafe.Pointer(uintptr(a) + uintptr(i))) = *(*byte)(unsafe.Pointer(uintptr(b) + uintptr(i)))
	}
}

func heapFuncCopy(dst, src unsafe.Pointer, valSize int) {
	for i := 0; i < valSize; i++ {
		*(*byte)(unsafe.Pointer(uintptr(dst) + uintptr(i))) = *(*byte)(unsafe.Pointer(uintptr(src) + uintptr(i)))
	}
}

func (h *Heap) Push(val unsafe.Pointer) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = append(h.array, make([]byte, h.valSize*(h.maxSize+1))...)
	}
	h.heapSize++
	k := h.heapSize
	valSize := h.valSize
	h.array = append(h.array, make([]byte, valSize)...)
	heapFuncCopy(unsafe.Pointer(&h.array[(k-1)*valSize]), val, valSize)

	for k > 1 {
		parent := k / 2
		if h.cmp(unsafe.Pointer(&h.array[(parent-1)*valSize]), unsafe.Pointer(&h.array[(k-1)*valSize])) <= 0 {
			return
		}
		heapFuncSwap(unsafe.Pointer(&h.array[(parent-1)*valSize]), unsafe.Pointer(&h.array[(k-1)*valSize]), valSize)
		k = parent
	}
}

func (h *Heap) Pop(res unsafe.Pointer) {
	if res != nil {
		heapFuncCopy(res, unsafe.Pointer(&h.array[0]), h.valSize)
	}
	heapFuncCopy(unsafe.Pointer(&h.array[0]), unsafe.Pointer(&h.array[(h.heapSize-1)*h.valSize]), h.valSize)
	h.heapSize--
	n := h.heapSize
	k := 1
	for 2*k <= n {
		next := 2*k + 1
		if next > n {
			next = 2 * k
		}
		if h.cmp(unsafe.Pointer(&h.array[(k-1)*h.valSize]), unsafe.Pointer(&h.array[(next-1)*h.valSize])) <= 0 {
			return
		}
		heapFuncSwap(unsafe.Pointer(&h.array[(k-1)*h.valSize]), unsafe.Pointer(&h.array[(next-1)*h.valSize]), h.valSize)
		k = next
	}
}

func (h *Heap) Top(res unsafe.Pointer) {
	if res != nil {
		heapFuncCopy(res, unsafe.Pointer(&h.array[0]), h.valSize)
	}
}

type UnionFind struct {
	parent []int32
	size   int32
}

func InitUnionFind(u *UnionFind) {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1
	}
}

func NewUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size:   size,
	}
	InitUnionFind(u)
	return u
}

func (u *UnionFind) FreeUnionFind() {
	u.parent = nil
}

func (u *UnionFind) Root(x int32) int32 {
	index := make([]int32, 32)
	len := 0
	for u.parent[x] >= 0 {
		index[len] = x
		len++
		x = u.parent[x]
	}
	for len > 0 {
		u.parent[index[len-1]] = x
		len--
	}
	return x
}

func (u *UnionFind) Same(x, y int32) bool {
	return u.Root(x) == u.Root(y)
}

func (u *UnionFind) GetSize(x int32) int32 {
	return -u.parent[u.Root(x)]
}

func (u *UnionFind) Unite(x, y int32) {
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
	array   []byte
	size    int32
	valSize int
	funcPtr func(c, a, b unsafe.Pointer)
}

func NewSegmentTree(ini unsafe.Pointer, n int32, valSize int, funcPtr func(c, a, b unsafe.Pointer)) *SegmentTree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &SegmentTree{
		array:   make([]byte, 2*k*int32(valSize)),
		size:    k,
		valSize: valSize,
		funcPtr: funcPtr,
	}
	for i := k; i < 2*k; i++ {
		heapFuncCopy(unsafe.Pointer(&s.array[i*int32(valSize)]), ini, valSize)
	}
	for i := k - 1; i > 0; i-- {
		funcPtr(unsafe.Pointer(&s.array[i*int32(valSize)]), unsafe.Pointer(&s.array[2*i*int32(valSize)]), unsafe.Pointer(&s.array[(2*i+1)*int32(valSize)]))
	}
	return s
}

func (s *SegmentTree) Update(k int32, val unsafe.Pointer) {
	k += s.size
	heapFuncCopy(unsafe.Pointer(&s.array[k*int32(s.valSize)]), val, s.valSize)
	for k >>= 1; k > 0; k >>= 1 {
		s.funcPtr(unsafe.Pointer(&s.array[k*int32(s.valSize)]), unsafe.Pointer(&s.array[2*k*int32(s.valSize)]), unsafe.Pointer(&s.array[(2*k+1)*int32(s.valSize)]))
	}
}

func (s *SegmentTree) UpdateTmp(k int32, val unsafe.Pointer) {
	k += s.size
	heapFuncCopy(unsafe.Pointer(&s.array[k*int32(s.valSize)]), val, s.valSize)
}

func (s *SegmentTree) UpdateAll() {
	for i := s.size - 1; i > 0; i-- {
		s.funcPtr(unsafe.Pointer(&s.array[i*int32(s.valSize)]), unsafe.Pointer(&s.array[2*i*int32(s.valSize)]), unsafe.Pointer(&s.array[(2*i+1)*int32(s.valSize)]))
	}
}

func (s *SegmentTree) Find(l, r int32, res unsafe.Pointer) {
	lindex := make([]int32, 32)
	rindex := make([]int32, 32)
	llen := 0
	rlen := 0
	for l += s.size; r > l; l >>= 1 {
		if l&1 != 0 {
			lindex[llen] = l
			llen++
			l++
		}
		if r&1 != 0 {
			r--
			rindex[rlen] = r
			rlen++
		}
	}
	if llen == 0 {
		lindex[llen] = rindex[rlen-1]
		llen++
	}
	heapFuncCopy(res, unsafe.Pointer(&s.array[lindex[0]*int32(s.valSize)]), s.valSize)
	for i := 1; i < llen; i++ {
		s.funcPtr(res, res, unsafe.Pointer(&s.array[lindex[i]*int32(s.valSize)]))
	}
	for i := rlen - 1; i >= 0; i-- {
		s.funcPtr(res, res, unsafe.Pointer(&s.array[rindex[i]*int32(s.valSize)]))
	}
}

type IndexVal struct {
	index int32
	val   int32
}

func cmpIndexVal(a, b unsafe.Pointer) int {
	d := (*(*IndexVal)(a)).val - (*(*IndexVal)(b)).val
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	}
	return 1
}

type SegmentNode struct {
	index int32
	val   int64
}

func funcSegmentNode(c, a, b unsafe.Pointer) {
	p := (*SegmentNode)(a)
	q := (*SegmentNode)(b)
	if p.val < q.val {
		*(*SegmentNode)(c) = *p
	} else {
		*(*SegmentNode)(c) = *q
	}
}

type Edge struct {
	a, b int32
	c    int64
}

func cmpEdge(a, b unsafe.Pointer) int {
	d := (*(*Edge)(a)).c - (*(*Edge)(b)).c
	if d == 0 {
		return 0
	} else if d < 0 {
		return -1
	}
	return 1
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
		return cmpIndexVal(unsafe.Pointer(&p[i]), unsafe.Pointer(&p[j])) < 0
	})
	ini := SegmentNode{n, int64((n+2)*1000000000 + 1)}
	l := NewSegmentTree(unsafe.Pointer(&ini), n, int(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)
	r := NewSegmentTree(unsafe.Pointer(&ini), n, int(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)
	for i := int32(0); i < n; i++ {
		l.UpdateTmp(i, unsafe.Pointer(&SegmentNode{i, a[i] + int64(n-1-i)*d}))
		r.UpdateTmp(i, unsafe.Pointer(&SegmentNode{i, a[i] + int64(i)*d}))
	}
	l.UpdateAll()
	r.UpdateAll()
	h := NewBinaryHeap(int(unsafe.Sizeof(Edge{})), cmpEdge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t SegmentNode
			l.Find(0, v, unsafe.Pointer(&t))
			h.Push(unsafe.Pointer(&Edge{v, t.index, p[i].val + t.val}))
		}
	}
}

func main() {
	run()
}

// <END-OF-CODE>
