
package main

import (
	"fmt"
	"math"
	"sort"
)

// Define types for 32-bit and 64-bit integers
type i32 int32
type i64 int64

// Structure to represent a directed edge in the graph
type graphEdge struct {
	vertex i32 // The destination vertex of the edge
	next   i32 // The index of the next edge in the adjacency list
}

// Structure to represent a directed graph
type graph struct {
	edge     []graphEdge // Array of edges
	start    []i32       // Array to store the starting index of edges for each vertex
	pointer  i32         // Current number of edges in the graph
	vertexNum i32        // Number of vertices in the graph
	edgeMaxSize i32      // Maximum size of the edges array
}

// Function to create a new directed graph with a specified number of vertices
func newGraph(vertexNum i32) *graph {
	// Allocate memory for the graph structure
	g := &graph{}
	// Allocate memory for edges and initialize the start array
	g.edge = make([]graphEdge, 1)
	g.start = make([]i32, vertexNum)
	g.pointer = 0 // Initialize edge count to 0
	g.vertexNum = vertexNum // Set the number of vertices
	g.edgeMaxSize = 1 // Initialize maximum edge size
	// Initialize the start array to -1 (indicating no edges)
	for i := i32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g // Return the created graph
}

// Function to add a directed edge from 'from' to 'to' in the graph
func addEdge(g *graph, from, to i32) {
	// Check if the edges array needs to be resized
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2 // Double the maximum size
		g.edge = make([]graphEdge, g.edgeMaxSize)
	}
	// Add the edge to the graph
	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	g.start[from] = g.pointer++ // Update the start index for 'from'
}

// Define a constant for modulo operations
const mod i32 = 1000000007

// Function to compute modular exponentiation
func modPow(r, n i32) i32 {
	t := i32(1) // Result variable
	s := r // Base
	// Loop until the exponent is zero
	for n > 0 {
		if n&1 == 1 { // If n is odd, multiply the result by the base
			t = (i64(t) * s) % mod
		}
		s = (i64(s) * s) % mod // Square the base
		n >>= 1 // Divide n by 2
	}
	return t // Return the result
}

// Structure to represent a node in dynamic programming
type node struct {
	one  i32  // Count of paths ending with 1
	zero i32  // Count of paths ending with 0
}

// Function to merge multiple dp nodes
func merge(a []node, n i32) node {
	one := i64(0) // Initialize count of paths ending with 1
	zero := i64(1) // Initialize count of paths ending with 0
	total := i64(1) // Initialize total paths
	// Iterate through the nodes to merge their counts
	for i := i32(0); i < n; i++ {
		one = (one * a[i].zero + zero * a[i].one) % mod // Update count of paths ending with 1
		zero = zero * a[i].zero % mod // Update count of paths ending with 0
		total = total * (a[i].zero + a[i].one) % mod // Update total paths
	}
	return node{one, (total + mod - one) % mod} // Return merged node
}

// Define a type for deque values
type dequeVal node

// Structure to represent a deque (double-ended queue)
type deque struct {
	array []dequeVal // Array to store deque values
	front i32        // Index of the front element
	last  i32        // Index of the last element
	mask  i32        // Mask for circular indexing
}

// Function to create a new deque
func newDeque() *deque {
	const len i32 = 2 // Initial length of the deque
	d := &deque{} // Allocate memory for the deque
	d.array = make([]dequeVal, len) // Allocate memory for the array
	d.front = d.last = 0 // Initialize front and last indices
	d.mask = len - 1 // Set the mask for circular indexing
	return d // Return the created deque
}

// Function to free the memory allocated for a deque
func freeDeque(d *deque) {
	d.array = nil // Free the array
	d = nil // Free the deque structure
}

// Function to get the size of the deque
func getSize(d *deque) i32 {
	return (d.last + (~d.front + 1)) & d.mask // Calculate the size using circular indexing
}

// Function to reallocate memory for the deque when it is full
func dequeRealloc(d *deque) {
	// Allocate a new array with double the size
	array := make([]dequeVal, 2*d.mask+1)
	k := i32(0) // Index for the new array
	// Copy elements from the old array to the new array
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = nil // Free the old array
	d.array = array // Update the deque's array to the new array
	d.front = 0 // Reset front index
	d.last = k // Update last index
	d.mask = 2*d.mask + 1 // Update the mask for the new size
}

// Function to get the value at a specific index in the deque
func getAt(d *deque, x i32) dequeVal {
	return d.array[(d.front + x) & d.mask] // Return the value using circular indexing
}

// Function to assign a value at a specific index in the deque
func assignAt(d *deque, x i32, v dequeVal) {
	d.array[(d.front + x) & d.mask] = v // Assign the value using circular indexing
}

// Function to push a value to the front of the deque
func pushFront(d *deque, v dequeVal) {
	// Check if the deque is full
	if(((d.last + 1) & d.mask) == d.front) {
		dequeRealloc(d) // Reallocate if full
	}
	d.front = (d.front + d.mask) & d.mask // Move front index backwards
	d.array[d.front] = v // Assign the value at the front
}

// Comparison function for sorting deques based on their size
func cmpDequeSize(a, b *deque) int {
	p := *a // Get the first deque
	q := *b // Get the second deque
	d := getSize(p) - getSize(q) // Calculate the size difference
	return d // Return comparison result
}

// Main function to run the algorithm
func run() {
	var n i32 // Number of vertices
	fmt.Scan(&n) // Read the number of vertices
	// Allocate memory for parent, depth, and count arrays
	p := make([]i32, n+1)
	depth := make([]i32, n+1)
	cnt := make([]i32, n+1)
	cnt[0] = 1 // Initialize count for depth 0
	g := newGraph(n+1) // Create a new graph
	// Read edges and build the graph
	for i := i32(1); i <= n; i++ {
		fmt.Scan(&p[i]) // Read parent for vertex i
		addEdge(g, p[i], i) // Add edge from parent to current vertex
		depth[i] = depth[p[i]] + 1 // Update depth of current vertex
		cnt[depth[i]]++ // Increment count for the current depth
	}
	// Allocate memory for dynamic programming arrays
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)
	// Process vertices in reverse order
	for i := n; i >= 0; i-- {
		v := i // Current vertex
		// If the vertex has no outgoing edges
		if g.start[v] == -1 {
			dp[v] = newDeque() // Create a new deque for this vertex
			pushFront(dp[v], node{1, 1}) // Initialize with base case
			continue // Move to the next vertex
		}
		len := i32(0) // Length of child deques
		// Collect child deques for the current vertex
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex // Get child vertex
			child[len] = dp[u] // Store child deque
			len++
		}
		// If there are multiple child deques, merge them
		if len > 1 {
			sort.Slice(child, func(i, j int) bool {
				return cmpDequeSize(child[i], child[j]) < 0
			}) // Sort child deques by size
			// Merge the child deques
			for d := i32(0); d < getSize(child[1]); d++ {
				j := i32(0)
				for j < len && d < getSize(child[j]); j++ {
					lst[j] = getAt(child[j], d) // Get nodes from child deques
				}
				assignAt(child[0], d, merge(lst, j)) // Merge and assign to the first child
			}
			// Free the other child deques
			for j := i32(1); j < len; j++ {
				freeDeque(child[j])
			}
		}
		dp[v] = child[0] // Assign the merged deque to the current vertex
		pushFront(dp[v], node{1, 1}) // Add the base case to the front
	}
	ans := i64(0) // Variable to store the final answer
	// Calculate the final answer based on the dp values
	for i := i32(0); i < getSize(dp[0]); i++ {
		ans += (i64(modPow(2, n+1-cnt[i])) * getAt(dp[0], i).one) % mod // Update answer
	}
	fmt.Println(ans % mod) // Print the final answer
}

// Main function to execute the program
func main() {
	run() // Call the run function
}

