package main

import (
	"fmt"
	"math/rand"
	"time"
)

// Define the structure of a binary heap and its operations.
type heap struct {
	array     []byte
	heapSize  int
	maxSize   int
	valSize   int
	cmp       func(a, b []byte) int
}

// Initialize a new binary heap with a given value size and comparison function.
func newBinaryHeap(valSize int, cmp func(a, b []byte) int) *heap {
	h := &heap{
		array:   make([]byte, valSize*(1+1)),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:      cmp,
	}
	return h
}

// Return the current size of the heap.
func (h *heap) getHeapSize() int {
	return h.heapSize
}

// Check if the heap is empty.
func (h *heap) isEmpty() bool {
	return h.heapSize == 0
}

// Free the memory allocated for the heap.
func (h *heap) freeHeap() {
	h.array = nil
	h.heapSize = 0
	h.maxSize = 0
	h.valSize = 0
	h.cmp = nil
}

// Initialize the heap size to zero.
func (h *heap) initHeap() {
	h.heapSize = 0
}

// Swap two elements of the heap.
func heapSwap(a, b []byte, valSize int) {
	if (valSize & 7) == 0 {
		for i := 0; i < valSize/8; i++ {
			a[i], b[i] = b[i], a[i]
		}
	} else {
		for i := 0; i < valSize; i++ {
			a[i], b[i] = b[i], a[i]
		}
	}
}

// Copy one element to another.
func heapCopy(dst, src []byte, valSize int) {
	if (valSize & 7) == 0 {
		for i := 0; i < valSize/8; i++ {
			dst[i] = src[i]
		}
	} else {
		for i := 0; i < valSize; i++ {
			dst[i] = src[i]
		}
	}
}

// Add a new element to the heap.
func (h *heap) push(val []byte) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = realloc(h.array, h.valSize*(h.maxSize+1))
	}
	h.heapSize++
	array := h.array
	k := h.heapSize
	valSize := h.valSize
	for k > 1 {
		parent := k / 2
		if h.cmp(array[parent*valSize:], array[k*valSize:]) <= 0 {
			return
		}
		heapSwap(array[parent*valSize:], array[k*valSize:], valSize)
		k = parent
	}
	heapCopy(array[k*valSize:], val, valSize)
}

// Remove the top element from the heap.
func (h *heap) pop(res []byte) {
	if res != nil {
		heapCopy(res, h.array[h.valSize:], h.valSize)
	}
	heapCopy(h.array[h.valSize:], h.array[h.valSize*h.heapSize:], h.valSize)
	h.heapSize--
	n := h.heapSize
	k := 1
	for 2*k+1 <= n {
		c := h.cmp(h.array[2*k*h.valSize:], h.array[(2*k+1)*h.valSize:])
		next := 2*k + (c <= 0 ? 0 : 1)
		if h.cmp(h.array[k*h.valSize:], h.array[next*h.valSize:]) <= 0 {
			return
		}
		heapSwap(h.array[k*h.valSize:], h.array[next*h.valSize:], h.valSize)
		k = next
	}
	if 2*k <= n {
		if h.cmp(h.array[k*h.valSize:], h.array[2*k*h.valSize:]) > 0 {
			heapSwap(h.array[k*h.valSize:], h.array[2*k*h.valSize:], h.valSize)
		}
	}
}

// Return the top element of the heap without removing it.
func (h *heap) top(res []byte) {
	if res != nil {
		heapCopy(res, h.array[h.valSize:], h.valSize)
	}
}

// Define the structure of Union-Find and its operations.
type UnionFind struct {
	parent []int
	size   int
}

// Initialize the parent array to -1.
func (u *UnionFind) initUnionFind() {
	for i := 0; i < u.size; i++ {
		u.parent[i] = -1
	}
}

// Initialize a new Union-Find structure with a given size.
func newUnionFind(size int) *UnionFind {
	u := &UnionFind{
		parent: make([]int, size),
		size:   size,
	}
	u.initUnionFind()
	return u
}

// Free the memory allocated for the Union-Find structure.
func (u *UnionFind) freeUnionFind() {
	u.parent = nil
	u.size = 0
}

// Find the root of a given element.
func (u *UnionFind) root(x int) int {
	index := []int{}
	for u.parent[x] >= 0 {
		index = append(index, x)
		x = u.parent[x]
	}
	for _, idx := range index {
		u.parent[idx] = x
	}
	return x
}

// Check if two elements are in the same set.
func (u *UnionFind) same(x, y int) bool {
	return u.root(x) == u.root(y)
}

// Return the size of the set containing a given element.
func (u *UnionFind) getSize(x int) int {
	return -u.parent[u.root(x)]
}

// Merge two sets.
func (u *UnionFind) unite(x, y int) {
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

// Define the structure of a segment tree and its operations.
type segmentTree struct {
	array    []byte
	size     int
	valSize  int
	merge    func(c, a, b []byte)
}

// Copy one memory area to another.
func segmentTreeMemcpy(dst, src []byte, size int) {
	for i := 0; i < size; i++ {
		dst[i] = src[i]
	}
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
func newSegmentTree(ini []byte, n, valSize int, merge func(c, a, b []byte)) *segmentTree {
	k := 1
	for k < n {
		k *= 2
	}
	s := &segmentTree{
		array:   make([]byte, 2*k*valSize),
		size:    k,
		valSize: valSize,
		merge:   merge,
	}
	segmentTreeMemcpy(s.array[k*valSize:], ini, n*valSize)
	for i := k - 1; i > 0; i-- {
		merge(s.array[i*valSize:], s.array[2*i*valSize:], s.array[(2*i+1)*valSize:])
	}
	return s
}

// Update a segment tree node.
func (s *segmentTree) update(k int, val []byte) {
	k += s.size
	array := s.array
	for i := k; i > 1; i >>= 1 {
		s.merge(array[i>>1*s.valSize:], array[i*s.valSize:], array[(i^1)*s.valSize:])
	}
	segmentTreeMemcpy(array[k*s.valSize:], val, s.valSize)
}

// Temporarily update a segment tree node.
func (s *segmentTree) updateTmp(k int, val []byte) {
	k += s.size
	array := s.array
	segmentTreeMemcpy(array[k*s.valSize:], val, s.valSize)
}

// Update all segment tree nodes.
func (s *segmentTree) updateAll() {
	array := s.array
	for i := s.size - 1; i > 0; i-- {
		s.merge(array[i*s.valSize:], array[2*i*s.valSize:], array[(2*i+1)*s.valSize:])
	}
}

// Find the result of applying the merge function to a range of segment tree nodes.
func (s *segmentTree) find(l, r int, res []byte) {
	l += s.size
	r += s.size
	array := s.array
	for l < r {
		if l&1 == 1 {
			s.merge(res, res, array[l*s.valSize:])
			l++
		}
		if r&1 == 1 {
			r--
			s.merge(res, res, array[r*s.valSize:])
		}
		l >>= 1
		r >>= 1
	}
}

// Define the main function to run the program.
func run() {
	var n, d int
	fmt.Scan(&n, &d)
	a := make([]int, n)
	p := make([]indexVal, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		p[i] = indexVal{i, a[i]}
	}
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(p), func(i, j int) {
		p[i], p[j] = p[j], p[i]
	})
	ini := segmentNode{n, (int64)(n + 2) * 1000000000 + 1}
	l := newSegmentTree([]byte{}, n, int(unsafe.Sizeof(ini)), func(c, a, b []byte) {
		segmentTreeMemcpy(c, a, int(unsafe.Sizeof(ini)))
		if *(*segmentNode)(a).val < *(*segmentNode)(b).val {
			segmentTreeMemcpy(c, a, int(unsafe.Sizeof(ini)))
		} else {
			segmentTreeMemcpy(c, b, int(unsafe.Sizeof(ini)))
		}
	})
	r := newSegmentTree([]byte{}, n, int(unsafe.Sizeof(ini)), func(c, a, b []byte) {
		segmentTreeMemcpy(c, a, int(unsafe.Sizeof(ini)))
		if *(*segmentNode)(a).val < *(*segmentNode)(b).val {
			segmentTreeMemcpy(c, a, int(unsafe.Sizeof(ini)))
		} else {
			segmentTreeMemcpy(c, b, int(unsafe.Sizeof(ini)))
		}
	})
	for i := 0; i < n; i++ {
		l.updateTmp(i, []byte{})
		r.updateTmp(i, []byte{})
	}
	l.updateAll()
	r.updateAll()
	h := newBinaryHeap(int(unsafe.Sizeof(edge{})), func(a, b []byte) int {
		e1 := (*edge)(a)
		e2 := (*edge)(b)
		if e1.c < e2.c {
			return -1
		} else if e1.c > e2.c {
			return 1
		} else {
			return 0
		}
	})
	for i := 0; i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t segmentNode
			l.find(0, v, []byte{})
			t = *(*segmentNode)(unsafe.Pointer(&l.array[v*int(unsafe.Sizeof(ini))]))
			h.push([]byte{})
		}
		if v+1 < n {
			var t segmentNode
			r.find(v+1, n, []byte{})
			t = *(*segmentNode)(unsafe.Pointer(&r.array[(v+1)*int(unsafe.Sizeof(ini))]))
			h.push([]byte{})
		}
		l.update(v, []byte{})
		r.update(v, []byte{})
	}
	var sum int64
	u := newUnionFind(n)
	for u.getSize(0) < n {
		var e edge
		h.pop([]byte{})
		if u.same(e.a, e.b) {
			continue
		}
		u.unite(e.a, e.b)
		sum += e.c
	}
	fmt.Println(sum)
}

func main() {
	run()
}

