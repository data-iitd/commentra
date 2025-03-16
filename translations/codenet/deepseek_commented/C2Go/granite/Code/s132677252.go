
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type directedEdge struct {
	vertex int32
	next   int32
}

type directedGraph struct {
	edge       []*directedEdge
	start      []int32
	pointer    int32
	vertex_num int32
	edge_max_size int32
}

func newGraph(vertex_num int32) *directedGraph {
	g := &directedGraph{}
	g.edge = make([]*directedEdge, 1)
	g.start = make([]int32, vertex_num)
	g.pointer = 0
	g.vertex_num = vertex_num
	g.edge_max_size = 1
	for i := int32(0); i < vertex_num; i++ {
		g.start[i] = -1 // Initialize all start pointers to -1 (no edges initially)
	}
	return g
}

func addEdge(g *directedGraph, from int32, to int32) {
	if g.pointer == g.edge_max_size {
		g.edge_max_size *= 2
		g.edge = append(g.edge, make([]*directedEdge, g.edge_max_size-g.pointer)...)
	}
	g.edge[g.pointer] = &directedEdge{to, g.start[from]} // Set the new edge and update the start pointer
	g.start[from] = g.pointer // Update the start pointer to the new edge
	g.pointer++ // Increment the pointer
}

const mod = 1000000007

func modPow(r int32, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 == 1 {
			t = (t * s) % mod // If n is odd, multiply t by s
		}
		s = (s * s) % mod // Square s
		n >>= 1 // Halve n
	}
	return t
}

type node struct {
	one  int32 // Number of ways to have exactly one edge
	zero int32 // Number of ways to have exactly zero edges
}

func merge(a []*node, n int32) node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := int32(0); i < n; i++ {
		one = (one * a[i].zero + zero * a[i].one) % mod // Calculate the number of ways to have exactly one edge
		zero = zero * a[i].zero % mod // Calculate the number of ways to have exactly zero edges
		total = total * (a[i].zero + a[i].one) % mod // Calculate the total number of ways
	}
	return node{int32(one), int32((total + mod - one) % mod)} // Return the merged node
}

type deque struct {
	array []*node
	front int32
	last  int32
	mask  int32
}

func newDeque() *deque {
	d := &deque{}
	d.array = make([]*node, 2)
	d.front = 0
	d.last = 0
	d.mask = 1
	return d
}

func (d *deque) getSize() int32 {
	return (d.last + d.mask - d.front) & d.mask
}

func (d *deque) realloc() {
	newArray := make([]*node, 2*d.mask+1)
	k := int32(0)
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2 * d.mask + 1
}

func (d *deque) getAt(x int32) *node {
	return d.array[(d.front+x)&d.mask]
}

func (d *deque) assignAt(x int32, v *node) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *deque) pushFront(v *node) {
	if d.getSize()+1 > d.mask {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b interface{}) int {
	pa := a.(*deque)
	pb := b.(*deque)
	d := pa.getSize() - pb.getSize()
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	} else {
		return 1
	}
}

func run() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n) // Read the number of vertices
	p := make([]int32, n+1) // Array to store parent pointers
	depth := make([]int32, n+1) // Array to store depths of vertices
	cnt := make([]int32, n+1) // Array to count vertices at each depth
	cnt[0] = 1 // There is one way to have zero edges (the root itself)
	g := newGraph(n + 1) // Initialize the graph
	for i := int32(1); i <= n; i++ {
		fmt.Fscanf(reader, "%d\n", &p[i]) // Read the parent of each vertex
		addEdge(g, p[i], i) // Add the edge to the graph
		depth[i] = depth[p[i]] + 1 // Calculate the depth of each vertex
		cnt[depth[i]]++ // Increment the count of vertices at the current depth
	}
	dp := make([]*deque, n+1) // Array to store dynamic programming results
	child := make([]*deque, n+1) // Array to store child deques
	lst := make([]*node, n+1) // Array to store merged nodes
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(&node{1, 1}) // Initialize the dp array for leaf nodes
			continue
		}
		len := int32(0)
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u] // Collect child deques
			len++
		}
		if len > 1 {
			sort.Slice(child[:len], cmpDequeSize) // Sort child deques by size
			for d := int32(0); d < child[1].getSize(); d++ {
				j := int32(0)
				for ; j < len && d < child[j].getSize(); j++ {
					lst[j] = child[j].getAt(d) // Get nodes at the current depth
				}
				child[0].assignAt(d, merge(lst, j)) // Merge nodes and assign to the first child deque
			}
			for j := int32(1); j < len; j++ {
				d := child[j]
				for d.getSize() > 0 {
					d.array[d.front] = nil // Free memory of nodes in the deque
					d.front = (d.front + 1) & d.mask
					d.last--
				}
			}
		}
		dp[v] = child[0] // Assign the merged deque to the current vertex
		dp[v].pushFront(&node{1, 1}) // Add the current node to the dp array
	}
	ans := int64(0)
	for i := int32(0); i < n+1; i++ {
		ans = (ans + int64(modPow(2, n+1-cnt[i])*dp[0].getAt(i).one) % mod // Calculate the answer
	}
	fmt.Println(ans) // Print the result
}

func main() {
	run()
}