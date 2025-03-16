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
	return &UnionFindTree{n: n, par: par, rank: rank}
}

func (uf *UnionFindTree) find(x int) int {
	if uf.par[x] == x {
		return x
	} else {
		uf.par[x] = uf.find(uf.par[x])
		return uf.par[x]
	}
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())
	utf := NewUnionFindTree(n)

	scanner.Scan()
	m := parseInt(scanner.Text())

	for i := 0; i < m; i++ {
		scanner.Scan()
		x := parseInt(scanner.Text()) - 1
		scanner.Scan()
		y := parseInt(scanner.Text()) - 1
		scanner.Scan()
		z := parseInt(scanner.Text())
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

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

