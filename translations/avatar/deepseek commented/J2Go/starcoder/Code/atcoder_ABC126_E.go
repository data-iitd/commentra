
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
	uf := &UnionFindTree{
		n:     n,
		par:   make([]int, n),
		rank:  make([]int, n),
	}
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
	return uf.find(uf.par[x])
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

	// Step 1: Read the input number of elements (n) and create a UnionFindTree instance.
	n, _ := strconv.Atoi(sc.Text())
	uf := NewUnionFindTree(n)

	// Step 2: Read the number of operations (m) and iterate through each operation.
	m, _ := strconv.Atoi(sc.Text())
	for i := 0; i < m; i++ {
		// Step 3: For each operation, read the two elements (x and y) and the operation type (z).
		x, _ := strconv.Atoi(sc.Text())
		y, _ := strconv.Atoi(sc.Text())
		z, _ := strconv.Atoi(sc.Text())

		// Step 4: Perform the union operation on the elements x and y.
		uf.unite(x-1, y-1)
	}

	// Step 5: Count the number of connected components in the UnionFindTree and print the result.
	cnt := 0
	for i := 0; i < n; i++ {
		if uf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

// 