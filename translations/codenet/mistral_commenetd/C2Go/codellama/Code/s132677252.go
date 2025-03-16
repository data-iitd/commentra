
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Include necessary header files

type directedEdge struct {
	vertex int32
	next   int32
}

// Define custom data types

type directedGraph struct {
	edge      []directedEdge
	start     []int32
	pointer   int32
	vertexNum int32
	edgeMax   int32
}

// Define a custom graph data structure

func newGraph(vertexNum int32) *directedGraph {
	g := &directedGraph{
		edge:      make([]directedEdge, 1),
		start:     make([]int32, vertexNum),
		pointer:   0,
		vertexNum: vertexNum,
		edgeMax:   1,
	}
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	// Initialize starting vertices to -1
	return g
}

// Function to create a new graph with given number of vertices

func addEdge(g *directedGraph, from, to int32) {
	if g.pointer == g.edgeMax {
		g.edgeMax *= 2
		g.edge = make([]directedEdge, g.edgeMax)
	}
	// Check if memory allocation is needed

	g.edge[g.pointer] = directedEdge{to, g.start[from]}
	// Add new edge to the graph

	g.start[from] = g.pointer
	g.pointer++
	// Update starting vertex of the new edge
}

// Function to add an edge between two vertices

const mod int32 = 1000000007

// Define a constant for modular arithmetic

func modPow(r, n int32) int32 {
	t := int64(1)
	s := int64(r)
	for n > 0 {
		if n&1 == 1 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return int32(t)
}

// Function to compute modular exponentiation

type dpNode struct {
	one   int32
	zero  int32
}

// Define a custom data structure for dynamic programming

type dequeVal dpNode

type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

// Define a custom deque data structure

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

// Function to create a new deque

func freeDeque(d *deque) {
	free(d.array)
	free(d)
}

// Function to free deque resources

func getSize(d *deque) int {
	return (d.last + (^d.front + 1)) & d.mask
}

// Function to get the size of a deque

func dequeRealloc(d *deque) {
	array := make([]dequeVal, 2*d.mask+1)
	k := 0
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
	}
	free(d.array)
	d.array = array
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

// Function to reallocate deque memory

func getAt(d *deque, x int) dequeVal {
	return d.array[(d.front + x) & d.mask]
}

// Function to get the value at a given index in a deque

func assignAt(d *deque, x int, v dequeVal) {
	d.array[(d.front + x) & d.mask] = v
}

// Function to assign a value to a given index in a deque

func pushFront(d *deque, v dequeVal) {
	if ((d.last + 1) & d.mask) == d.front {
		dequeRealloc(d)
	}
	// Check if memory allocation is needed

	d.front = (d.front + d.mask) & d.mask
	// Update front index

	d.array[d.front] = v
	// Add new value to the front of the deque
}

// Function to push a value to the front of a deque

func cmpDequeSize(a, b unsafe.Pointer) int {
	p := *(*deque)(a)
	q := *(*deque)(b)
	d := getSize(p) - getSize(q)
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

// Function to compare two deques based on their sizes

func run() {
	var n int32
	fmt.Scan(&n)
	// Read the number of vertices from the standard input

	p := make([]int32, n+1)
	// Allocate memory for an array to store the parent pointers

	depth := make([]int32, n+1)
	// Allocate memory for an array to store the depth of each vertex

	cnt := make([]int32, n+1)
	// Allocate memory for an array to store the number of nodes at each depth

	cnt[0] = 1
	// Initialize the number of nodes at depth 0

	g := newGraph(n + 1)
	// Create a new graph with n+1 vertices

	for i := int32(1); i <= n; i++ {
		fmt.Scan(&p[i])
		// Read the parent pointer for each vertex

		addEdge(g, p[i], i)
		// Add an edge from the parent to the current vertex

		depth[i] = depth[p[i]] + 1
		// Update the depth of the current vertex

		cnt[depth[i]]++
		// Increment the number of nodes at the current depth
	}
	// Process all vertices and edges

	dp := make([]*deque, n+1)
	// Allocate memory for an array to store deques for each vertex

	child := make([]*deque, n+1)
	// Allocate memory for an array to store the children deques for each vertex

	lst := make([]dpNode, n+1)
	// Allocate memory for an array to store the last dp values for each vertex

	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			// If the vertex has no children, create a new deque for it

			pushFront(dp[v], dpNode{1, 1})
			// Add the initial dp values (one and zero)

			continue
		}
		// Otherwise, process the children

		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			// Get the children deques
		}
		if len > 1 {
			qsort(unsafe.Pointer(&child[0]), len, unsafe.Sizeof(child[0]), cmpDequeSize)
			// Sort the children deques based on their sizes

			for d := 0; d < getSize(child[1]); d++ {
				j := 0
				for j < len && d < getSize(child[j]); j++ {
					lst[j] = getAt(child[j], d)
					// Get the last dp values from the children deques
				}
				assignAt(child[0], d, merge(lst, j))
				// Merge the last dp values and update the root deque
			}
			for j := 1; j < len; j++ {
				freeDeque(child[j])
				// Free the memory of the children deques
			}
		}
		dp[v] = child[0]
		// Update the root deque with the merged dp values

		pushFront(dp[v], dpNode{1, 1})
		// Add the initial dp values (one and zero)
	}
	// Process all vertices

	ans := int64(0)
	// Initialize the answer to 0

	for i := 0; i < getSize(dp[0]); i++ {
		ans += int64(modPow(2, n+1-cnt[i]))*int64(getAt(dp[0], i).one) % int64(mod)
		// Calculate the answer using the dp values
	}
	// Print the answer

	fmt.Println(ans % int64(mod))
	// Print the answer modulo 1000000007

	free(p)
	free(depth)
	free(cnt)
	free(g)
	free(dp)
	free(child)
	free(lst)
	// Free all allocated memory
}

// Main function to run the program

func main() {
	run()
}

// Entry point of the program

