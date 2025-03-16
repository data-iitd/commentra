package main

import (
	"bufio"
	"fmt"
	"os"
)

type BitMatching struct {
	G    [][]int
	match []int
	used  []bool
}

func (bm *BitMatching) init(V int) {
	bm.G = make([][]int, 2*V)
	bm.match = make([]int, 2*V)
	bm.used = make([]bool, 2*V)
	for i := 0; i < 2*V; i++ {
		bm.G[i] = []int{}
		bm.match[i] = -1
	}
}

func (bm *BitMatching) add(a, b, V int) {
	bm.G[a] = append(bm.G[a], b+V)
	bm.G[b+V] = append(bm.G[b+V], a)
}

func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true
	for _, u := range bm.G[v] {
		w := bm.match[u]
		if w == -1 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false
}

func (bm *BitMatching) exec(V int) int {
	res := 0
	for v := 0; v < V; v++ {
		if bm.match[v] == -1 {
			for i := 0; i < len(bm.used); i++ {
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
		a, b = b, a % b
	}
	return a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		var n, m int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &n, &m)
		if n == 0 {
			break
		}

		bm := BitMatching{}
		bm.init(520)
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &a[i])
		}
		for i := 0; i < m; i++ {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &b[i])
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 {
					bm.add(i, j, m)
				}
			}
		}

		fmt.Println(bm.exec(n))
	}
}

