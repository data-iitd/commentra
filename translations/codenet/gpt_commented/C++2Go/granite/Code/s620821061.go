
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MN = 520
)

type BitMatching struct {
	G      [2 * MN]int
	match  [2 * MN]int
	used   [2 * MN]bool
	V      int
}

func (bm *BitMatching) init() {
	bm.V = 0
	for i := 0; i < 2*MN; i++ {
		bm.G[i] = 0
	}
}

func (bm *BitMatching) add(a, b int) {
	bm.G[a] |= 1 << (b + MN)
	bm.G[b+MN] |= 1 << a
}

func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true
	for i := 0; i < 2*MN; i++ {
		if (bm.G[v]>>i)&1 == 1 {
			u := i
			w := bm.match[u]
			if w < 0 || (!bm.used[w] && bm.dfs(w)) {
				bm.match[v] = u
				bm.match[u] = v
				return true
			}
		}
	}
	return false
}

func (bm *BitMatching) exec() int {
	res := 0
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 {
			for i := 0; i < 2*MN; i++ {
				bm.used[i] = false
			}
			if bm.dfs(v) {
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
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n, m int
	for scanner.Scan() {
		n = int(nextInt64(scanner.Bytes()))
		if n == 0 {
			break
		}
		bm := BitMatching{}
		bm.init()
		a := make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i] = int(nextInt64(scanner.Bytes()))
		}
		b := make([]int, m)
		for i := 0; i < m; i++ {
			scanner.Scan()
			b[i] = int(nextInt64(scanner.Bytes()))
		}
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(int64(a[i]), int64(b[j]))!= 1 {
					bm.add(i, j)
				}
			}
		}
		fmt.Println(bm.exec())
	}
}

func nextInt64(bytes []byte) int64 {
	res := int64(0)
	for i := 0; i < len(bytes); i++ {
		res *= 10
		res += int64(bytes[i]-'0')
	}
	return res
}

// END-OF-CODE