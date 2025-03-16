package main

import "fmt"

func main() {
	var K, N int
	fmt.Scanf("%d %d", &K, &N)
	var ans []int
	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			tmp := solve(i)
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[i-K-1])
		}
	}
}

func solve(n int) int {
	if n <= K+1 {
		var ans int
		kumi := (n - 1) / 2
		for p := 0; p <= kumi; p++ {
			if p > N {
				break
			}
			ans += 1 << p * cmb(kumi, p, 998244353) * kumiawase(N-p, p+(K-kumi*2-n%2))
			if n%2 == 0 && N-p-1 >= 0 {
				ans += 1 << p * cmb(kumi, p, 998244353) * kumiawase(N-p-1, p+(K-kumi*2-n%2))
			}
		}
		return ans % 998244353
	}
	return ans[n-K-1]
}

func cmb(n, r, mod int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n-r)
	return g1[n] * g2[r] * g2[n-r] % mod
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var g1, g2, inverse []int

func init() {
	g1 = make([]int, 8000+1)
	g2 = make([]int, 8000+1)
	inverse = make([]int, 8000+1)
	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inverse[0], inverse[1] = 0, 1
	for i := 2; i <= 8000; i++ {
		g1[i] = g1[i-1]*i % 998244353
		inverse[i] = -inverse[i-1]*(i-1)%998244353 + 998244353
		g2[i] = g2[i-1]*inverse[i] % 998244353
}

