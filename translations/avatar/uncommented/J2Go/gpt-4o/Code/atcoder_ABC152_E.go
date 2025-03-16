package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	lcm := big.NewInt(1)
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm = lcm.Div(lcm, gcd(lcm, a)).Mul(lcm, a)
	}

	mod := int64(1000000007)
	modLcm := new(big.Int).Mod(lcm, big.NewInt(mod)).Int64()
	ans := int64(0)
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}
	fmt.Println(ans)
}

func gcd(a, b *big.Int) *big.Int {
	return new(big.Int).GCD(nil, nil, a, b)
}

func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod
	for y := e; y != 0; y >>= 1 {
		if (y & 1) == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

// <END-OF-CODE>
