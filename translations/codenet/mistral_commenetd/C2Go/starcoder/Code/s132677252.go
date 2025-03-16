
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

// Define custom data types

type graphEdge struct {
	vertex int
	next   int
}

type graph struct {
<<<<<<< HEAD
	edge     []graphEdge
	start    []int
	pointer  int
=======
	edge      []graphEdge
	start     []int
	pointer   int
>>>>>>> 98c87cb78a (data updated)
	vertexNum int
	edgeMaxSize int
}

// Define a custom graph data structure

func newGraph(vertexNum int) *graph {
	g := &graph{}
	// Allocate memory for graph structure

	g.edge = make([]graphEdge, 1)
	// Allocate memory for first edge

	g.start = make([]int, vertexNum)
	// Allocate memory for starting vertices array

	g.pointer = 0
	g.vertexNum = vertexNum
	g.edgeMaxSize = 1
	// Initialize graph properties

	for i := 0; i < vertexNum; i++ {
		g.start[i] = -1
	}
	// Initialize starting vertices to -1

	return g
}

// Function to create a new graph with given number of vertices

<<<<<<< HEAD
func addEdge(g *graph, from int, to int) {
=======
func addEdge(g *graph, from, to int) {
>>>>>>> 98c87cb78a (data updated)
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize)...)
	}
	// Check if memory allocation is needed

	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	// Add new edge to the graph

	g.start[from] = g.pointer
<<<<<<< HEAD
	// Update starting vertex of the new edge

=======
>>>>>>> 98c87cb78a (data updated)
	g.pointer++
}

// Function to add an edge between two vertices

const mod = 1000000007

// Define a constant for modular arithmetic

<<<<<<< HEAD
func modPow(r int, n int) int {
=======
func modPow(r, n int) int {
>>>>>>> 98c87cb78a (data updated)
	t := 1
	s := r
	for n > 0 {
		if n&1 > 0 {
<<<<<<< HEAD
			t = t * s % mod
		}
		s = s * s % mod
=======
			t = (t * s) % mod
		}
		s = (s * s) % mod
>>>>>>> 98c87cb78a (data updated)
		n >>= 1
	}
	return t
}

// Function to compute modular exponentiation

type dpNode struct {
	one  int
	zero int
}

// Define a custom data structure for dynamic programming

type dequeVal struct {
	one  int
	zero int
}

type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

// Define a custom deque data structure

func newDeque() *deque {
	const len = 2
	d := &deque{}
	d.array = make([]dequeVal, len)
	// Allocate memory for deque structure and its array

	d.front = d.last = 0
	d.mask = len - 1
	// Initialize front and last indices and mask

	return d
}

// Function to create a new deque

func freeDeque(d *deque) {
	d.array = nil
	d = nil
}

// Function to free deque resources

func getSize(d *deque) int {
	return (d.last + (~d.front + 1)) & d.mask
}

// Function to get the size of a deque

func dequeRealloc(d *deque) {
	array := make([]dequeVal, 2*(d.mask+1))
	k := 0
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = array
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

// Function to reallocate deque memory

func getAt(d *deque, x int) dequeVal {
	return d.array[(d.front+x)&d.mask]
}

// Function to get the value at a given index in a deque

func assignAt(d *deque, x int, v dequeVal) {
	d.array[(d.front+x)&d.mask] = v
}

// Function to assign a value to a given index in a deque

func pushFront(d *deque, v dequeVal) {
	if ((d.last+1)&d.mask) == d.front {
		dequeRealloc(d)
	}
	// Check if memory allocation is needed

	d.front = (d.front + d.mask) & d.mask
	// Update front index

	d.array[d.front] = v
	// Add new value to the front of the deque
}

// Function to push a value to the front of a deque

<<<<<<< HEAD
func cmpDequeSize(a interface{}, b interface{}) int {
=======
func cmpDequeSize(a, b interface{}) int {
>>>>>>> 98c87cb78a (data updated)
	p := a.(*deque)
	q := b.(*deque)
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
	var n int
<<<<<<< HEAD
	fmt.Fscanf(os.Stdin, "%d\n", &n)
=======
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)
>>>>>>> 98c87cb78a (data updated)
	// Read the number of vertices from the standard input

	p := make([]int, n+1)
	// Allocate memory for an array to store the parent pointers

	depth := make([]int, n+1)
	// Allocate memory for an array to store the depth of each vertex

	cnt := make([]int, n+1)
	// Allocate memory for an array to store the number of nodes at each depth

	cnt[0] = 1
	// Initialize the number of nodes at depth 0

	g := newGraph(n + 1)
	// Create a new graph with n+1 vertices

	for i := 1; i <= n; i++ {
<<<<<<< HEAD
		fmt.Fscanf(os.Stdin, "%d\n", p[i])
=======
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", p[i])
>>>>>>> 98c87cb78a (data updated)
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
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			// Get the children deques
		}
		if len > 1 {
			sort.Slice(child, func(i, j int) bool {
				return getSize(child[i]) < getSize(child[j])
			})
			// Sort the children deques based on their sizes

			for d := 0; d < getSize(child[1]); d++ {
				j := 0
				for ; j < len && d < getSize(child[j]); j++ {
					lst[j] = getAt(child[j], d)
					// Get the last dp values from the children deques
				}
				assignAt(child[0], d, merge(lst[:j]))
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

	ans := 0
	// Initialize the answer to 0

	for i := 0; i < getSize(dp[0]); i++ {
<<<<<<< HEAD
		ans += (int64(modPow(2, n+1-cnt[i])) * int64(getAt(dp[0], i).one)) % mod
		// Calculate the answer using the dp values
	}
	// Print the answer
=======
		ans += (modPow(2, n+1-cnt[i]) * getAt(dp[0], i).one) % mod
	}
	// Calculate the answer using the dp values
>>>>>>> 98c87cb78a (data updated)

	fmt.Printf("%d\n", ans%mod)
	// Print the answer modulo 1000000007
}

// Main function to run the program

func main() {
	run()
}

// Entry point of the program

