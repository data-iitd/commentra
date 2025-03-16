package main

import (
	"fmt"
	"math/big"
)

const MN = 520

type BitMatching struct {
	G       [2 * MN][]int
	match   [2 * MN]int
	used    [2 * MN]bool
}

func (bm *BitMatching) init() {
	for i := 0; i < 2*MN; i++ {
		bm.G[i] = []int{}
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

func gcd(a, b *big.Int) *big.Int {
	if b.Cmp(big.NewInt(0)) == 0 {
		return a
	}
	return gcd(b, new(big.Int).Mod(a, b))
}

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)

		if n == 0 {
			break
		}

		bm := BitMatching{}
		bm.init()

		a := make([]*big.Int, n)
		b := make([]*big.Int, m)

		for i := 0; i < n; i++ {
			var x big.Int
			fmt.Scan(&x)
			a[i] = &x
		}

		for i := 0; i < m; i++ {
			var y big.Int
			fmt.Scan(&y)
			b[i] = &y
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]).Cmp(big.NewInt(1)) != 0 {
					bm.add(i, j)
				}
			}
		}

		fmt.Println(bm.exec())
	}
}

