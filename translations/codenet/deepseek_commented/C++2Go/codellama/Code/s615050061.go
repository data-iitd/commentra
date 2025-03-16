package main

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
	m map[uint64]uint64
	c uint64
)

func pow(a, k uint64) uint64 {
	if k < 0 {
		k += math.MaxUint64 - 1
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
	m = make(map[uint64]uint64)
	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i-1])
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (s[i] == '<' ? -1 : 1)
		}
	}
	for i := n; i > 0; i-- {
		m[f[i]]++
		c += m[f[n]*pow(B, g[i-1])+f[i-1]]
	}
	fmt.Println(c)
}

