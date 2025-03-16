
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"sort"
)

type BitMatching struct {
	G      [][]int
	match  []int
	used   []bool
	V      int
}

func (bm *BitMatching) init() {
	bm.V = 0
	bm.G = make([][]int, 0)
	bm.match = make([]int, 0)
	bm.used = make([]bool, 0)
}

func (bm *BitMatching) add(a, b int) {
	for len(bm.G) <= a {
		bm.G = append(bm.G, make([]int, 0))
		bm.match = append(bm.match, -1)
		bm.used = append(bm.used, false)
	}
	for len(bm.G) <= b {
		bm.G = append(bm.G, make([]int, 0))
		bm.match = append(bm.match, -1)
		bm.used = append(bm.used, false)
	}
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
	bm.match = make([]int, len(bm.G))
	for i := 0; i < bm.V; i++ {
		if bm.match[i] < 0 {
			bm.used = make([]bool, len(bm.G))
			if bm.dfs(i) {
				res++
			}
		}
	}
	return res
}

func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	const MN = 520
	bm := BitMatching{}
	bm.init()
	var n, m int
	var a, b int64
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
	}
	for n!= 0 {
		a = make([]int64, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			fmt.Sscanf(scanner.Text(), "%d", &a[i])
		}
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &m)
		b = make([]int64, m)
		for i := 0; i < m; i++ {
			scanner.Scan()
			fmt.Sscanf(scanner.Text(), "%d", &b[i])
		}
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j])!= 1 {
					bm.add(i, j)
				}
			}
		}
		fmt.Println(bm.exec())
		bm.init()
		for scanner.Scan() {
			n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
		}
	}
}

