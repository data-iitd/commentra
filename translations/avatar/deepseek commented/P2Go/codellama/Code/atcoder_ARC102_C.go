package main

import (
	"fmt"
	"math"
)

func main() {
	var K, N int
	fmt.Scan(&K, &N)
	// fmt.Println(K, N)

	// Combination function to calculate binomial coefficient modulo mod
	func cmb(n, r, mod int) int {
		if r < 0 || r > n {
			return 0
		}
		r = int(math.Min(float64(r), float64(n-r)))
		return g1[n] * g2[r] * g2[n-r] % mod
	}

	mod := 998244353 // Modulo value
	__N := 8000 // Constant value
	g1 := []int{1, 1} // List to store factorials
	g2 := []int{1, 1} // List to store inverse factorials
	inverse := []int{0, 1} // List to store modular inverses

	// Precompute factorials, inverses, and modular inverses up to __N
	for i := 2; i <= __N; i++ {
		g1 = append(g1, (g1[i-1] * i) % mod)
		inverse = append(inverse, (-inverse[mod % i] * (mod / i)) % mod)
		g2 = append(g2, (g2[i-1] * inverse[i-1]) % mod)
	}

	// Function to calculate kumiawase (combination with repetition) modulo mod
	func kumiawase(p, q int) int {
		return cmb(p + q - 1, q - 1, mod)
	}

	// Function to solve the problem for a given n
	func solve(n int) int {
		assert(n <= K + 1)
		ans := 0
		kumi := (n - 1) / 2
		for p := 0; p <= kumi; p++ {
			if p > N {
				break
			}
			ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi*2 - int(n % 2 == 0)))
			if n % 2 == 0 && N - p - 1 >= 0 {
				ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi*2 - int(n % 2 == 0)))
			}
		}
		return ans
	}

	ans := []int{} // List to store results
	for i := 2; i <= 2*K+1; i++ {
		if i <= K+1 {
			tmp := solve(i) % 998244353
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[i-K-2])
		}
	}
}

