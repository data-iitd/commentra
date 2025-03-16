package main

import (
	"fmt"
	"math/big"
	"os"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	gcd := A[0]
	for _, num := range A[1:] {
		gcd = gcdOf(gcd, num)
	}

	fmt.Println(gcd)
}

func gcdOf(a, b int) int {
	return int(big.NewInt(int64(a)).GCD(nil, nil, big.NewInt(int64(a)), big.NewInt(int64(b))).Int64())
}

// <END-OF-CODE>
