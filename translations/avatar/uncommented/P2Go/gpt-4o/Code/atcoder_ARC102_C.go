package main

import (
	"fmt"
)

const mod = 998244353
const __N = 8000

var g1, g2, inverse []int

func init() {
	g1 = make([]int, __N+1)
	g2 = make([]int, __N+1)
	inverse = make([]int, __N+1)

	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inverse[0], inverse[1] = 0, 1

	for i := 2; i <= __N; i++ {
		g1[i] = (g1[i-1] * i) % mod
		inverse[i] = (-inverse[mod%i] * (mod / i)) % mod
		if inverse[i] < 0 {
			inverse[i] += mod
		}
		g2[i] = (g2[i-1] * inverse[i]) % mod
	}
}

func cmb(n, r int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n-r)
	return (g1[n] * g2[r] % mod * g2[n-r] % mod) % mod
}

func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1)
}

func solve(n, K int) int {
	if n > K+1 {
		panic("n should be less than or equal to K + 1")
	}
	ans := 0
	kumi := (n - 1) / 2
	for p := 0; p <= kumi; p++ {
		if p > __N {
			break
		}
		ans = (ans + (pow(2, p) * cmb(kumi, p) % mod * kumiawase(N-p, p+(K-kumi*2-int(n%2 == 0))) % mod) % mod) % mod) % mod
		if n%2 == 0 && N-p-1 >= 0 {
			ans = (ans + (pow(2, p) * cmb(kumi, p) % mod * kumiawase(N-p-1, p+(K-kumi*2-int(n%2 == 0))) % mod) % mod) % mod) % mod
		}
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(base, exp int) int {
	result := 1
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exp /= 2
	}
	return result
}

func main() {
	var K, N int
	fmt.Scan(&K, &N)

	ans := make([]int, 0)
	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			tmp := solve(i, K) % mod
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[K-i])
		}
	}
}

// <END-OF-CODE>
