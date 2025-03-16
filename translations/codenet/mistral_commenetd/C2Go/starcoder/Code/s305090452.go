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
)

// Include necessary header files

// Define a structure for binary heap

type binaryHeap struct {
	array     []interface{}
	heap_size int
	max_size  int
	val_size  int
	cmp       func(interface{}, interface{}) int
}

// Function to create a new binary heap

func new_binary_heap(val_size int, cmp func(interface{}, interface{}) int) *binaryHeap {
	h := &binaryHeap{}
	// Allocate memory for heap structure

	h.array = make([]interface{}, val_size*(1+1))
	// Allocate memory for heap array

	h.heap_size = 0
	h.max_size = 1
	h.val_size = val_size
	h.cmp = cmp
	// Initialize heap properties

	return h
}

// Function to get the current size of the heap

func get_heap_size(h *binaryHeap) int {
	// Function to get the current size of the heap

	return h.heap_size
}

func is_empty(h *binaryHeap) bool {
	// Function to check if the heap is empty

	return h.heap_size == 0
}

func free_heap(h *binaryHeap) {
	// Function to free the memory allocated for the heap

	h.array = nil
	h.heap_size = 0
	h.max_size = 0
	h.val_size = 0
	h.cmp = nil
}

func init_heap(h *binaryHeap) {
	h.heap_size = 0
	// Function to initialize an empty heap
}

// Implementation of various heap functions

func heap_func_swap(a, b interface{}, val_size int) {
	// Helper function to swap two elements in the heap

	if (val_size&7) == 0 {
		p := a.(*uint64)
		q := b.(*uint64)
		val_size /= 8
		for ; val_size > 0; val_size-- {
			tmp := *p
			*p++ = *q
			*q++ = tmp
		}
	} else {
		p := a.(*uint8)
		q := b.(*uint8)
		for ; val_size > 0; val_size-- {
			tmp := *p
			*p++ = *q
			*q++ = tmp
		}
	}
}

func heap_func_copy(dst, src interface{}, val_size int) {
	// Helper function to copy elements from one location to another

	if (val_size&7) == 0 {
		p := src.(*uint64)
		q := dst.(*uint64)
		val_size /= 8
		for ; val_size > 0; val_size-- {
			*q++ = *p++
		}
	} else {
		p := src.(*uint8)
		q := dst.(*uint8)
		for ; val_size > 0; val_size-- {
			*q++ = *p++
		}
	}
}

// Helper functions for heap manipulation

func push(h *binaryHeap, val interface{}) {
	// Function to add a new element to the heap

	if h.heap_size == h.max_size {
		h.max_size = 2*h.max_size + 1
		h.array = append(h.array, make([]interface{}, h.val_size*(h.max_size+1))...)
	}
	h.heap_size++
	array := h.array
	k := h.heap_size
	val_size := h.val_size
	cmp := h.cmp
	heap_func_copy(array[k*val_size:], val, val_size)
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*val_size:], array[k*val_size:]) <= 0 {
			return
		}
		heap_func_swap(array[parent*val_size:], array[k*val_size:], val_size)
		k = parent
	}
}

func pop(h *binaryHeap, res interface{}) {
	// Function to remove and return the root element from the heap

	array := h.array
	val_size := h.val_size
	if res!= nil {
		heap_func_copy(res, array[val_size:], val_size)
	}
<<<<<<< HEAD
	heap_func_copy(array[val_size:], array[val_size*h.heap_size:], val_size)
	h.heap_size--
	cmp := h.cmp
	n := h.heap_size
	k := 1
	for 2*k+1 <= n {
		c := cmp(array[val_size*2*k:], array[val_size*(2*k+1):])
		next := 2*k + (c <= 0)
		if cmp(array[val_size*k:], array[val_size*next:]) <= 0 {
			return
		}
		heap_func_swap(array[val_size*k:], array[val_size*next:], val_size)
		k = next
	}
	if 2*k <= n && cmp(array[val_size*k:], array[val_size*2*k:]) > 0 {
		heap_func_swap(array[val_size*k:], array[val_size*2*k:], val_size)
	}
}

func top(h *binaryHeap, res interface{}) {
	// Function to get the root element of the heap without removing it

	array := h.array
	val_size := h.val_size
	if res!= nil {
		heap_func_copy(res, array[val_size:], val_size)
	}
}

// Implementation of various heap functions

// Define a structure for Union-Find data structure

type UnionFind struct {
	parent []int32
	size   int32
}

// Function to create a new Union-Find data structure

func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{}
	u.parent = make([]int32, size)
	u.size = size
	initUnionFind(u)
	return u
}

// Function to initialize the parent array with -1 for all elements

func initUnionFind(u *UnionFind) {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1
	}
}

// Function to free the memory allocated for the Union-Find data structure

func freeUnionFind(u *UnionFind) {
	u.parent = nil
	u.size = 0
}

// Function to get the root of the element x

func root(u *UnionFind, x int32) int32 {
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

// Function to check if the two elements are in the same set

func same(u *UnionFind, x, y int32) bool {
	return root(u, x) == root(u, y)
}

// Function to get the size of the set containing the element x

func getSize(u *UnionFind, x int32) int32 {
	return -u.parent[root(u, x)]
}

// Function to unite the two sets containing the elements x and y

func unite(u *UnionFind, x, y int32) {
	x = root(u, x)
	y = root(u, y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

// Implementation of various Union-Find functions

// Define a structure for segment tree

type segment_tree struct {
	array     []interface{}
	size      int32
	val_size  int
	func      func(interface{}, interface{}, interface{})
	func_size int
}

// Function to create a new segment tree

func new_segment_tree(ini interface{}, n int32, val_size int, func func(interface{}, interface{}, interface{})) *segment_tree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &segment_tree{}
	s.array = make([]interface{}, 2*k*val_size)
	s.size = k
	s.val_size = val_size
	s.func = func
	s.func_size = 0
	for i := k; i < 2*k; i++ {
		s.array[i*val_size] = ini
	}
	a := s.array
	for i := k - 1; i > 0; i-- {
		s.func(a[i*val_size:], a[2*i*val_size:], a[(2*i+1)*val_size:])
	}
	return s
}

// Function to update a node in the segment tree

func update(s *segment_tree, k int32, val interface{}) {
	k += s.size
	p := s.array
	size := s.val_size
	segment_tree_memcpy(p[k*size:], val, size)
	for k > 1 {
		s.func(p[k*size:], p[2*k*size:], p[(2*k+1)*size:])
		k >>= 1
	}
}

func update_tmp(s *segment_tree, k int32, val interface{}) {
	k += s.size
	p := s.array
	size := s.val_size
	segment_tree_memcpy(p[k*size:], val, size)
}

// Function to update all the nodes in the segment tree

func update_all(s *segment_tree) {
	a := s.array
	size := s.val_size
	for i := s.size - 1; i > 0; i-- {
		s.func(a[i*size:], a[2*i*size:], a[(2*i+1)*size:])
	}
}

// Implementation of various segment tree functions

// Function to find the result of a query in the segment tree

func find(s *segment_tree, l int32, r int32, res interface{}) {
	lindex := make([]int32, 32)
	rindex := make([]int32, 32)
	llen := int32(0)
	rlen := int32(0)
	for l += s.size, r += s.size; l < r; l >>= 1, r >>= 1 {
		if l&1 > 0 {
			lindex[llen] = l
			llen++
			l++
		}
		if r&1 > 0 {
			rindex[rlen] = r - 1
			rlen++
			r--
		}
	}
	if llen == 0 {
		lindex[llen] = rindex[rlen]
		llen++
	}
	segment_tree_memcpy(res, s.array[lindex[0]*s.val_size:], s.val_size)
	for i := int32(1); i < llen; i++ {
		s.func(res, res, s.array[lindex[i]*s.val_size:])
	}
	for i := rlen - 1; i >= 0; i-- {
		s.func(res, res, s.array[rindex[i]*s.val_size:])
	}
}

// Define a structure for index_val

type index_val struct {
	index int32
	val   int32
}

// Function to compare two index_val structures

func cmp_index_val(a, b interface{}) int {
	d := ((index_val)(a)).val - ((index_val)(b)).val
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

// Define a structure for segment_node

type segment_node struct {
	index int32
	val   int64
}

// Function to compare two segment_node structures

func cmp_segment_node(a, b interface{}) int {
	d := ((segment_node)(a)).val - ((segment_node)(b)).val
	if d == 0 {
		return 0
	}
	if d < 0 {
		return -1
	}
	return 1
}

// Define a structure for edge

type edge struct {
	a, b int32
	c    int64
}

// Function to compare two edge structures

func cmp_edge(a, b interface{}) int {
	d := ((edge)(a)).c - ((edge)(b)).c
	if d == 0 {
		return 0
	}
	if d < 0 {
		return -1
	}
	return 1
}

// Implementation of various helper functions

func run() {
	n, d := int32(0), int32(0)
	fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString('\n'), "%d %d", &n, &d)
	a := make([]int32, n)
	p := make([]index_val, n)
	for i := int32(0); i < n; i++ {
		fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString('\n'), "%d", a[i])
		p[i] = index_val{i, a[i]}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].val < p[j].val
	})
	ini := segment_node{n, int64(n+2)*1000000000 + 1}
	l := new_segment_tree(ini, n, int(unsafe.Sizeof(ini)), func_segment_node)
	r := new_segment_tree(ini, n, int(unsafe.Sizeof(ini)), func_segment_node)
	for i := int32(0); i < n; i++ {
		update_tmp(l, i, segment_node{i, a[i] + int64(n-1-i)*d})
		update_tmp(r, i, segment_node{i, a[i] + int64(i)*d})
	}
	update_all(l)
	update_all(r)
	h := new_binary_heap(int(unsafe.Sizeof(edge{})), cmp_edge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			t := segment_node{}
			find(l, 0, v, &t)
			push(h, edge{v, t.index, p[i].val + t.val})
		}
	}
	for i := int32(0); i < n-1; i++ {
		e := edge{}
		pop(h, &e)
		unite(newUnionFind(n), e.a, e.b)
	}
	fmt.Println(getSize(newUnionFind(n), 0))
}

func main() {
	run()
}

// Translate the above Go code to C and end with comment "
=======
>>>>>>> 98c87cb78a (data updated)
