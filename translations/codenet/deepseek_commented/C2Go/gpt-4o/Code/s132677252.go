package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1000000007

type graphEdge struct {
	vertex int32 // The destination vertex of the edge
	next   int32 // The index of the next edge in the adjacency list
}

type directedGraph struct {
	edge         []graphEdge // Array of edges
	start        []int32     // Array of start pointers for each vertex
	pointer      int32       // Current number of edges
	vertexNum    int32       // Number of vertices
	edgeMaxSize  int32       // Maximum size of the edge array
}

func newGraph(vertexNum int32) *directedGraph {
	g := &directedGraph{
		edge:        make([]graphEdge, 1),
		start:       make([]int32, vertexNum),
		pointer:     0,
		vertexNum:   vertexNum,
		edgeMaxSize: 1,
	}
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1 // Initialize all start pointers to -1 (no edges initially)
	}
	return g
}

func (g *directedGraph) addEdge(from, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	g.edge[g.pointer] = graphEdge{vertex: to, next: g.start[from]} // Set the new edge and update the start pointer
	g.start[from] = g.pointer
	g.pointer++
}

func modPow(r, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = (int64(t) * int64(s)) % mod // If n is odd, multiply t by s
		}
		s = (int64(s) * int64(s)) % mod // Square s
		n >>= 1 // Halve n
	}
	return t
}

type node struct {
	one  int32 // Number of ways to have exactly one edge
	zero int32 // Number of ways to have exactly zero edges
}

func merge(a []node) node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for _, n := range a {
		one = (one*zero + int64(n.one)*zero) % mod // Calculate the number of ways to have exactly one edge
		zero = (zero * int64(n.zero)) % mod        // Calculate the number of ways to have exactly zero edges
		total = (total * (int64(n.zero) + int64(n.one))) % mod // Calculate the total number of ways
	}
	return node{one: int32(one), zero: int32((total + mod - one) % mod)} // Return the merged node
}

type deque struct {
	array []node
	front int
	last  int
	mask  int
}

func newDeque() *deque {
	len := 2
	return &deque{
		array: make([]node, len),
		front: 0,
		last:  0,
		mask:  len - 1,
	}
}

func (d *deque) getSize() int {
	return (d.last + (^d.front + 1)) & d.mask
}

func (d *deque) realloc() {
	newArray := make([]node, 2*(d.mask+1))
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

func (d *deque) getAt(x int) node {
	return d.array[(d.front+x)&d.mask]
}

func (d *deque) assignAt(x int, v node) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *deque) pushFront(v node) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b *deque) int {
	d := a.getSize() - b.getSize()
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	}
	return 1
}

func run() {
	var n int32
	fmt.Scan(&n) // Read the number of vertices
	p := make([]int32, n+1) // Array to store parent pointers
	depth := make([]int32, n+1) // Array to store depths of vertices
	cnt := make([]int32, n+1) // Array to count vertices at each depth
	cnt[0] = 1 // There is one way to have zero edges (the root itself)
	g := newGraph(n + 1) // Initialize the graph
	for i := int32(1); i <= n; i++ {
		fmt.Scan(&p[i]) // Read the parent of each vertex
		g.addEdge(p[i], i) // Add the edge to the graph
		depth[i] = depth[p[i]] + 1 // Calculate the depth of each vertex
		cnt[depth[i]]++ // Increment the count of vertices at the current depth
	}
	dp := make([]*deque, n+1) // Array to store dynamic programming results
	child := make([]*deque, n+1) // Array to store child deques
	lst := make([]node, n+1) // Array to store merged nodes
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(node{one: 1, zero: 1}) // Initialize the dp array for leaf nodes
			continue
		}
		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u] // Collect child deques
			len++
		}
		if len > 1 {
			sort.Slice(child[:len], func(i, j int) bool {
				return cmpDequeSize(child[i], child[j]) < 0
			}) // Sort child deques by size
			for d := 0; d < int(child[1].getSize()); d++ {
				j := 0
				for ; j < len && d < int(child[j].getSize()); j++ {
					lst[j] = child[j].getAt(d) // Get nodes at the current depth
				}
				child[0].assignAt(d, merge(lst[:j])) // Merge nodes and assign to the first child deque
			}
			for j := 1; j < len; j++ {
				child[j] = nil // Free memory of unused child deques
			}
		}
		dp[v] = child[0] // Assign the merged deque to the current vertex
		dp[v].pushFront(node{one: 1, zero: 1}) // Add the current node to the dp array
	}
	ans := int64(0)
	for i := 0; i < int(dp[0].getSize()); i++ {
		ans += (int64(modPow(2, n+1-cnt[int32(i)])) * int64(dp[0].getAt(i).one)) % mod // Calculate the answer
	}
	fmt.Println(ans % mod) // Print the result
}

func main() {
	run()
}

// <END-OF-CODE>
