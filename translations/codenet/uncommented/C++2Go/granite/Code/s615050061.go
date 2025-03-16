
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	B = 13131
	N = 500000 + 7
)

var (
	n int
	s string
	f [N]uint64
	g [N]int
	m = make(map[uint64]uint64)
	cnt uint64
)

func pow(a, k int64) uint64 {
	if k < 0 {
		k = (1 << 63) - 1
	}
	t := uint64(1)
	for ; k > 0; a *= a, k >>= 1 {
		if k&1 == 1 {
			t *= uint64(a)
		}
	}
	return t
}

func main() {
	data, _ := os.ReadFile("code.in")
	scanner := bufio.NewScanner(bytes.NewReader(data))
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &n)
	scanner.Scan()
	s = scanner.Text()
	for i := 1; i <= n; i++ {
		if s[i-1] == '+' || s[i-1] == '-' {
			f[i] = f[i-1] + (uint64(s[i-1])-43)*pow(uint64(B), int64(g[i-1]))
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (uint64(s[i-1])-60)
		}
	}
	for i := n; i > 0; i-- {
		m[f[i]]++
		cnt += m[f[n]*pow(uint64(B), int64(g[i-1]))+f[i-1]]
	}
	fmt.Println(cnt)
}

