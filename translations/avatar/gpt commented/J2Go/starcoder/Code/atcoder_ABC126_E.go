package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	m int
)

// UnionFindTree represents a disjoint set
type UnionFindTree struct {
	par  []int
	rank []int
}

// NewUnionFindTree creates a new UnionFindTree
func NewUnionFindTree(n int) *UnionFindTree {
	uf := &UnionFindTree{
		par:  make([]int, n),
		rank: make([]int, n),
	}
	for i := 0; i < n; i++ {
		uf.par[i] = i
		uf.rank[i] = 0
	}
	return uf
}

// Find returns the root of the set containing x
func (uf *UnionFindTree) Find(x int) int {
	if uf.par[x] == x {
		return x
	}
	uf.par[x] = uf.Find(uf.par[x])
	return uf.par[x]
}

// Unite merges the sets containing x and y
func (uf *UnionFindTree) Unite(x, y int) {
	x = uf.Find(x)
	y = uf.Find(y)
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

// Same returns true if x and y are in the same set
func (uf *UnionFindTree) Same(x, y int) bool {
	return uf.Find(x) == uf.Find(y)
}

// ReadInput reads the input from stdin
func ReadInput() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	m, _ = strconv.Atoi(sc.Text())
}

// Main starts the program
func main() {
	ReadInput()
	uf := NewUnionFindTree(n)
	for i := 0; i < m; i++ {
		sc := bufio.NewScanner(os.Stdin)
		sc.Split(bufio.ScanWords)
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
		uf.Unite(x-1, y-1)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if uf.Find(i) == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

// 