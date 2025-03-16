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
	result := int64(len(s) * len(t) / int(gcd))
	for k := 0; k < int(gcd); k++ {
		if s[k*n/int(gcd)] != t[k*m/int(gcd)] {
			result = -1
			break
		}
	}

	// Print the result
	fmt.Println(result)
}
