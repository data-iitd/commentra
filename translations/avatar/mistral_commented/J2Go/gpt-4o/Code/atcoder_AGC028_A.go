package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Read input values for n and m
	var n, m int
	fmt.Scan(&n, &m)

	// Calculate the greatest common divisor (GCD) of n and m
	gcd := new(big.Int).GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m))).Int64()

	// Read input strings s and t
	var s, t string
	fmt.Scan(&s, &t)

	// Perform the required calculation and print the result
	result := int64(0)
	foundDifference := false

	for k := int64(0); k < gcd; k++ {
		if s[k*n/gcd] != t[k*m/gcd] {
			result = -1
			foundDifference = true
			break
		}
	}

	if !foundDifference {
		result = (int64(n) * int64(m)) / gcd
	}

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>
