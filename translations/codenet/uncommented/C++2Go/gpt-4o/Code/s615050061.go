package main

import (
	"fmt"
)

const (
	B = 13131
	N = 500000 + 7
)

var (
	n   int
	s   [N]rune
	f   [N]uint64
	g   [N]int
	m   = make(map[uint64]uint64)
	cnt uint64
)

func pow(a, k uint64) uint64 {
	if k < 0 {
		k += (1 << 63) - 1
	}
	t := uint64(1)
	for k > 0 {
		if k&1 == 1 {
			t *= a
		}
		a *= a
		k >>= 1
	}
	return t
}

func main() {
	// Uncomment the following lines to read from input files
	// file, _ := os.Open("code.in")
	// defer file.Close()
	// reader := bufio.NewReader(file)

	fmt.Scanf("%d\n", &n)
	fmt.Scanf("%s", &s[1])

	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			if s[i] == '+' {
				f[i] = f[i-1] + pow(B, uint64(g[i-1]))
			} else {
				f[i] = f[i-1] - pow(B, uint64(g[i-1]))
			}
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			if s[i] == '<' {
				g[i] = g[i-1] - 1
			} else {
				g[i] = g[i-1] + 1
			}
		}
	}

	for i := n; i > 0; i-- {
		m[f[i]]++
		cnt += m[f[n]*pow(B, uint64(g[i-1]))+f[i-1]]
	}

	fmt.Println(cnt)
}

// <END-OF-CODE>
