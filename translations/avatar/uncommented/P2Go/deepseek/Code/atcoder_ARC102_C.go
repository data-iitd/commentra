package main

import (
	"fmt"
	"math"
)

const mod = 998244353

var (
	g1 = []int{1, 1}
	g2 = []int{1, 1}
	inverse = []int{0, 1}
)

func cmb(n, r, mod int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n-r)
	return g1[n] * g2[r] * g2[n-r] % mod
}

func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1, mod)
}

func solve(n, K, N int) int {
	if n > K+1 {
		return 0
	}
	ans := 0
	kumi := (n - 1) / 2
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += (1 << p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-(n%2)/2))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += (1 << p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-(n%2)/2))
		}
	}
	return ans % mod
}

func main() {
	var K, N int
	fmt.Scan(&K, &N)

	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			tmp := solve(i, K, N)
			fmt.Println(tmp)
		} else {
			fmt.Println(solve(i, K, N))
		}
	}
}
