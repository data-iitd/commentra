package main

import (
	"fmt"
)

func main() {
	var n, m, mod int
	fmt.Scan(&n, &m, &mod)

	C := make([][]int, 310)
	for i := range C {
		C[i] = make([]int, 310)
	}
	C[0][0] = 1
	for i := 1; i <= n; i++ {
		C[i][0] = C[i][i] = 1
		for j := 1; j < i; j++ {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
		}
	}

	f := make([][]int, 310)
	for i := range f {
		f[i] = make([]int, 310)
	}
	for i := 0; i <= m; i++ {
		f[1][i] = 1
	}
	pre := make([][]int, 310)
	for i := range pre {
		pre[i] = make([]int, 310)
	}
	for i := 1; i <= n; i++ {
		for j := 0; j <= m; j++ {
			for k := 1; k < i; k++ {
				f[i][j] += f[i-k][j] * pre[k][j+1] % mod * C[i-2][k-1]
				f[i][j] %= mod
			}
		}
		for j := m; j >= 0; j-- {
			pre[i][j] = (pre[i][j+1] + f[i][j]) % mod
		}
	}

	fmt.Println(f[n+1][0])
}

