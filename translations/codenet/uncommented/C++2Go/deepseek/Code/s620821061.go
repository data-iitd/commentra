package main

import (
	"bufio"
	"fmt"
	"os"
)

type BitMatching struct {
	G       [][]int
	match   []int
	used    []bool
	V       int
}

func (bm *BitMatching) init() {
	bm.G = make([][]int, 2*bm.V)
	for i := 0; i < 2*bm.V; i++ {
		bm.G[i] = []int{}
	}
}

func (bm *BitMatching) add(a, b int) {
	bm.G[a] = append(bm.G[a], b+bm.V)
	bm.G[b+bm.V] = append(bm.G[b+bm.V], a)
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
	bm.match = make([]int, 2*bm.V)
	for i := 0; i < 2*bm.V; i++ {
		bm.match[i] = -1
	}
	bm.used = make([]bool, 2*bm.V)
	for v := 0; v < bm.V; v++ {
		if bm.match[v] < 0 {
			for i := 0; i < 2*bm.V; i++ {
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
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	in := bufio.NewScanner(os.Stdin)
	for {
		in.Scan()
		n, _ := fmt.Sscan(in.Text(), &n)
		m, _ := fmt.Sscan(in.Text(), &m)
		if n == 0 {
			break
		}
		bm := BitMatching{V: n}
		bm.init()
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			in.Scan()
			fmt.Sscan(in.Text(), &a[i])
		}
		for i := 0; i < m; i++ {
			in.Scan()
			fmt.Sscan(in.Text(), &b[i])
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
