package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N)

	var A []int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A = append(A, x)
	}

	gcd := A[0]
	for _, v := range A[1:] {
		gcd = gcdBig(gcd, v)
	}

	fmt.Println(gcd)
}

func gcdBig(a, b int) *big.Int {
	return new(big.Int).GCD(nil, nil, big.NewInt(int64(a)), big.NewInt(int64(b)))
}

