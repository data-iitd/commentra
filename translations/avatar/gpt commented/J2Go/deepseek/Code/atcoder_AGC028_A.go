package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Create a scanner object for input
	var n, m int
	fmt.Scan(&n, &m)
	
	// Calculate the greatest common divisor (gcd) of n and m
	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()
	
	// Read two strings s and t from input
	var s, t string
	fmt.Scan(&s, &t)
	
	// Check for mismatches in the characters of the two strings based on the gcd
	// If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
	var lcm int64 = int64(n) * int64(m) / gcd
	foundMismatch := false
	for k := 0; k < int(gcd); k++ {
		if s[k*n/int(gcd)] != t[k*m/int(gcd)] {
			fmt.Println(-1)
			foundMismatch = true
			break
		}
	}
	if !foundMismatch {
		fmt.Println(lcm)
	}
}
