package main

import (
	"fmt"
	"math/big"
)

func gcd(a, b *big.Int) *big.Int {
	return a.GCD(nil, nil, a, b)
}

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]*big.Int, N)
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = big.NewInt(int64(x))
	}

	var result *big.Int = A[0]
	for i := 1; i < N; i++ {
		result = gcd(result, A[i])
	}

	fmt.Println(result)
}
