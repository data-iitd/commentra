package main

import (
	"fmt"
	"math/big"
)

// Define a structure for a directed edge in the graph
type graphEdge struct {
	vertex int
	next   int
}

// Define a structure for the directed graph
type graph struct {
	edge       []graphEdge
	start      []int
	pointer    int
	vertexNum  int
	edgeMaxSize int
}

// Function to initialize a new graph with a given number of vertices
func newGraph(vertexNum int) *graph {
	g := &graph{
		edge:       []graphEdge{{0, 0}},
		start:      make([]int, vertexNum),
		pointer:    0,
		vertexNum:  vertexNum,
		edgeMaxSize: 1,
	}
	for i := 0; i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

// Function to add a directed edge to the graph
func (g *graph) addEdge(from, to int) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, graphEdge{0, 0})
	}
	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

// Define the modulo constant
const mod = 1000000007

// Function to compute r^n % mod using exponentiation by squaring
func modPow(r, n int) int {
	t := 1
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = t * s % mod
		}
		s = s * s % mod
		n >>= 1
	}
	return t
}

// Define a structure for a node in the dynamic programming array
type node struct {
	one  int
	zero int
}

// Function to merge two nodes in the dynamic programming array
func merge(a []node, n int) node {
	one := 0
	zero := 1
	total := 1
	for i := 0; i < n; i++ {
		one = (one*a[i].zero + int(int64(zero)*int64(a[i].one))) % mod
		zero = zero * a[i].zero % mod
		total = total * (a[i].zero + a[i].one) % mod
	}
	return node{one, (total + mod - one) % mod}
}

// Define the type for values stored in the deque
type dequeVal node

// Define a structure for the deque
type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

// Function to initialize a new deque
func newDeque() *deque {
	d := &deque{
		array: []dequeVal{{0, 0}},
		front: 0,
		last:  0,
		mask:  1,
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

// Function to get the number of elements in the deque
func (d *deque) getSize() int {
	return (d.last + (^d.front + 1)) & d.mask
}

// Function to reallocate the deque when necessary
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

// Function to add an element to the front of the deque
func (d *deque) pushFront(v dequeVal) {
	if ((d.last+1)&d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

// Function to compare the sizes of two deques
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

// Function to run the main logic of the program
func run() {
	var n int
	fmt.Scanf("%d", &n)
	p := make([]int, n+1)
	depth := make([]int, n+1)
	cnt := make([]int, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &p[i])
		g.addEdge(p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(dequeVal{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			qsort(child[:len], func(i, j int) bool {
				return child[i].getSize() < child[j].getSize()
			})
			for d := 0; d < child[1].getSize(); d++ {
				j := 0
				for ; j < len && d < child[j].getSize(); j++ {
					lst[j] = child[j].getAt(d)
				}
				child[0].assignAt(d, merge(lst[:j], j))
			}
			for j := 1; j < len; j++ {
				child[j].free()
			}
		}
		dp[v] = child[0]
		dp[v].pushFront(dequeVal{1, 1})
	}
	ans := 0
	for i := 0; i < dp[0].getSize(); i++ {
		ans += int64(modPow(2, n+1-cnt[i])) * int64(dp[0].getAt(i).one) % mod
	}
	fmt.Println(ans % mod)
}

// Main function to run the program
func main() {
	run()
}

