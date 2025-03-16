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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Bytes())
	utf := NewUnionFindTree(n)

	scanner.Scan()
	m := parseInt(scanner.Bytes())
	for i := 0; i < m; i++ {
		scanner.Scan()
		x := parseInt(scanner.Bytes()) - 1
		scanner.Scan()
		y := parseInt(scanner.Bytes()) - 1
		scanner.Scan()
		z := parseInt(scanner.Bytes())

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

func parseInt(b []byte) int {
	var num int
	for _, v := range b {
		num = num*10 + int(v-'0')
	}
	return num
}

