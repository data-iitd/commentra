package main

import (
	"fmt"
)

const MOD = 1000000007

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
	utf.par[x] = utf.find(utf.par[x])
	return utf.par[x]
}

func (utf *UnionFindTree) unite(x, y int) {
	x = utf.find(x)
	y = utf.find(y)
	if x == y {
		return
	}
	if utf.rank[x] < utf.rank[y] {
		utf.par[x] = y
	} else {
		utf.par[y] = x
		if utf.rank[x] == utf.rank[y] {
			utf.rank[x]++
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
		var z int // z is read but not used
		fmt.Scan(&x, &y, &z)
		utf.unite(x-1, y-1)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

// <END-OF-CODE>
