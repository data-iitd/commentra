
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Define a structure for a binary heap
type heap struct {
	array     []interface{} // Pointer to the array that holds the heap elements
	heap_size int           // Current number of elements in the heap
	max_size  int           // Maximum capacity of the heap
	val_size  int           // Size of each value in the heap
	cmp       func(a, b interface{}) int // Comparison function for heap elements
}

// Function to create a new binary heap
func new_binary_heap(val_size int, cmp func(a, b interface{}) int) *heap {
	h := new(heap) // Allocate memory for the heap structure
	h.array = make([]interface{}, val_size*(1+1)) // Allocate memory for the heap array
	h.heap_size = 0 // Initialize heap size to 0
	h.max_size = 1 // Set initial maximum size
	h.val_size = val_size // Set the value size
	h.cmp = cmp // Set the comparison function
	return h // Return the created heap
}

// Function to get the current size of the heap
func (h *heap) get_heap_size() int {
	return h.heap_size // Return the current size of the heap
}

// Function to check if the heap is empty
func (h *heap) is_empty() bool {
	return h.heap_size == 0 // Return 1 if the heap is empty, otherwise 0
}

// Function to free the memory allocated for the heap
func (h *heap) free_heap() {
	h.array = nil // Free the array holding the heap elements
	h = nil       // Free the heap structure itself
}

// Function to initialize the heap
func (h *heap) init_heap() {
	h.heap_size = 0 // Set the heap size to 0
}

// Function to swap two elements in the heap
func (h *heap) heap_func_swap(a, b interface{}) {
	// Swap elements based on their size (optimized for 64-bit values)
	if h.val_size&7 == 0 {
		p := a.([]uint64)
		q := b.([]uint64)
		val_size := h.val_size / 8
		for val_size > 0 {
			tmp := p[0]
			p[0] = q[0]
			q[0] = tmp
			p = p[1:]
			q = q[1:]
			val_size--
		}
	} else {
		// Fallback for other sizes
		p := a.([]uint8)
		q := b.([]uint8)
		for h.val_size > 0 {
			tmp := p[0]
			p[0] = q[0]
			q[0] = tmp
			p = p[1:]
			q = q[1:]
			h.val_size--
		}
	}
}

// Function to copy values from source to destination
func (h *heap) heap_func_copy(dst, src interface{}) {
	// Copy elements based on their size (optimized for 64-bit values)
	if h.val_size&7 == 0 {
		p := src.([]uint64)
		q := dst.([]uint64)
		val_size := h.val_size / 8
		for val_size > 0 {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
			val_size--
		}
	} else {
		// Fallback for other sizes
		p := src.([]uint8)
		q := dst.([]uint8)
		for h.val_size > 0 {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
			h.val_size--
		}
	}
}

// Function to push a new value into the heap
func (h *heap) push(val interface{}) {
	// Check if the heap needs to be resized
	if h.heap_size == h.max_size {
		h.max_size = 2*h.max_size + 1 // Double the max size
		h.array = append(h.array, make([]interface{}, h.val_size)...) // Resize the array
	}
	h.heap_size++ // Increment the heap size
	array := h.array
	k := h.heap_size
	val_size := h.val_size
	cmp := h.cmp
	h.heap_func_copy(array[k*val_size:], val) // Copy the new value into the heap
	// Maintain the heap property by moving the new element up the heap
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*val_size:], array[k*val_size:]) <= 0 {
			return
		}
		h.heap_func_swap(array[parent*val_size:], array[k*val_size:])
		k = parent
	}
}

// Function to pop the top value from the heap
func (h *heap) pop(res interface{}) {
	array := h.array
	val_size := h.val_size
	if res!= nil {
		h.heap_func_copy(res, array[val_size:]) // Copy the top value to the result
	}
	h.heap_func_copy(array[val_size:], array[val_size*h.heap_size:]) // Move the last element to the top
	h.heap_size-- // Decrement the heap size
	cmp := h.cmp
	n := h.heap_size
	k := 1
	// Maintain the heap property by moving the top element down the heap
	for 2*k+1 <= n {
		c := cmp(array[val_size*2*k:], array[val_size*(2*k+1):])
		next := 2*k + (c <= 0)
		if cmp(array[val_size*k:], array[val_size*next:]) <= 0 {
			return
		}
		h.heap_func_swap(array[val_size*k:], array[val_size*next:])
		k = next
	}
	// Check if the last child needs to be swapped
	if 2*k <= n && cmp(array[val_size*k:], array[val_size*2*k:]) > 0 {
		h.heap_func_swap(array[val_size*k:], array[val_size*2*k:])
	}
}

// Function to get the top value of the heap without removing it
func (h *heap) top(res interface{}) {
	array := h.array
	val_size := h.val_size
	if res!= nil {
		h.heap_func_copy(res, array[val_size:]) // Copy the top value to the result
	}
}

// Define a structure for Union-Find (Disjoint Set Union)
type UnionFind struct {
	parent []int32 // Array to hold the parent of each element
	size   int32   // Size of the Union-Find structure
}

// Function to initialize the Union-Find structure
func (u *UnionFind) initUnionFind() {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1 // Set each element's parent to -1 (indicating it is its own root)
	}
}

// Function to create a new Union-Find structure
func newUnionFind(size int32) *UnionFind {
	u := new(UnionFind) // Allocate memory for the structure
	u.parent = make([]int32, size) // Allocate memory for the parent array
	u.size = size // Set the size
	u.initUnionFind() // Initialize the Union-Find structure
	return u // Return the created structure
}

// Function to free the memory allocated for the Union-Find structure
func (u *UnionFind) freeUnionFind() {
	u.parent = nil // Free the parent array
	u = nil         // Free the Union-Find structure
}

// Function to find the root of an element with path compression
func (u *UnionFind) root(x int32) int32 {
	index := make([]int32, 32) // Array to hold the path for compression
	len := int32(0)            // Length of the path
	for u.parent[x] >= 0 {
		index[len] = x // Store the current index
		x = u.parent[x] // Move to the parent
		len++
	}
	// Path compression: make all nodes point directly to the root
	for len > 0 {
		u.parent[index[len-1]] = x
		len--
	}
	return x
}

// Function to check if two elements are in the same set
func (u *UnionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y) // Return 1 if they have the same root, otherwise 0
}

// Function to get the size of the set containing element x
func (u *UnionFind) getSize(x int32) int32 {
	return -u.parent[u.root(x)] // Return the size of the set
}

// Function to unite two sets containing elements x and y
func (u *UnionFind) unite(x, y int32) {
	x = u.root(x) // Find the root of x
	y = u.root(y) // Find the root of y
	if x == y {
		return
	}
	// Union by size: attach the smaller tree under the larger tree
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y] // Update the size of the new root
	u.parent[y] = x            // Make x the parent of y
}

// Define a structure for a segment tree
type segment_tree struct {
	array     []interface{} // Pointer to the array that holds the segment tree nodes
	size      int32         // Size of the segment tree
	val_size  int           // Size of each value in the segment tree
	func_node func(c, a, b interface{}) // Function to combine two values
}

// Function to copy memory from source to destination
func (s *segment_tree) segment_tree_memcpy(dst, src interface{}, size int) {
	p