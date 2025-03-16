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

func (utf *UnionFindTree) find(x int) int {
	if utf.par[x] == x {
		return x
	} else {
		utf.par[x] = utf.find(utf.par[x])
		return utf.par[x]
	}
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
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

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
	fmt.Fprintln(writer, cnt)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

