package main

import (
	"fmt"
	"math/big"
)

// Define types for 32-bit and 64-bit integers
type i32 int32
type i64 int64

// Structure to represent a directed edge in the graph
type graphEdge struct {
	vertex int32
	next   int32
}

// Structure to represent a directed graph
type graph struct {
	edge          []*graphEdge
	start         []int32
	pointer       int32
	vertexNum     int32
	edgeMaxSize   int32
}

// Function to create a new directed graph with a specified number of vertices
func newGraph(vertexNum int32) *graph {
	// Allocate memory for the graph structure
	g := &graph{
		edge:        make([]*graphEdge, 1),
		start:       make([]int32, vertexNum),
		pointer:     0,
		vertexNum:   vertexNum,
		edgeMaxSize: 1,
	}
	// Initialize the start array to -1 (indicating no edges)
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

// Function to add a directed edge from 'from' to 'to' in the graph
func (g *graph) addEdge(from, to int32) {
	// Check if the edges array needs to be resized
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]*graphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	// Add the edge to the graph
	g.edge[g.pointer] = &graphEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

// Define a constant for modulo operations
const mod = 1000000007

// Function to compute modular exponentiation
func modPow(r, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return t
}

// Structure to represent a node in dynamic programming
type node struct {
	one  int32
	zero int32
}

// Function to merge multiple dp nodes
func merge(a []*node, n int) node {
	one := int32(0)
	zero := int32(1)
	total := int32(1)
	for i := 0; i < n; i++ {
		one = (one*a[i].zero + zero*a[i].one) % mod
		zero = zero * a[i].zero % mod
		total = total * (a[i].zero + a[i].one) % mod
	}
	return node{one, (total + mod - one) % mod}
}

// Define a type for deque values
type dequeVal node

// Structure to represent a deque (double-ended queue)
type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

// Function to create a new deque
func newDeque() *deque {
	const len = 2
	d := &deque{
		array: make([]dequeVal, len),
		front: 0,
		last:  0,
		mask:  len - 1,
	}
	return d
}

// Function to free the memory allocated for a deque
func (d *deque) free() {
	d.array = nil
	d.front = 0
	d.last = 0
	d.mask = 0
}

// Function to get the size of the deque
func (d *deque) getSize() int {
	return (d.last + (^d.front + 1)) & d.mask
}

// Function to reallocate memory for the deque when it is full
func (d *deque) realloc() {
	newArray := make([]dequeVal, 2*(d.mask+1))
	k := 0
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

// Function to get the value at a specific index in the deque
func (d *deque) getAt(x int) dequeVal {
	return d.array[(d.front+x)&d.mask]
}

// Function to assign a value at a specific index in the deque
func (d *deque) assignAt(x int, v dequeVal) {
	d.array[(d.front+x)&d.mask] = v
}

// Function to push a value to the front of the deque
func (d *deque) pushFront(v dequeVal) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

// Comparison function for sorting deques based on their size
func cmpDequeSize(a, b interface{}) int {
	p := a.(*deque)
	q := b.(*deque)
	d := p.getSize() - q.getSize()
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	} else {
		return 1
	}
}

// Main function to run the algorithm
func run() {
	var n int32
	fmt.Scanf("%"