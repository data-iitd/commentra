package main

import (
	"fmt"
	"math/big"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * (b / gcd(a, b))
}

func main() {
	const MOD = 1_000_000_007
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	_lcm := 1
	for _, a := range A {
		_lcm = lcm(_lcm, a)
	}

	sum := 0
	for _, s := range A {
		inv := new(big.Int).ModInverse(big.NewInt(int64(s)), big.NewInt(MOD))
		sum = (sum + int(inv.Int64())) % MOD
	}

	ans := (_lcm * sum) % MOD
	fmt.Println(ans)
}

// <END-OF-CODE>
