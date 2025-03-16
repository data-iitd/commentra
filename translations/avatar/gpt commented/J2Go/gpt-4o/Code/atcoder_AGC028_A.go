package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Calculate the greatest common divisor (gcd) of n and m
	gcd := gcd(n, m)

	var s, t string
	fmt.Scan(&s, &t)

	// Check for mismatches in the characters of the two strings based on the gcd
	for k := 0; k < gcd; k++ {
		if s[k*n/gcd] != t[k*m/gcd] {
			fmt.Println(-1) // Return -1 for mismatches
			return
		}
	}

	// Calculate least common multiple (lcm) if no mismatch
	lcm := (n * m) / gcd
	fmt.Println(lcm)
}

// Function to calculate gcd using the Euclidean algorithm
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
