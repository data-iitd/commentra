package main

import (
	"fmt"
)

const MOD = 1e9 + 7

// Function to calculate a^n
func pow(a, n int) int {
	res := 1
	for n > 0 {
		if n & 1 == 1 {
			res *= a
		}
		a *= a
		n >>= 1
	}
	return res
}

// Function to calculate a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1
	for n > 0 {
		if n & 1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		n >>= 1
	}
	return res
}

// Function to calculate a^(-1) % mod (only if a % mod != 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod - 2, mod)
}

// Function to calculate nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p := 1
	q := 1
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % mod
	}
	for i := 2; i <= k; i++ {
		q = (q * i) % mod
	}
	q = mod_inv(q, mod)
	return (p * q) % mod
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	fmt.Println(mod_nCk(k, n, MOD))
}

