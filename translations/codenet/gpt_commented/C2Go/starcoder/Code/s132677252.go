
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define types for 32-bit and 64-bit integers
type i32 int32
type i64 int64

// Structure to represent a directed edge in the graph
type graph_edge struct {
	vertex int32 // The destination vertex of the edge
	next   int32 // The index of the next edge in the adjacency list
}

// Structure to represent a directed graph
type graph struct {
	edge        []graph_edge // Array of edges
	start       []int32      // Array to store the starting index of edges for each vertex
	pointer     int32        // Current number of edges in the graph
	vertex_num  int32        // Number of vertices in the graph
	edge_max_size int32        // Maximum size of the edges array
}

// Function to create a new directed graph with a specified number of vertices
func new_graph(vertex_num int32) *graph {
	// Allocate memory for the graph structure
	g := new(graph)
	// Allocate memory for edges and initialize the start array
	g.edge = make([]graph_edge, 1)
	g.start = make([]int32, vertex_num)
	g.pointer = 0 // Initialize edge count to 0
	g.vertex_num = vertex_num // Set the number of vertices
	g.edge_max_size = 1 // Initialize maximum edge size
	// Initialize the start array to -1 (indicating no edges)
	for i := int32(0); i < vertex_num; i++ {
		g.start[i] = -1
	}
	return g // Return the created graph
}

// Function to add a directed edge from 'from' to 'to' in the graph
func add_edge(g *graph, from int32, to int32) {
	// Check if the edges array needs to be resized
	if g.pointer == g.edge_max_size {
		g.edge_max_size *= 2 // Double the maximum size
		g.edge = append(g.edge, make([]graph_edge, g.edge_max_size)...)
	}
	// Add the edge to the graph
	g.edge[g.pointer] = graph_edge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++ // Update the edge count
}

// Define a constant for modulo operations
const mod = 1000000007

// Function to compute modular exponentiation
func mod_pow(r i32, n i32) i32 {
	t := i32(1) // Result variable
	s := r      // Base
	// Loop until the exponent is zero
	for n > 0 {
		if n&1 > 0 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return t // Return the result
}

// Structure to represent a node in dynamic programming
type node struct {
	one  i32 // Count of paths ending with 1
	zero i32 // Count of paths ending with 0
}

// Function to merge multiple dp nodes
func merge(a []node, n i32) node {
	one := i64(0) // Initialize count of paths ending with 1
	zero := i64(1) // Initialize count of paths ending with 0
	total := i64(1) // Initialize total paths
	// Iterate through the nodes to merge their counts
	for i := i32(0); i < n; i++ {
		one = (one * i64(a[i].zero) + zero * i64(a[i].one)) % mod
		zero = zero * i64(a[i].zero) % mod
		total = total * (i64(a[i].zero) + i64(a[i].one)) % mod
	}
	return node{one: i32(one), zero: i32(total + mod - one)}
}

// Define a type for deque values
type deque_val node

// Structure to represent a deque (double-ended queue)
type deque struct {
	array []deque_val // Array to store deque values
	front int32       // Index of the front element
	last  int32       // Index of the last element
	mask  int32       // Mask for circular indexing
}

// Function to create a new deque
func new_deque() *deque {
	const len = 2 // Initial length of the deque
	d := new(deque)
	d.array = make([]deque_val, len) // Allocate memory for the array
	d.front = d.last = 0             // Initialize front and last indices
	d.mask = len - 1                 // Set the mask for circular indexing
	return d
}

// Function to free the memory allocated for a deque
func free_deque(d *deque) {
	d.array = nil
	d = nil
}

// Function to get the size of the deque
func get_size(d *deque) int32 {
	return (d.last + (~d.front + 1)) & d.mask // Calculate the size using circular indexing
}

// Function to reallocate memory for the deque when it is full
func deque_realloc(d *deque) {
	// Allocate a new array with double the size
	array := make([]deque_val, 2*(d.mask+1))
	k := int32(0) // Index for the new array
	// Copy elements from the old array to the new array
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = array // Update the deque's array to the new array
	d.front = 0     // Reset front index
	d.last = k      // Update last index
	d.mask = 2*d.mask + 1
}

// Function to get the value at a specific index in the deque
func get_at(d *deque, x int32) deque_val {
	return d.array[(d.front+x)&d.mask] // Return the value using circular indexing
}

// Function to assign a value at a specific index in the deque
func assign_at(d *deque, x int32, v deque_val) {
	d.array[(d.front+x)&d.mask] = v // Assign the value using circular indexing
}

// Function to push a value to the front of the deque
func push_front(d *deque, v deque_val) {
	// Check if the deque is full
	if ((d.last + 1) & d.mask) == d.front {
		deque_realloc(d) // Reallocate if full
	}
	d.front = (d.front + d.mask) & d.mask // Move front index backwards
	d.array[d.front] = v                 // Assign the value at the front
}

// Comparison function for sorting deques based on their size
func cmp_deque_size(a, b *deque) int {
	p := a
	q := b
	d := get_size(p) - get_size(q) // Calculate the size difference
	return int(d) == 0? 0 : int(d) > 0? -1 : 1
}

// Main function to run the algorithm
func run() {
	var n i32 // Number of vertices
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n) // Read the number of vertices
	// Allocate memory for parent, depth, and count arrays
	p := make([]i32, n+1)
	depth := make([]i32, n+1)
	cnt := make([]i32, n+1)
	cnt[0] = 1 // Initialize count for depth 0
	g := new_graph(n + 1) // Create a new graph
	// Read edges and build the graph
	for i := i32(1); i <= n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &p[i]) // Read parent for vertex i
		add_edge(g, p[i], i) // Add edge from parent to current vertex
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
			dp[v] = new_deque() // Create a new deque for this vertex
			push_front(dp[v], node{one: 1, zero: 1}) // Initialize with base case
			continue // Move to the next vertex
		}
		var len int32 // Length of child deques
		// Collect child deques for the current vertex
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex // Get child vertex
			child[len] = dp[u]   // Store child deque
			len++
		}
		// If there are multiple child deques, merge them
		if len > 1 {
			sort.Slice(child, func(i, j int) bool {
				return get_size(child[i]) > get_size(child[j])
			}) // Sort child deques by size
			// Merge the child deques
			for d := int32(0); d < get_size(child[1]); d++ {
				j := int32(0)
				for ; j < len && d < get_size(child[j]); j++ {
					lst[j] = get_at(child[j], d) // Get nodes from child deques
				}
				assign_at(child[0], d, merge(lst[:j], j)) // Merge and assign to the first child
			}
			// Free the other child deques
			for j := int32(1); j < len; j++ {
				free_deque(child[j])
			}
		}
		dp[v] = child[0] // Assign the merged deque to the current vertex
		push_front(dp[v], node{one: 1, zero: 1}) // Add the base case to the front
	}
	var ans i64 // Variable to store the final answer
	// Calculate the final answer based on the dp values
	for i := int32(0); i < get_size(dp[0]); i++ {
		ans += i64(mod_pow(2, n+1-cnt[i])) * get_at(dp[0], i).one % mod
	}
	fmt.Printf("%d\n", ans%mod) // Print the final answer
}

// Main function to execute the program
func main() {
	run() // Call the run function
}

