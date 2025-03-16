<<<<<<< HEAD

// Package main runs the code

=======
// Include necessary headers for input/output, data manipulation, and other functionalities
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define constants and data structures
<<<<<<< HEAD
const (
	N = 100000
	MAX_L = 22
)

// Define data structures
type pair struct {
	x, y int
}
type pairList []pair

// Define functions
func (p pairList) Len() int           { return len(p) }
func (p pairList) Less(i, j int) bool { return p[i].x < p[j].x }
func (p pairList) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p *pairList) Push(x interface{}) { *p = append(*p, x.(pair)) }
func (p *pairList) Pop() interface{}   { a := *p; *p, a = a[:len(a)-1], a[len(a):]; return a[len(a)-1] }
func (p pairList) String() string {
	s := "pairList["
	for i := 0; i < len(p); i++ {
		s += fmt.Sprintf("{%d, %d}", p[i].x, p[i].y)
		if i < len(p)-1 {
			s += ", "
		}
	}
	s += "]"
	return s
}

// Define variables
var (
	G [N]pairList
	U [MAX_L][N]int
	R [N]int
	L [N]int
)

// Define functions
=======
const MOD = 1000000007
const MAX_L = 22
type P struct {
	x, y int
}
var N int
var G [100000][]P
var U [MAX_L][100000]int
var R [100000]int
var L [100000]int

// Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
>>>>>>> 98c87cb78a (data updated)
func dfs(x, p, r, l int) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp.x
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+pp.y)
	}
}

<<<<<<< HEAD
=======
// Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
>>>>>>> 98c87cb78a (data updated)
func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for k := 0; k < MAX_L; k++ {
		if (R[a] - R[b])>>k&1 == 1 {
			b = U[k][b]
		}
	}
	if a == b {
		return a
	}
	for k := MAX_L - 1; k >= 0; k-- {
		if U[k][a]!= U[k][b] {
			a = U[k][a]
			b = U[k][b]
		}
	}
	return U[0][a]
}

<<<<<<< HEAD
=======
// Distance calculation function to find the distance between two nodes
>>>>>>> 98c87cb78a (data updated)
func dist(x, y int) int {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

// Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
func main() {
<<<<<<< HEAD
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	var N int
=======
	reader := bufio.NewReader(os.Stdin)
	defer reader.Close()
>>>>>>> 98c87cb78a (data updated)
	fmt.Fscan(reader, &N)
	for i := 0; i < N-1; i++ {
		var a, b, c int
		fmt.Fscan(reader, &a, &b, &c)
		a--
		b--
<<<<<<< HEAD
		G[a] = append(G[a], pair{b, c})
		G[b] = append(G[b], pair{a, c})
=======
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
>>>>>>> 98c87cb78a (data updated)
	}
	for i := 0; i < MAX_L; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}
	dfs(0, -1, 0, 0)
	for i := 0; i < MAX_L-1; i++ {
<<<<<<< HEAD
		for j := 0; j < N; j++ {
			if U[i][j] == -1 {
				U[i+1][j] = -1
			} else {
				U[i+1][j] = U[i][U[i][j]]
=======
		for v := 0; v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
>>>>>>> 98c87cb78a (data updated)
			}
		}
	}
	var Q, K int
	fmt.Fscan(reader, &Q, &K)
	K--
	for i := 0; i < Q; i++ {
		var x, y int
		fmt.Fscan(reader, &x, &y)
		x--
		y--
		fmt.Println(dist(x, K) + dist(K, y))
	}
}

