
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a constant value for modulo operation
const MOD = 1000000007

// Defining a structure named UnionFindTree
type UnionFindTree struct {
	n     int
	par   []int
	rank  []int
}

// Defining a function named NewUnionFindTree
func NewUnionFindTree(n int) *UnionFindTree {
	uf := &UnionFindTree{n: n}
	uf.par = make([]int, n)
	uf.rank = make([]int, n)
	for i := 0; i < n; i++ {
		uf.par[i] = i
		uf.rank[i] = 0
	}
	return uf
}

// Defining a function named find
func (uf *UnionFindTree) find(x int) int {
	if uf.par[x] == x {
		return x
	}
	return uf.find(uf.par[x])
}

// Defining a function named unite
func (uf *UnionFindTree) unite(x, y int) {
	x = uf.find(x)
	y = uf.find(y)
	if x == y {
		return
	}
	if uf.rank[x] < uf.rank[y] {
		uf.par[x] = y
	} else {
		uf.par[y] = x
		if uf.rank[x] == uf.rank[y] {
			uf.rank[x]++
		}
	}
}

// Defining a function named same
func (uf *UnionFindTree) same(x, y int) bool {
	return uf.find(x) == uf.find(y)
}

// Defining a function named doIt
func doIt() {
	var n int
	fmt.Scanf("%d", &n)
	uf := NewUnionFindTree(n)
	var m int
	fmt.Scanf("%d", &m)
	for i := 0; i < m; i++ {
		var x, y, z int
		fmt.Scanf("%d %d %d", &x, &y, &z)
		x--
		y--
		uf.unite(x, y)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if uf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

func main() {
	doIt()
}

// 