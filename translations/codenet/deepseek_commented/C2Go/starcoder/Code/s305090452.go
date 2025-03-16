<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define the structure of a binary heap and its operations.
type heap struct {
	array    []byte
	heapSize int
	maxSize  int
	valSize  int
	cmp      func(a, b []byte) int
}

// Initialize a new binary heap with a given value size and comparison function.
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

// Return the current size of the heap.
<<<<<<< HEAD
func (h *heap) getHeapSize() int {
=======
func getHeapSize(h *heap) int {
>>>>>>> 98c87cb78a (data updated)
	return h.heapSize
}

// Check if the heap is empty.
<<<<<<< HEAD
func (h *heap) isEmpty() bool {
=======
func is_empty(h *heap) bool {
>>>>>>> 98c87cb78a (data updated)
	return h.heapSize == 0
}

// Free the memory allocated for the heap.
<<<<<<< HEAD
func (h *heap) freeHeap() {
=======
func freeHeap(h *heap) {
>>>>>>> 98c87cb78a (data updated)
	h.array = nil
	h.heapSize = 0
	h.maxSize = 0
	h.valSize = 0
	h.cmp = nil
}

// Initialize the heap size to zero.
<<<<<<< HEAD
func (h *heap) initHeap() {
=======
func initHeap(h *heap) {
>>>>>>> 98c87cb78a (data updated)
	h.heapSize = 0
}

// Swap two elements of the heap.
<<<<<<< HEAD
func (h *heap) swap(a, b int) {
	if (h.valSize & 7) == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&h.array[a*h.valSize]))
		q := (*[8]uint64)(unsafe.Pointer(&h.array[b*h.valSize]))
		valSize := h.valSize / 8
		for ; valSize > 0; valSize-- {
			p[valSize], q[valSize] = q[valSize], p[valSize]
		}
	} else {
		p := (*[8]uint8)(unsafe.Pointer(&h.array[a*h.valSize]))
		q := (*[8]uint8)(unsafe.Pointer(&h.array[b*h.valSize]))
		for i := 0; i < h.valSize; i++ {
			p[i], q[i] = q[i], p[i]
=======
func heapFuncSwap(a, b []byte, valSize int) {
	if (valSize & 7) == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&a[0]))
		q := (*[8]uint64)(unsafe.Pointer(&b[0]))
		valSize /= 8
		for ; valSize > 0; valSize-- {
			p[0], q[0] = q[0], p[0]
			p = p[1:]
			q = q[1:]
		}
	} else {
		p := (*[1]uint8)(unsafe.Pointer(&a[0]))
		q := (*[1]uint8)(unsafe.Pointer(&b[0]))
		for ; valSize > 0; valSize-- {
			p[0], q[0] = q[0], p[0]
			p = p[1:]
			q = q[1:]
>>>>>>> 98c87cb78a (data updated)
		}
	}
}

// Copy one element to another.
<<<<<<< HEAD
func (h *heap) copy(dst, src int) {
	if (h.valSize & 7) == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&h.array[src*h.valSize]))
		q := (*[8]uint64)(unsafe.Pointer(&h.array[dst*h.valSize]))
		valSize := h.valSize / 8
		for ; valSize > 0; valSize-- {
			q[valSize] = p[valSize]
		}
	} else {
		p := (*[8]uint8)(unsafe.Pointer(&h.array[src*h.valSize]))
		q := (*[8]uint8)(unsafe.Pointer(&h.array[dst*h.valSize]))
		for i := 0; i < h.valSize; i++ {
			q[i] = p[i]
=======
func heapFuncCopy(dst, src []byte, valSize int) {
	if (valSize & 7) == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&src[0]))
		q := (*[8]uint64)(unsafe.Pointer(&dst[0]))
		valSize /= 8
		for ; valSize > 0; valSize-- {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
		}
	} else {
		p := (*[1]uint8)(unsafe.Pointer(&src[0]))
		q := (*[1]uint8)(unsafe.Pointer(&dst[0]))
		for ; valSize > 0; valSize-- {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
>>>>>>> 98c87cb78a (data updated)
		}
	}
}

// Add a new element to the heap.
<<<<<<< HEAD
func (h *heap) push(val []byte) {
=======
func push(h *heap, val []byte) {
>>>>>>> 98c87cb78a (data updated)
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = append(h.array, make([]byte, h.valSize*(h.maxSize+1))...)
	}
	h.heapSize++
	array := h.array
	k := h.heapSize
	valSize := h.valSize
	cmp := h.cmp
<<<<<<< HEAD
	copy(array[k*valSize:], val)
=======
	heapFuncCopy(array[k*valSize:], val, valSize)
>>>>>>> 98c87cb78a (data updated)
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*valSize:], array[k*valSize:]) <= 0 {
			return
		}
<<<<<<< HEAD
		h.swap(parent, k)
=======
		heapFuncSwap(array[parent*valSize:], array[k*valSize:], valSize)
>>>>>>> 98c87cb78a (data updated)
		k = parent
	}
}

// Remove the top element from the heap.
<<<<<<< HEAD
func (h *heap) pop(res []byte) {
	array := h.array
	valSize := h.valSize
	if res!= nil {
		copy(res, array[valSize:])
	}
	copy(array[valSize:], array[valSize*h.heapSize:])
	h.heapSize--
	cmp := h.cmp
	n := h.heapSize
	k := 1
	for 2*k+1 <= n {
		c := cmp(array[valSize*2*k:], array[valSize*(2*k+1)])
		next := 2*k + (c <= 0)
		if cmp(array[valSize*k:], array[valSize*next]) <= 0 {
			return
		}
		h.swap(k, next)
		k = next
	}
	if 2*k <= n && cmp(array[valSize*k:], array[valSize*2*k]) > 0 {
		h.swap(k, 2 * k)
=======
func pop(h *heap, res []byte) {
	array := h.array
	valSize := h.valSize
	if res!= nil {
		heapFuncCopy(res, array[valSize:], valSize)
	}
	heapFuncCopy(array[valSize:], array[valSize*h.heapSize:], valSize)
	h.heapSize--
	cmp := h.cmp
	const n = h.heapSize
	k := 1
	for 2*k+1 <= n {
		c := cmp(array[valSize*2*k:], array[valSize*(2*k+1):])
		next := 2*k + (c <= 0)
		if cmp(array[valSize*k:], array[valSize*next:]) <= 0 {
			return
		}
		heapFuncSwap(array[valSize*k:], array[valSize*next:], valSize)
		k = next
	}
	if 2*k <= n && cmp(array[valSize*k:], array[valSize*2*k:]) > 0 {
		heapFuncSwap(array[valSize*k:], array[valSize*2*k:], valSize)
>>>>>>> 98c87cb78a (data updated)
	}
}

// Return the top element of the heap without removing it.
<<<<<<< HEAD
func (h *heap) top(res []byte) {
	array := h.array
	valSize := h.valSize
	if res!= nil {
		copy(res, array[valSize:])
=======
func top(h *heap, res []byte) {
	array := h.array
	valSize := h.valSize
	if res!= nil {
		heapFuncCopy(res, array[valSize:], valSize)
>>>>>>> 98c87cb78a (data updated)
	}
}

// Define the structure of Union-Find and its operations.
type UnionFind struct {
	parent []int32
	size   int32
}

// Initialize the parent array to -1.
<<<<<<< HEAD
func (u *UnionFind) initUnionFind() {
=======
func initUnionFind(u *UnionFind) {
>>>>>>> 98c87cb78a (data updated)
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1
	}
}

// Initialize a new Union-Find structure with a given size.
func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size:   size,
	}
<<<<<<< HEAD
	u.initUnionFind()
=======
	initUnionFind(u)
>>>>>>> 98c87cb78a (data updated)
	return u
}

// Free the memory allocated for the Union-Find structure.
<<<<<<< HEAD
func (u *UnionFind) freeUnionFind() {
=======
func freeUnionFind(u *UnionFind) {
>>>>>>> 98c87cb78a (data updated)
	u.parent = nil
	u.size = 0
}

// Find the root of a given element.
<<<<<<< HEAD
func (u *UnionFind) root(x int32) int32 {
=======
func root(u *UnionFind, x int32) int32 {
>>>>>>> 98c87cb78a (data updated)
	index := make([]int32, 32)
	len := int32(0)
	for u.parent[x] >= 0 {
		index[len] = x
		x = u.parent[x]
		len++
	}
	for len > 0 {
		u.parent[index[len-1]] = x
		len--
	}
	return x
}

// Check if two elements are in the same set.
<<<<<<< HEAD
func (u *UnionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y)
}

// Return the size of the set containing a given element.
func (u *UnionFind) getSize(x int32) int32 {
	return -u.parent[u.root(x)]
}

// Merge two sets.
func (u *UnionFind) unite(x, y int32) {
	x = u.root(x)
	y = u.root(y)
=======
func same(u *UnionFind, x, y int32) bool {
	return root(u, x) == root(u, y)
}

// Return the size of the set containing a given element.
func getSize(u *UnionFind, x int32) int32 {
	return -u.parent[root(u, x)]
}

// Merge two sets.
func unite(u *UnionFind, x, y int32) {
	x = root(u, x)
	y = root(u, y)
>>>>>>> 98c87cb78a (data updated)
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
	size     int32
	valSize  int
<<<<<<< HEAD
	funcVoid func(c, a, b []byte)
}

// Copy one memory area to another.
func (s *segmentTree) memcpy(dst, src int, size int) {
	p := (*[8]uint8)(unsafe.Pointer(&s.array[dst]))
	q := (*[8]uint8)(unsafe.Pointer(&s.array[src]))
	for ; size > 0; size-- {
		p[size] = q[size]
=======
	func     func(c, a, b []byte)
	funcSize int
}

// Copy one memory area to another.
func segmentTreeMemcpy(dst, src []byte, size int) {
	p := (*[1]uint8)(unsafe.Pointer(&dst[0]))
	q := (*[1]uint8)(unsafe.Pointer(&src[0]))
	for ; size > 0; size-- {
		p[0] = q[0]
		p = p[1:]
		q = q[1:]
>>>>>>> 98c87cb78a (data updated)
	}
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
<<<<<<< HEAD
func newSegmentTree(ini []byte, n int32, valSize int, funcVoid func(c, a, b []byte)) *segmentTree {
=======
func newSegmentTree(ini []byte, n int32, valSize int, func_ func(c, a, b []byte)) *segmentTree {
>>>>>>> 98c87cb78a (data updated)
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &segmentTree{
		array:    make([]byte, 2*k*valSize),
		size:     k,
		valSize:  valSize,
<<<<<<< HEAD
		funcVoid: funcVoid,
	}
	for i := k; i < 2*k; i++ {
		s.memcpy(i*valSize, i, valSize)
	}
	a := s.array
	for i := k - 1; i > 0; i-- {
		s.funcVoid(a[i*valSize:], a[2*i*valSize:], a[(2*i+1)*valSize:])
=======
		func:     func_,
		funcSize: int(unsafe.Sizeof(func_)),
	}
	for i := k; i < 2*k; i++ {
		segmentTreeMemcpy(s.array[i*valSize:], ini, valSize)
	}
	a := s.array
	for i := k - 1; i > 0; i-- {
		s.func(a[i*valSize:], a[2*i*valSize:], a[(2*i+1)*valSize:])
>>>>>>> 98c87cb78a (data updated)
	}
	return s
}

// Update a segment tree node.
<<<<<<< HEAD
func (s *segmentTree) update(k int32, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	s.memcpy(k*size, k, size)
	for k >>= 1; k > 0; k >>= 1 {
		s.funcVoid(p[k*size:], p[2*k*size:], p[(2*k+1)*size:])
=======
func update(s *segmentTree, k int32, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	segmentTreeMemcpy(p[k*size:], val, size)
	for k > 1 {
		k >>= 1
		s.func(p[k*size:], p[2*k*size:], p[(2*k+1)*size:])
>>>>>>> 98c87cb78a (data updated)
	}
}

// Temporarily update a segment tree node.
<<<<<<< HEAD
func (s *segmentTree) updateTmp(k int32, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	s.memcpy(k*size, k, size)
}

// Update all segment tree nodes.
func (s *segmentTree) updateAll() {
	a := s.array
	size := s.valSize
	for i := s.size - 1; i > 0; i-- {
		s.funcVoid(a[i*size:], a[2*i*size:], a[(2*i+1)*size:])
=======
func update_tmp(s *segmentTree, k int32, val []byte) {
	k += s.size
	p := s.array
	size := s.valSize
	segmentTreeMemcpy(p[k*size:], val, size)
}

// Update all segment tree nodes.
func update_all(s *segmentTree) {
	a := s.array
	size := s.valSize
	for i := s.size - 1; i > 0; i-- {
		s.func(a[i*size:], a[2*i*size:], a[(2*i+1)*size:])
>>>>>>> 98c87cb78a (data updated)
	}
}

// Find the result of applying the merge function to a range of segment tree nodes.
<<<<<<< HEAD
func (s *segmentTree) find(l, r int32, res []byte) {
=======
func find(s *segmentTree, l, r int32, res []byte) {
>>>>>>> 98c87cb78a (data updated)
	lindex := make([]int32, 32)
	rindex := make([]int32, 32)
	llen := int32(0)
	rlen := int32(0)
	for l += s.size; l < r; l >>= 1 {
		if l&1 > 0 {
			lindex[llen] = l
			llen++
		}
		if r&1 > 0 {
			rindex[rlen] = r - 1
			rlen++
		}
		r >>= 1
	}
	if llen == 0 {
		lindex[llen] = rindex[rlen-1]
		rlen--
	}
<<<<<<< HEAD
	s.memcpy(0, lindex[0], s.valSize)
	for i := int32(1); i < llen; i++ {
		s.funcVoid(res, res, s.array[lindex[i]*s.valSize:])
	}
	for i := rlen - 1; i >= 0; i-- {
		s.funcVoid(res, res, s.array[rindex[i]*s.valSize:])
=======
	segmentTreeMemcpy(res, s.array[lindex[0]*s.valSize:], s.valSize)
	for i := int32(1); i < llen; i++ {
		s.func(res, res, s.array[lindex[i]*s.valSize:])
	}
	for i := rlen - 1; i >= 0; i-- {
		s.func(res, res, s.array[rindex[i]*s.valSize:])
>>>>>>> 98c87cb78a (data updated)
	}
}

// Define the main function to run the program.
<<<<<<< HEAD
func main() {
	reader := bufio.NewReader(os.Stdin)
	n, d := readTwoNums(reader)
	a := readNNums(reader, n)
	p := make([]index_val, n)
	for i := int32(0); i < n; i++ {
=======
func run() {
	n, d := int32(0), int32(0)
	fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString('\n'), "%d %d", &n, &d)
	a := make([]int32, n)
	p := make([]index_val, n)
	for i := int32(0); i < n; i++ {
		fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString('\n'), "%d", a[i])
>>>>>>> 98c87cb78a (data updated)
		p[i] = index_val{i, a[i]}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].val < p[j].val
	})
	ini := segment_node{n, int64(n+2)*1000000000 + 1}
<<<<<<< HEAD
	l := newSegmentTree([]byte(ini), n, int(unsafe.Sizeof(ini)), func_segment_node)
	r := newSegmentTree([]byte(ini), n, int(unsafe.Sizeof(ini)), func_segment_node)
	for i := int32(0); i < n; i++ {
		update_tmp(l, i, []byte{byte(a[i] + (n - 1 - i) * d)})
		update_tmp(r, i, []byte{byte(a[i] + i * d)})
=======
	l := newSegmentTree((*[1]byte)(unsafe.Pointer(&ini)), n, int(unsafe.Sizeof(ini)), func_segment_node)
	r := newSegmentTree((*[1]byte)(unsafe.Pointer(&ini)), n, int(unsafe.Sizeof(ini)), func_segment_node)
	for i := int32(0); i < n; i++ {
		update_tmp(l, i, (*[1]byte)(unsafe.Pointer(&segment_node{i, a[i] + int64(n-1-i)*d})))
		update_tmp(r, i, (*[1]byte)(unsafe.Pointer(&segment_node{i, a[i] + int64(i)*d})))
>>>>>>> 98c87cb78a (data updated)
	}
	update_all(l)
	update_all(r)
	h := newBinaryHeap(int(unsafe.Sizeof(edge{})), cmp_edge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
<<<<<<< HEAD
			t := segment_node{}
			find(l, 0, v, []byte(t))
			push(h, edge{v, t.index, p[i].val + t.val - int64(n-1-v)*d})
		}
		if v+1 < n {
			t := segment_node{}
			find(r, v+1, n, []byte(t))
			push(h, edge{v, t.index, p[i].val + t.val - int64(v)*d})
		}
		update(l, v, []byte(ini))
		update(r, v, []byte(ini))
	}
	sum := int64(0)
	u := newUnionFind(n)
	for!h.isEmpty() {
		e := edge{}
		pop(h, []byte(e))
		if u.same(e.a, e.b) {
			continue
		}
		u.unite(e.a, e.b)
		sum += e.c
	}
	fmt.Println(sum)
}

// Read two integers from a file stream.
func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

// Read n integers from a file stream.
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-':
			x++
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bs []byte, from int, val *int) int {
=======
			var t segment_node
			find(l, 0, v, (*[1]byte)(unsafe.Pointer(&t)))
			push(h, (*[1]byte)(unsafe.Pointer(&edge{v, t.index, p[i].val + t.val - int64(n-1-v)*d})))
		}
		if v+1 < n {
			var t segment_node
			find(r, v+1, n, (*[1]byte)(unsafe.Pointer(&t)))
			push(h, (*[1]byte)(unsafe.Pointer(&edge{v, t.index, p[i].val + t.val - int64(v)*d})))
		}
		update(l, v, (*[1]byte)(unsafe.Pointer(&ini)))
		update(r, v, (*[1]byte)(unsafe.Pointer(&ini)))
	}
	sum := int64(0)
	u := newUnionFind(n)
	for getSize(u, 0) < n {
		var e edge
		pop(h, (*[1]byte)(unsafe.Pointer(&e)))
		if same(u, e.a, e.b) {
			continue
		}
		unite(u, e.a, e.b)
		sum += e.c
	}
	fmt.Printf("%d\n", sum)
}

func main() {
	run()
}

>>>>>>> 98c87cb78a (data updated)
