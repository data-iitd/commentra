package main

import (
	"fmt"
)

const MN = 520

type BitMatching struct {
	G    [][]int
	match []int
	used  []bool
}

func NewBitMatching() *BitMatching {
	bm := &BitMatching{
		G:    make([][]int, 2*MN),
		match: make([]int, 2*MN),
		used:  make([]bool, 2*MN),
	}
	for i := range bm.match {
		bm.match[i] = -1
	}
	return bm
}

func (bm *BitMatching) init() {
	for i := range bm.G {
		bm.G[i] = nil
	}
}

func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+MN)
	bm.G[b+MN] = append(bm.G[b+MN], a)
}

func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true
	for _, u := range bm.G[v] {
		w := bm.match[u]
		if w < 0 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false
}

func (bm *BitMatching) exec() int {
	res := 0
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 {
			for i := range bm.used {
				bm.used[i] = false
			}
			if bm.dfs(v) {
				res++
			}
		}
	}
	return res
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}
		bm := NewBitMatching()
		bm.init()
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i])
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 {
					bm.add(i, j)
				}
			}
		}
		fmt.Println(bm.exec())
	}
}

// <END-OF-CODE>
