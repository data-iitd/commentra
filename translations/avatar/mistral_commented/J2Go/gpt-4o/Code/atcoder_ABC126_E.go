package main

import (
	"fmt"
)

type UnionFindTree struct {
	n    int
	par  []int
	rank []int
}

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

func (utf *UnionFindTree) find(x int) int {
	if utf.par[x] == x {
		return x
	}
	utf.par[x] = utf.find(utf.par[x]) // Path compression
	return utf.par[x]
}

func (utf *UnionFindTree) unite(x, y int) {
	xRoot := utf.find(x)
	yRoot := utf.find(y)
	if xRoot == yRoot {
		return
	}
	if utf.rank[xRoot] < utf.rank[yRoot] {
		utf.par[xRoot] = yRoot
	} else {
		utf.par[yRoot] = xRoot
		if utf.rank[xRoot] == utf.rank[yRoot] {
			utf.rank[xRoot]++
		}
	}
}

func (utf *UnionFindTree) same(x, y int) bool {
	return utf.find(x) == utf.find(y)
}

func main() {
	var n, m int
	fmt.Scan(&n) // Reading the number of vertices n
	utf := NewUnionFindTree(n) // Creating an instance of UnionFindTree with n vertices
	fmt.Scan(&m) // Reading the number of edges m

	// Processing the edges
	for i := 0; i < m; i++ {
		var x, y, z int
		fmt.Scan(&x, &y, &z) // Reading the source vertex x, destination vertex y, and weight z
		utf.unite(x-1, y-1) // Merging the two vertices x and y (adjusting for 0-based index)
	}

	cnt := 0 // Initializing a counter variable for the number of connected components
	for i := 0; i < n; i++ {
		if utf.par[i] == i { // Checking if the current vertex is the root of a connected component
			cnt++ // Incrementing the counter if it is
		}
	}
	fmt.Println(cnt) // Printing the number of connected components
}

// <END-OF-CODE>
