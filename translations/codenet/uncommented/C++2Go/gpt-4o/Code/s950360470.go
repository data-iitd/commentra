package main

import (
	"fmt"
)

const MOD = 1e9 + 7 // 1000000007

// pow calculates a^n
func pow(a, n int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res *= a
		}
		a *= a
		n >>= 1
	}
	return res
}

// modPow calculates a^n % mod
func modPow(a, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		n >>= 1
	}
	return res
}

// modInv calculates a^(-1) % mod (only if a % p != 0)
func modInv(a, mod int64) int64 {
	return modPow(a, mod-2, mod)
}

// modNCK calculates nCk % mod
func modNCK(n, k int64, mod int64) int64 {
	if n == 0 || k == 0 {
		return 1
	}
	p := int64(1)
	q := int64(1)
	for i := n - k + 1; i <= n; i++ {
		p = (p * i) % mod
	}
	for i := int64(2); i <= k; i++ {
		q = (q * i) % mod
	}
	q = modInv(q, mod)
	return (p * q) % mod
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	fmt.Println(modNCK(k, n, MOD))
}

// <END-OF-CODE>
