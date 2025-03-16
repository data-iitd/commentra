
package main

import (
	"fmt"
	"math"
	"sort"
)

// Define a structure for a binary heap
type binaryHeap struct {
	array []interface{} // Pointer to the array that holds the heap elements
	heapSize int // Current number of elements in the heap
	maxSize int // Maximum capacity of the heap
	valSize int // Size of each value in the heap
	cmp func(interface{}, interface{}) int // Comparison function for heap elements
}

// Function to create a new binary heap
func newBinaryHeap(valSize int, cmpF func(interface{}, interface{}) int) *binaryHeap {
	h := &binaryHeap{
		array: make([]interface{}, valSize * (1 + 1)),
		heapSize: 0,
		maxSize: 1,
		valSize: valSize,
		cmp: cmpF,
	}
	return h
}

// Function to get the current size of the heap
func (h *binaryHeap) getHeapSize() int {
	return h.heapSize
}

// Function to check if the heap is empty
func (h *binaryHeap) isEmpty() bool {
	return h.heapSize == 0
}

// Function to free the memory allocated for the heap
func (h *binaryHeap) freeHeap() {
	h.array = nil
}

// Function to initialize the heap
func (h *binaryHeap) initHeap() {
	h.heapSize = 0
}

// Function to swap two elements in the heap
func heapFuncSwap(a, b interface{}, valSize int) {
	// Swap elements based on their size (optimized for 64-bit values)
	if (valSize & 7) == 0 {
		p := a.([]uint64)
		q := b.([]uint64)
		valSize /= 8
		for valSize > 0 {
			tmp := p[0]
			p[0] = q[0]
			q[0] = tmp
			p = p[1:]
			q = q[1:]
			valSize--
		}
	} else {
		// Fallback for other sizes
		p := a.([]uint8)
		q := b.([]uint8)
		for valSize > 0 {
			tmp := p[0]
			p[0] = q[0]
			q[0] = tmp
			p = p[1:]
			q = q[1:]
			valSize--
		}
	}
}

// Function to copy values from source to destination
func heapFuncCopy(dst, src interface{}, valSize int) {
	// Copy elements based on their size (optimized for 64-bit values)
	if (valSize & 7) == 0 {
		p := src.([]uint64)
		q := dst.([]uint64)
		valSize /= 8
		for valSize > 0 {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
			valSize--
		}
	} else {
		// Fallback for other sizes
		p := src.([]uint8)
		q := dst.([]uint8)
		for valSize > 0 {
			q[0] = p[0]
			p = p[1:]
			q = q[1:]
			valSize--
		}
	}
}

// Function to push a new value into the heap
func (h *binaryHeap) push(val interface{}) {
	// Check if the heap needs to be resized
	if h.heapSize == h.maxSize {
		h.maxSize = 2 * h.maxSize + 1
		h.array = make([]interface{}, h.maxSize)
	}
	h.heapSize++ // Increment the heap size
	array := h.array // Cast array to uint8 pointer for byte-wise access
	k := h.heapSize // Current index for the new element
	valSize := h.valSize // Size of the value
	cmp := h.cmp // Get the comparison function
	heapFuncCopy(array[k], val, valSize) // Copy the new value into the heap
	// Maintain the heap property by moving the new element up the heap
	for k > 1 {
		parent := k / 2
		if cmp(array[parent], array[k]) <= 0 {
			return // If the heap property is satisfied, exit
		}
		heapFuncSwap(array[parent], array[k], valSize) // Swap with parent
		k = parent // Move up to the parent
	}
}

// Function to pop the top value from the heap
func (h *binaryHeap) pop(res interface{}) {
	array := h.array // Cast array to uint8 pointer for byte-wise access
	valSize := h.valSize // Size of the value
	if res != nil {
		heapFuncCopy(res, array[valSize], valSize) // Copy the top value to the result
	}
	heapFuncCopy(array[valSize], array[h.heapSize*valSize], valSize) // Move the last element to the top
	h.heapSize-- // Decrement the heap size
	cmp := h.cmp // Get the comparison function
	n := h.heapSize // Current size of the heap
	k := 1 // Start from the root
	// Maintain the heap property by moving the top element down the heap
	for 2*k+1 <= n {
		c := cmp(array[2*k], array[2*k+1])
		next := 2*k + (c <= 0)
		if cmp(array[k], array[next]) <= 0 {
			return // If heap property is satisfied, exit
		}
		heapFuncSwap(array[k], array[next], valSize) // Swap with the smaller child
		k = next // Move down to the next level
	}
	// Check if the last child needs to be swapped
	if 2*k <= n && cmp(array[k], array[2*k]) > 0 {
		heapFuncSwap(array[k], array[2*k], valSize)
	}
}

// Function to get the top value of the heap without removing it
func (h *binaryHeap) top(res interface{}) {
	array := h.array // Cast array to uint8 pointer for byte-wise access
	valSize := h.valSize // Size of the value
	if res != nil {
		heapFuncCopy(res, array[valSize], valSize) // Copy the top value to the result
	}
}

// Define a structure for Union-Find (Disjoint Set Union)
type UnionFind struct {
	parent []int32 // Array to hold the parent of each element
	size int32 // Size of the Union-Find structure
}

// Function to initialize the Union-Find structure
func (u *UnionFind) initUnionFind() {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1 // Set each element's parent to -1 (indicating it is its own root)
	}
}

// Function to create a new Union-Find structure
func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size: size,
	}
	u.initUnionFind()
	return u
}

// Function to free the memory allocated for the Union-Find structure
func (u *UnionFind) freeUnionFind() {
	u.parent = nil
}

// Function to find the root of an element with path compression
func (u *UnionFind) root(x int32) int32 {
	index := make([]int32, 32) // Array to hold the path for compression
	len := int32(0) // Length of the path
	for u.parent[x] >= 0 {
		index[len] = x
		x = u.parent[x]
		len++
	}
	// Path compression: make all nodes point directly to the root
	for len > 0 {
		u.parent[index[len-1]] = x
		len--
	}
	return x // Return the root
}
