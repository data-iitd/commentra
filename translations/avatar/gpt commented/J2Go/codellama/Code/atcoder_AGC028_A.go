package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Read two integers n and m from input
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])

	// Calculate the greatest common divisor (gcd) of n and m
	gcd := big.NewInt(int64(n)).GCD(nil, nil, big.NewInt(int64(m))).Int64()

	// Read two strings s and t from input
	s := os.Args[3]
	t := os.Args[4]

	// Check for mismatches in the characters of the two strings based on the gcd
	// If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
	for i := 0; i < int(gcd); i++ {
		if s[i*n/gcd] != t[i*m/gcd] {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(big.NewInt(int64(n)).Mul(big.NewInt(int64(n)), big.NewInt(int64(m))).Div(big.NewInt(int64(n)).Mul(big.NewInt(int64(n)), big.NewInt(int64(m))), big.NewInt(int64(gcd))).Int64())
}

