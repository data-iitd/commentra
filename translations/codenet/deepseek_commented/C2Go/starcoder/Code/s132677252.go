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
	g := &graph{}
	g.edge = make([]graphEdge, 1)
	g.start = make([]int, vertexNum)
	g.pointer = 0
	g.vertexNum = vertexNum
	g.edgeMaxSize = 1
	for i := 0; i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

// Function to add a directed edge to the graph
func addEdge(g *graph, from, to int) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize)...)
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
		if n&1 == 1 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
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
		one = (one * a[i].zero + zero * a[i].one) % mod
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
	d := &deque{}
	d.array = make([]dequeVal, 2)
	d.front = 0
	d.last = 0
	d.mask = 1
	return d
}

// Function to free the memory allocated for a deque
func freeDeque(d *deque) {
	d.array = nil
	d = nil
}

// Function to get the number of elements in the deque
func getSize(d *deque) int {
	return (d.last + (~d.front + 1)) & d.mask
}

// Function to reallocate the deque when necessary
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
	d.mask = 2 * d.mask + 1
}

// Function to get the value at a specific index in the deque
func getAt(d *deque, x int) dequeVal {
	return d.array[(d.front+x)&d.mask]
}

// Function to assign a value at a specific index in the deque
func assignAt(d *deque, x int, v dequeVal) {
	d.array[(d.front+x)&d.mask] = v
}

// Function to add an element to the front of the deque
func pushFront(d *deque, v dequeVal) {
	if ((d.last + 1) & d.mask) == d.front {
		dequeRealloc(d)
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

// Function to compare the sizes of two deques
func cmpDequeSize(a, b *deque) int {
	p := a
	q := b
	d := getSize(p) - getSize(q)
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

// Function to run the main logic of the program
func run() {
	var n int
<<<<<<< HEAD
	fmt.Scanf("%d", &n)
=======
	fmt.Scanf("%d\n", &n)
>>>>>>> 98c87cb78a (data updated)
	p := make([]int, n+1)
	depth := make([]int, n+1)
	cnt := make([]int, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)
	for i := 1; i <= n; i++ {
<<<<<<< HEAD
		fmt.Scanf("%d", &p[i])
=======
		fmt.Scanf("%d\n", &p[i])
>>>>>>> 98c87cb78a (data updated)
		addEdge(g, p[i], i)
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
			pushFront(dp[v], node{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			sort.Slice(child, func(i, j int) bool {
				return cmpDequeSize(child[i], child[j]) < 0
			})
			for d := 0; d < getSize(child[1]); d++ {
				j := 0
				for ; j < len && d < getSize(child[j]); j++ {
					lst[j] = getAt(child[j], d)
				}
				assignAt(child[0], d, merge(lst[:j], j))
			}
			for j := 1; j < len; j++ {
				freeDeque(child[j])
			}
		}
		dp[v] = child[0]
		pushFront(dp[v], node{1, 1})
	}
	ans := 0
	for i := 0; i < getSize(dp[0]); i++ {
		ans += (modPow(2, n+1-cnt[i]) * getAt(dp[0], i).one) % mod
	}
	fmt.Printf("%d\n", ans%mod)
}

// Main function to run the program
func main() {
	run()
}

