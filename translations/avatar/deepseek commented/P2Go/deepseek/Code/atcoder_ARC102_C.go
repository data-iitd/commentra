package main

import (
	"fmt"
)

const mod = 998244353
const __N = 8000

var g1 = []int{1, 1}
var g2 = []int{1, 1}
var inverse = []int{0, 1}

// Combination function to calculate binomial coefficient modulo mod
func cmb(n, r, mod int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n-r)
	return g1[n] * g2[r] * g2[n-r] % mod
}

// Function to calculate kumiawase (combination with repetition) modulo mod
func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1, mod)
}

// Function to solve the problem for a given n
func solve(n int) int {
	if n > K {
		return 0
	}
	ans := 0
	kumi := (n - 1) / 2
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += pow(2, p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-(n%2)))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += pow(2, p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-(n%2)))
		}
	}
	return ans % mod
}

// Precompute factorials, inverses, and modular inverses up to __N
func precompute() {
	for i := 2; i <= __N; i++ {
		g1 = append(g1, (g1[len(g1)-1]*i)%mod)
		inverse = append(inverse, (-inverse[mod%i]*int(mod/i))%mod)
		g2 = append(g2, (g2[len(g2)-1]*inverse[len(inverse)-1])%mod)
	}
}

// Power function to calculate x^y mod p
func pow(x, y, p int) int {
	res := 1
	x = x % p
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}
	return res
}

var K, N int

func main() {
	fmt.Scan(&K, &N)
	precompute()
	ans := []int{}
	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			tmp := solve(i) % mod
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[i-K-1])
		}
	}
}
