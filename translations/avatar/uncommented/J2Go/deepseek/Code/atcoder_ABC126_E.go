package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

type UnionFindTree struct {
	n    int
	par  []int
	rank []int
}

func NewUnionFindTree(n int) *UnionFindTree {
	par := make([]int, n)
	rank := make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = i
		rank[i] = 0
	}
	return &UnionFindTree{n, par, rank}
}

func (uft *UnionFindTree) find(x int) int {
	if uft.par[x] == x {
		return x
	} else {
		uft.par[x] = uft.find(uft.par[x])
		return uft.par[x]
	}
}

func (uft *UnionFindTree) unite(x, y int) {
	x = uft.find(x)
	y = uft.find(y)
	if x == y {
		return
	}
	if uft.rank[x] < uft.rank[y] {
		uft.par[x] = y
	} else {
		uft.par[y] = x
		if uft.rank[x] == uft.rank[y] {
			uft.rank[x]++
		}
	}
}

func (uft *UnionFindTree) same(x, y int) bool {
	return uft.find(x) == uft.find(y)
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	utf := NewUnionFindTree(sc.Int())
	n := sc.Int()
	m := sc.Int()
	for i := 0; i < m; i++ {
		x := sc.Int() - 1
		y := sc.Int() - 1
		z := sc.Int()
		utf.unite(x, y)
	}

	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

