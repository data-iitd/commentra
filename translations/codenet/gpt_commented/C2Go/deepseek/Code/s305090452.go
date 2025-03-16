package main

import (
	"fmt"
	"math/rand"
	"time"
)

// Define a structure for a binary heap
type heap struct {
	array    []byte
	heapSize int
	maxSize  int
	valSize  int
	cmp      func(a, b []byte) int
}

// Function to create a new binary heap
func newBinaryHeap(valSize int, cmp func(a, b []byte) int) *heap {
	h := &heap{
		array:    make([]byte, valSize*(1+1)),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:      cmp,
	}
	return h
}

// Function to get the current size of the heap
func getHeapSize(h *heap) int {
	return h.heapSize
}

// Function to check if the heap is empty
func isEmpty(h *heap) bool {
	return h.heapSize == 0
}

// Function to free the memory allocated for the heap
func freeHeap(h *heap) {
	// No dynamic memory allocation in Go, so nothing to free
}

// Function to initialize the heap
func initHeap(h *heap) {
	h.heapSize = 0
}

// Function to swap two elements in the heap
func heapFuncSwap(a, b []byte, valSize int) {
	// Swap elements based on their size (optimized for 64-bit values)
	if valSize%8 == 0 {
		for i := 0; i < valSize/8; i++ {
			a[i], b[i] = b[i], a[i]
		}
	} else {
		// Fallback for other sizes
		for i := 0; i < valSize; i++ {
			a[i], b[i] = b[i], a[i]
		}
	}
}

// Function to copy values from source to destination
func heapFuncCopy(dst, src []byte, valSize int) {
	// Copy elements based on their size (optimized for 64-bit values)
	if valSize%8 == 0 {
		for i := 0; i < valSize/8; i++ {
			dst[i] = src[i]
		}
	} else {
		// Fallback for other sizes
		for i := 0; i < valSize; i++ {
			dst[i] = src[i]
		}
	}
}

// Function to push a new value into the heap
func push(h *heap, val []byte) {
	// Check if the heap needs to be resized
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = append(h.array, make([]byte, h.valSize*(h.maxSize+1)-len(h.array))...)
	}
	h.heapSize++
	array := h.array
	k := h.heapSize
	valSize := h.valSize
	cmp := h.cmp
	heapFuncCopy(array[k*valSize:], val, valSize)
	// Maintain the heap property by moving the new element up the heap
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*valSize:], array[k*valSize:]) <= 0 {
			return
		}
		heapFuncSwap(array[parent*valSize:], array[k*valSize:], valSize)
		k = parent
	}
}

// Function to pop the top value from the heap
func pop(h *heap, res []byte) {
	array := h.array
	valSize := h.valSize
	if res != nil {
		heapFuncCopy(res, array[valSize:], valSize)
	}
	heapFuncCopy(array[valSize:], array[valSize*h.heapSize:], valSize)
	h.heapSize--
	cmp := h.cmp
	n := h.heapSize
	k := 1
	// Maintain the heap property by moving the top element down the heap
	for 2*k+1 <= n {
		c := cmp(array[2*k*valSize:], array[(2*k+1)*valSize:])
		next := 2*k + (c <= 0 ? 0 : 1)
		if cmp(array[k*valSize:], array[next*valSize:]) <= 0 {
			return
		}
		heapFuncSwap(array[k*valSize:], array[next*valSize:], valSize)
		k = next
	}
	// Check if the last child needs to be swapped
	if 2*k <= n {
		if cmp(array[k*valSize:], array[2*k*valSize:]) > 0 {
			heapFuncSwap(array[k*valSize:], array[2*k*valSize:], valSize)
		}
	}
}

// Function to get the top value of the heap without removing it
func top(h *heap, res []byte) {
	heapFuncCopy(res, h.array[h.valSize:], h.valSize)
}

// Define a structure for Union-Find (Disjoint Set Union)
type UnionFind struct {
	parent []int
	size   int
}

// Function to initialize the Union-Find structure
func initUnionFind(u *UnionFind) {
	for i := 0; i < u.size; i++ {
		u.parent[i] = -1
	}
}

// Function to create a new Union-Find structure
func newUnionFind(size int) *UnionFind {
	u := &UnionFind{
		parent: make([]int, size),
		size:   size,
	}
	initUnionFind(u)
	return u
}

// Function to free the memory allocated for the Union-Find structure
func freeUnionFind(u *UnionFind) {
	// No dynamic memory allocation in Go, so nothing to free
}

// Function to find the root of an element with path compression
func root(u *UnionFind, x int) int {
	index := []int{}
	for u.parent[x] >= 0 {
		index = append(index, x)
		x = u.parent[x]
	}
	// Path compression: make all nodes point directly to the root
	for _, idx := range index {
		u.parent[idx] = x
	}
	return x
}

// Function to check if two elements are in the same set
func same(u *UnionFind, x, y int) bool {
	return root(u, x) == root(u, y)
}

// Function to get the size of the set containing element x
func getSize(u *UnionFind, x int) int {
	return -u.parent[root(u, x)]
}

// Function to unite two sets containing elements x and y
func unite(u *UnionFind, x, y int) {
	x = root(u, x)
	y = root(u, y)
	if x == y {
		return
	}
	// Union by size: attach the smaller tree under the larger tree
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

// Define a structure for a segment tree
type segmentTree struct {
	array    []byte
	size     int
	valSize  int
	combine  func(a, b, c []byte)
}

// Function to copy memory from source to destination
func segmentTreeMemcpy(dst, src []byte, size int) {
	copy(dst, src)
}

// Function to create a new segment tree
func newSegmentTree(ini []byte, n int, valSize int, combine func(a, b, c []byte)) *segmentTree {
	k := 1
	for k < n {
		k *= 2
	}
	s := &segmentTree{
		array:    make([]byte, 2*k*valSize),
		size:     k,
		valSize:  valSize,
		combine:  combine,
	}
	// Initialize the leaves of the segment tree
	copy(s.array[k*valSize:], ini)
	// Build the segment tree by combining child nodes
	for i := k - 1; i > 0; i-- {
		combine(s.array[i*valSize:], s.array[2*i*valSize:], s.array[(2*i+1)*valSize:])
	}
	return s
}

// Function to update a value in the segment tree
func update(s *segmentTree, k int, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	segmentTreeMemcpy(p[k*size:], val, size)
	// Update the segment tree upwards
	for k >>= 1; k > 0; k >>= 1 {
		s.combine(p[k*size:], p[2*k*size:], p[2*k*size+s.valSize:])
	}
}

// Function to update a value temporarily in the segment tree
func updateTmp(s *segmentTree, k int, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	segmentTreeMemcpy(p[k*size:], val, size)
}

// Function to update all nodes in the segment tree
func updateAll(s *segmentTree) {
	p := s.array
	size := s.valSize
	// Update the segment tree from the leaves to the root
	for i := s.size - 1; i > 0; i-- {
		s.combine(p[i*size:], p[2*i*size:], p[2*i*size+s.valSize:])
	}
}

// Function to find the result in a range of the segment tree
func find(s *segmentTree, l, r int, res []byte) {
	lindex := []int{}
	rindex := []int{}
	// Traverse the segment tree to find the indices
	for l += s.size; l < r; l >>= 1 {
		if l&1 != 0 {
			lindex = append(lindex, l)
			l++
		}
	}
	for r += s.size; l < r; r >>= 1 {
		if r&1 != 0 {
			rindex = append(rindex, r-1)
		}
	}
	if len(lindex) == 0 {
		lindex = append(lindex, rindex[0])
		rindex = rindex[:len(rindex)-1]
	}
	segmentTreeMemcpy(res, p[lindex[0]*size:], size)
	// Combine results from left indices
	for i := 1; i < len(lindex); i++ {
		s.combine(res, res, p[lindex[i]*size:])
	}
	// Combine results from right indices
	for i := len(rindex) - 1; i >= 0; i-- {
		s.combine(res, res, p[rindex[i]*size:])
	}
}

// Define integer types for convenience
type i32 int32
type i64 int64

// Define a structure for index-value pairs
type indexVal struct {
	index int
	val   int
}

// Comparison function for index-value pairs
func cmpIndexVal(a, b interface{}) int {
	d := a.(indexVal).val - b.(indexVal).val
	return d
}

// Define a structure for segment tree nodes
type segmentNode struct {
	index int
	val   i64
}

// Function to combine two segment nodes
func funcSegmentNode(a, b, c []byte) {
	p := (*segmentNode)(unsafe.Pointer(&a[0]))
	q := (*segmentNode)(unsafe.Pointer(&b[0]))
	r := (*segmentNode)(unsafe.Pointer(&c[0]))
	*p = segmentNode{p.index, min(p.val, q.val)}
}

// Define a structure for edges
type edge struct {
	a, b int
	c    i64
}

// Comparison function for edges
func cmpEdge(a, b interface{}) int {
	d := a.(edge).c - b.(edge).c
	return d
}

// Main function to run the algorithm
func run() {
	var n, d int
	fmt.Scan(&n, &d)
	a := make([]int, n)
	p := make([]indexVal, n)
	// Read values and initialize index-value pairs
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		p[i] = indexVal{i, a[i]}
	}
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(p), func(i, j int) { p[i], p[j] = p[j], p[i] })
	const ini = segmentNode{n, (n + 2) * 1000000000 + 1}
	l := newSegmentTree([]byte(ini), n, unsafe.Sizeof(ini), funcSegmentNode)
	r := newSegmentTree([]byte(ini), n, unsafe.Sizeof(ini), funcSegmentNode)
	// Update segment trees with adjusted values
	for i := 0; i < n; i++ {
		updateTmp(l, i, []byte(segmentNode{i, int64(a[i] + (n - 1 - i) * d)}))
		updateTmp(r, i, []byte(segmentNode{i, int64(a[i] + i * d)}))
	}
	updateAll(l)
	updateAll(r)
	h := newBinaryHeap(unsafe.Sizeof(edge{}), func(a, b []byte) int {
		p := (*edge)(unsafe.Pointer(&a[0]))
		q := (*edge)(unsafe.Pointer(&b[0]))
		return int(p.c - q.c)
	})
	// Process each index-value pair
	for i := 0; i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t segmentNode
			find(l, 0, v, []byte(t))
			push(h, []byte(edge{v, t.index, int64(p[i].val + t.val - (n - 1 - v) * d)}))
		}
		if v+1 < n {
			var t segmentNode
			find(r, v+1, n, []byte(t))
			push(h, []byte(edge{v, t.index, int64(p[i].val + t.val - i * d)}))
		}
		update(l, v, []byte(ini))
		update(r, v, []byte(ini))
	}
	var sum i64
	u := newUnionFind(n)
	// Process edges in the heap to find the minimum spanning tree
	for getSize(u, 0) < n {
		var e edge
		pop(h, []byte(e))
		if same(u, e.a, e.b) {
			continue
		}
		unite(u, e.a, e.b)
		sum += e.c
	}
	fmt.Println(sum)
}

// Main entry point of the program
func main() {
	run()
}

