package main

import "fmt"

// Global variables
var (
	K, N int
)

// Function to calculate binomial coefficient modulo mod
func cmb(n, r, mod int) int {
	if r < 0 || r > n {
		return 0
	}
	r = min(r, n - r)
	return g1[n] * g2[r] * g2[n-r] % mod
}

// Function to calculate modular inverse
func inverse(x, mod int) int {
	return pow(x, mod-2, mod)
}

// Function to calculate modular exponentiation
func pow(x, y, mod int) int {
	res := 1
	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % mod
		}
		y >>= 1
		x = (x * x) % mod
	}
	return res
}

// Function to calculate minimum of two values
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// Function to calculate kumiawase (combination with repetition) modulo mod
func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1, mod)
}

// Function to solve the problem for a given n
func solve(n int) int {
	var ans int
	kumi := (n-1)/2
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += 1 << p * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-(kumi*2)-(n%2==0)))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += 1 << p * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-(kumi*2)-(n%2==0)))
	}
	return ans
}

func main() {
	// Reading K and N from input
	fmt.Scanf("%d %d\n", &K, &N)
	// Precompute factorials, inverses, and modular inverses up to __N
	g1 := make([]int, __N+1)
	g2 := make([]int, __N+1)
	inverse := make([]int, __N+1)
	g1[0], g1[1] = 1, 1
	g2[0], g2[1] = 1, 1
	inverse[0], inverse[1] = 0, 1
	for i := 2; i <= __N; i++ {
		g1[i] = (g1[i-1] * i) % mod
		inverse[i] = (-inverse[mod%i] * (mod/i)) % mod
		g2[i] = (g2[i-1] * inverse[i]) % mod
	}
	// Calculating results
	for i := 2; i <= 2*K; i++ {
		if i <= K+1 {
			fmt.Printf("%d\n", solve(i))
		} else {
			fmt.Printf("%d\n", solve(i-K))
	}
}

