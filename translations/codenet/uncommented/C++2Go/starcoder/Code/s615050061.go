package main

import (
	"fmt"
	"math/big"
	"sort"
)

const B = 13131

func main() {
	var n int
	var s string
	fmt.Scanf("%d%s", &n, &s)
	f := make([]int, n+1)
	g := make([]int, n+1)
	f[0] = 0
	g[0] = 0
	for i := 1; i <= n; i++ {
		if s[i] == '+' {
			f[i] = f[i-1] + 1
			g[i] = g[i-1]
		} else if s[i] == '-' {
			f[i] = f[i-1] - 1
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + 1
		}
	}
	cnt := 0
	m := make(map[int]int)
	for i := 1; i <= n; i++ {
		m[f[i]]++
	}
	for i := 1; i <= n; i++ {
		cnt += m[f[n]*pow(B, g[i-1])+f[i-1]]
	}
	fmt.Println(cnt)
}

func pow(a, k int) int {
	if k < 0 {
		k += (1 << 63) - 1
	}
	t := big.NewInt(1)
	for ; k > 0; a, k = a*a, k>>1 {
		if k&1 == 1 {
			t.Mul(t, big.NewInt(int64(a)))
		}
	}
	return int(t.Int64())
}

