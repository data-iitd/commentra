package main

import (
	"fmt"
	"math"
)

func main() {
	var K, N int
	fmt.Scan(&K, &N)
	dprint := func(x ...interface{}) {
		fmt.Println(x...)
	}
	cmb := func(n, r, mod int) int {
		if r < 0 || r > n {
			return 0
		}
		r = int(math.Min(float64(r), float64(n-r)))
		return g1[n] * g2[r] * g2[n-r] % mod
	}
	mod := 998244353
	__N := 8000
	g1 := []int{1, 1}
	g2 := []int{1, 1}
	inverse := []int{0, 1}
	for i := 2; i <= __N+1; i++ {
		g1 = append(g1, (g1[len(g1)-1]*i)%mod)
		inverse = append(inverse, (-inverse[mod%i]*(mod/i))%mod)
		g2 = append(g2, (g2[len(g2)-1]*inverse[len(inverse)-1])%mod)
	}
	kumiawase := func(p, q int) int {
		return cmb(p+q-1, q-1, mod)
	}
	solve := func(n int) int {
		assert(n <= K+1)
		ans := 0
		kumi := (n - 1) / 2
		for p := 1; p <= kumi+1; p++ {
			if p > N {
				break
			}
			ans += 2**p * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-int(n%2 == 0)))
			if n%2 == 0 && N-p-1 >= 0 {
				ans += 2**p * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-int(n%2 == 0)))
			}
		}
		return ans
	}
	ans := []int{}
	for i := 2; i <= 2*K+1; i++ {
		if i <= K+1 {
			tmp := solve(i) % 998244353
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[len(ans)-i+K])
		}
	}
}

