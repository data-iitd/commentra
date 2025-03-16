package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Reading the first and second integers

	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))) // Calculating the GCD of n and m
	var s, t string
	fmt.Scan(&s, &t) // Reading the first and second strings

	// Filtering the range of the GCD and checking character mismatches
	for k := 0; k < int(gcd.Int64()); k++ {
		if s[k*n/int(gcd.Int64())] != t[k*m/int(gcd.Int64())] {
			fmt.Println(-1) // If there's a mismatch, print -1
			return
		}
	}

	// Calculating and printing the result
	result := new(big.Int).Mul(big.NewInt(int64(n)), big.NewInt(int64(m)))
	result.Div(result, gcd)
	fmt.Println(result)
}

// <END-OF-CODE>
