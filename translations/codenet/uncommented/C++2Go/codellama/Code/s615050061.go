//package main

import (
	"fmt"
	"math"
)

const (
	B = 13131
	N = 500000 + 7
)

var (
	n int
	s []byte
	f []uint64
	g []int
	map map[uint64]uint64
	cnt uint64
)

func pow(a, k uint64) uint64 {
	if k < 0 {
		k += math.MaxUint64
	}
	t := uint64(1)
	for ; k > 0; a *= a, k >>= 1 {
		if k&1 == 1 {
			t *= a
		}
	}
	return t
}

func main() {
	fmt.Scan(&n, &s)
	f = make([]uint64, n+1)
	g = make([]int, n+1)
	map = make(map[uint64]uint64)
	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + (s[i] == '+' ? 1 : -1) * pow(uint64(g[i-1]), uint64(g[i]))
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (s[i] == '<' ? -1 : 1)
		}
	}
	for i := n; i > 0; i-- {
		cnt += map[f[n]*pow(uint64(g[i-1]), uint64(g[i]))+f[i-1]]
		map[f[i]]++
	}
	fmt.Println(cnt)
}

