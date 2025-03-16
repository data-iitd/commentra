package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type UnionFindTree struct {
	n     int
	par   []int
	rank  []int
}

func NewUnionFindTree(n int) *UnionFindTree {
	uf := &UnionFindTree{n: n, par: make([]int, n), rank: make([]int, n)}
	for i := 0; i < n; i++ {
		uf.par[i] = i
		uf.rank[i] = 0
	}
	return uf
}

func (uf *UnionFindTree) find(x int) int {
	if uf.par[x] == x {
		return x
	}
	uf.par[x] = uf.find(uf.par[x])
	return uf.par[x]
}

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

func (uf *UnionFindTree) same(x, y int) bool {
	return uf.find(x) == uf.find(y)
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	uf := NewUnionFindTree(n)
	sc.Scan()
	m, _ := strconv.Atoi(sc.Text())
	for i := 0; i < m; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		z, _ := strconv.Atoi(sc.Text())
		uf.unite(x-1, y-1)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if uf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

