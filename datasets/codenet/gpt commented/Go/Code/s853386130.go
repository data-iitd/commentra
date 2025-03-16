package main

import (
	"bufio"
	"fmt"
	"os"
)

var mod = 1000000007
var INF = 1000000007

func main() {
	// Initialize a buffered reader to read input
	r := bufio.NewReader(os.Stdin)
	var n, m, R int
	
	// Read the number of nodes (n), edges (m), and the number of required nodes (R)
	fmt.Fscan(r, &n)
	fmt.Fscan(r, &m)
	fmt.Fscan(r, &R)

	// Read the required nodes and adjust for 0-based indexing
	rs := make([]int, R)
	for i := 0; i < R; i++ {
		fmt.Fscan(r, &rs[i])
		rs[i]--
	}

	// Initialize the cost matrix with INF values
	costs := make([][]int, n)
	for i := 0; i < n; i++ {
		costs[i] = make([]int, n)
		for j := 0; j < n; j++ {
			costs[i][j] = INF
		}
		costs[i][i] = 0 // The cost to reach itself is 0
	}
	
	// Read the edges and their costs
	var a, b, c int
	for i := 0; i < m; i++ {
		fmt.Fscan(r, &a)
		fmt.Fscan(r, &b)
		fmt.Fscan(r, &c)
		a--
		b--
		costs[a][b] = c // Set cost for edge a to b
		costs[b][a] = c // Set cost for edge b to a (undirected graph)
	}

	// Calculate the shortest paths using the Floyd-Warshall algorithm
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j])
			}
		}
	}

	// Generate all permutations of the required nodes
	perms := permutations(rs)
	ans := INF
	
	// Evaluate each permutation to find the minimum cost path
	for _, perm := range perms {
		tmp := 0
		for j := 1; j < len(perm); j++ {
			from := perm[j-1]
			to := perm[j]
			tmp += costs[from][to] // Accumulate the cost of the current permutation
		}
		ans = min(ans, tmp) // Update the answer with the minimum cost found
	}
	
	// Output the minimum cost
	fmt.Println(ans)
}

// permutations generates all permutations of an array
func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	// Recursive helper function to generate permutations
	helper = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				// Swap elements based on the parity of n
				if n%2 == 1 {
					tmp := arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				} else {
					tmp := arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

// Union-Find structure for disjoint set operations
type unionFind struct {
	d []int
}

// newUnionFind initializes a new Union-Find structure
func newUnionFind(n int) *unionFind {
	uf := new(unionFind)
	uf.d = make([]int, n)
	for i := 0; i < n; i++ {
		uf.d[i] = -1 // Initialize each node as its own root
	}
	return uf
}

// find finds the root of the set containing x
func (uf *unionFind) find(x int) int {
	if uf.d[x] < 0 {
		return x
	}
	uf.d[x] = uf.find(uf.d[x]) // Path compression
	return uf.d[x]
}

// unite merges the sets containing x and y
func (uf *unionFind) unite(x, y int) bool {
	rootX := uf.find(x)
	rootY := uf.find(y)
	if rootX == rootY {
		return false // x and y are already in the same set
	}

	// Union by size
	if uf.d[rootX] < uf.d[rootY] {
		uf.d[rootX] += uf.d[rootY]
		uf.d[rootY] = rootX
	} else {
		uf.d[rootY] += uf.d[rootX]
		uf.d[rootX] = rootY
	}

	return true
}

// same checks if x and y are in the same set
func (uf *unionFind) same(x, y int) bool {
	return uf.find(x) == uf.find(y)
}

// size returns the size of the set containing x
func (uf *unionFind) size(x int) int {
	return -uf.d[uf.find(x)]
}

// modpow calculates (a^n) % mod using exponentiation by squaring
func modpow(a, n, mod int) int {
	res := 1
	for n > 0 {
		if n%2 != 0 {
			res = res * a % mod
		}
		a = a * a % mod
		n = n / 2
	}
	return res
}

// modinv calculates the modular inverse of n % mod
func modinv(n, mod int) int {
	return modpow(n, mod-2, mod)
}

// modcomb calculates n choose a (nCk) % mod
func modcomb(n, a, mod int) int {
	x := 1
	y := 1
	for i := 0; i < a; i++ {
		x = x * (n - i)
		x %= mod
		y = y * (i + 1)
		y %= mod
	}
	return x * modpow(y, mod-2, mod) % mod
}

// modfactorial calculates n! % mod
func modfactorial(n, mod int) int {
	result := 1
	for i := 1; i <= n; i++ {
		result = (result * i) % mod
	}
	return result
}

// Combination structure for precomputed factorials and inverses
type Combination struct {
	facts, invs []int
	mod         int
}

// NewCombination initializes a new Combination structure
func NewCombination(n, mod int) Combination {
	return Combination{
		facts: make([]int, n+1),
		invs:  make([]int, n+1),
		mod:   mod,
	}
}

// calc computes n choose k (nCk) using precomputed values
func (cmb *Combination) calc(n, k int) int {
	ret := cmb.facts[n] * cmb.invs[k]
	ret %= cmb.mod
	ret = ret * cmb.invs[n-k]
	ret %= cmb.mod
	return ret
}

// init precomputes factorials and their inverses
func (cmb *Combination) init(n int) {
	cmb.facts[0] = 1
	// Calculate factorials
	for i := 1; i <= n; i++ {
		cmb.facts[i] = cmb.facts[i-1] * i % cmb.mod
	}
	// Calculate inverses using modular inverse
	cmb.invs[n] = modinv(cmb.facts[n], cmb.mod)
	for i := n - 1; i >= 0; i-- {
		cmb.invs[i] = cmb.invs[i+1] * (i + 1) % cmb.mod
	}
}

// Utility functions

// min returns the smaller of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// max returns the larger of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// abs returns the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// primeFactor returns the prime factorization of x
func primeFactor(x int) map[int]int {
	res := make(map[int]int)
	for i := 2; i*i <= x; i++ {
		for x%i == 0 {
			res[i]++
			x = x / i
		}
	}
	if x != 1 {
		res[x] = 1
	}
	return res
}

// divisor returns all divisors of x
func divisor(x int) []int {
	res := make([]int, 0)
	for i := 1; i*i <= x; i++ {
		if x%i == 0 {
			res = append(res, i)
			if i != x/i {
				res = append(res, x/i)
			}
		}
	}
	return res
}

// gcd returns the greatest common divisor of x and y
func gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

// lcm returns the least common multiple of x and y
func lcm(x, y int) int {
	return x / gcd(x, y) * y
}

// reverseString returns the reversed version of a string
func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// pow calculates a raised to the power of n
func pow(a, n int) int {
	ret := 1
	for i := 1; i <= n; i++ {
		ret *= a
	}
	return ret
}

// Queue structure for implementing a queue
type Queue []int

// empty checks if the queue is empty
func (q *Queue) empty() bool {
	return len(*q) == 0
}

// push adds an element to the queue
func (q *Queue) push(i int) {
	*q = append(*q, i)
}

// pop removes and returns the front element of the queue
func (q *Queue) pop() (int, bool) {
	if q.empty() {
		return 0, false
	} else {
		res := (*q)[0]
		*q = (*q)[1:]
		return res, true
	}
}

// Stack structure for implementing a stack
type Stack []int

// empty checks if the stack is empty
func (s *Stack) empty() bool {
	return len(*s) == 0
}

// push adds an element to the stack
func (s *Stack) push(i int) {
	*s = append(*s, i)
}

// pop removes and returns the top element of the stack
func (s *Stack) pop() (int, bool) {
	if s.empty() {
		return 0, false
	} else {
		index := len(*s) - 1
		res := (*s)[index]
		*s = (*s)[:index]
		return res, true
	}
}

// priority_queue structure for implementing a max-heap
type intHeap []int

func (h intHeap) Len() int           { return len(h) }
func (h intHeap) Less(i, j int) bool { return h[i] > h[j] } // Max-heap
func (h intHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

// Push adds an element to the heap
func (h *intHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop removes and returns the top element of the heap
func (h *intHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// sortable points structure for sorting points
type point struct {
	x int
	y int
}

type points []point

// Len returns the number of points
func (p points) Len() int {
	return len(p)
}

// Less compares two points based on their x-coordinate
func (p points) Less(i, j int) bool {
	return p[i].x < p[j].x
}

// Swap swaps two points in the slice
func (p points) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
