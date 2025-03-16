package main

import (
	"fmt"
)

const MOD = 1e9 + 7

// a^n
func pow(a, n int) int {
	res := 1
	for n > 0 {
		if n&1 != 0 {
			res *= a
		}
		a *= a
		n >>= 1
	}
	return res
}

// a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 != 0 {
			res = res * a % mod
		}
		a = a * a % mod
		n >>= 1
	}
	return res
}

// a^(-1) % mod (only if : a % p != 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod)
}

// nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 {
		return 1
	}
	p := 1
	q := 1
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % MOD
	}
	for i := 2; i <= k; i++ {
		q = (q * i) % MOD
	}
	q = mod_inv(q, MOD)
	return (p * q) % MOD
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	fmt.Println(mod_nCk(k, n, MOD))
}

