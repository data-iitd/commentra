package main

import (
	"fmt"
	"math/big"
)

// Define a function to calculate the least common multiple (LCM) of two numbers
func lcm(a, b int) int {
	return int(new(big.Int).Mul(big.NewInt(int64(a)), big.NewInt(int64(b))).Div(new(big.Int).GCD(nil, nil, big.NewInt(int64(a)), big.NewInt(int64(b))), big.NewInt(int64(a))).Int64())
}

const MOD = 1e9 + 7

func main() {
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

	ans := _lcm
	for _, a := range A {
		ans = ans * pow(a, MOD-2, MOD) % MOD
	}

	fmt.Println(ans)
}

// Define a function to calculate the modular inverse of a number
func pow(a, b, m int) int {
	a %= m
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = res * a % m
		}
		a = a * a % m
		b >>= 1
	}
	return res
}

