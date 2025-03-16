package main

import (
	"fmt"
)

type UnionFindTree struct {
	n    int
	par  []int
	rank []int
}

// Constructor to initialize the Union-Find structure
func NewUnionFindTree(n int) *UnionFindTree {
	utf := &UnionFindTree{
		n:    n,
		par:  make([]int, n),
		rank: make([]int, n),
	}
	for i := 0; i < n; i++ {
		utf.par[i] = i
		utf.rank[i] = 0
	}
	return utf
}

// Find the root of the set containing x with path compression
func (utf *UnionFindTree) Find(x int) int {
	if utf.par[x] == x {
		return x
	}
	utf.par[x] = utf.Find(utf.par[x])
	return utf.par[x]
}

// Unite the sets containing x and y
func (utf *UnionFindTree) Unite(x, y int) {
	xRoot := utf.Find(x)
	yRoot := utf.Find(y)
	if xRoot == yRoot {
		return
	}
	// Union by rank
	if utf.rank[xRoot] < utf.rank[yRoot] {
		utf.par[xRoot] = yRoot
	} else {
		utf.par[yRoot] = xRoot
		if utf.rank[xRoot] == utf.rank[yRoot] {
			utf.rank[xRoot]++
		}
	}
}

// Check if x and y are in the same set
func (utf *UnionFindTree) Same(x, y int) bool {
	return utf.Find(x) == utf.Find(y)
}

func main() {
	var n, m int
	fmt.Scan(&n) // Read the number of elements (nodes)
	utf := NewUnionFindTree(n) // Initialize Union-Find data structure
	fmt.Scan(&m) // Read the number of connections (edges)

	// Process each connection
	for i := 0; i < m; i++ {
		var x, y, z int
		fmt.Scan(&x, &y, &z) // Read the two nodes to unite and the weight
		utf.Unite(x-1, y-1) // Unite the two nodes (adjusting for 0-based index)
	}

	// Count the number of unique connected components
	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i { // Check if the current node is a root of a component
			cnt++
		}
	}

	// Output the count of unique connected components
	fmt.Println(cnt)
}

// <END-OF-CODE>
