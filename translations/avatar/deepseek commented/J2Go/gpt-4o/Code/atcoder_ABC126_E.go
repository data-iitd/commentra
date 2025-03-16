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
	fmt.Scan(&n)
	utf := NewUnionFindTree(n)

	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		var x, y int
		var z int // z is read but not used in this implementation
		fmt.Scan(&x, &y, &z)
		utf.unite(x-1, y-1) // Convert to 0-based index
	}

	// Count the number of connected components
	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

// <END-OF-CODE>
