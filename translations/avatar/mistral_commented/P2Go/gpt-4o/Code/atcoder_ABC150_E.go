package main

import (
	"fmt"
	"math"
)

const mod = 1000000007

func main() {
	var n int
	fmt.Scan(&n)

	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}

	// Sort the slice in descending order
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if c[i] < c[j] {
				c[i], c[j] = c[j], c[i]
			}
		}
	}

	// Calculate b as 2^(2*n-2) % mod
	b := int(math.Pow(2, float64(2*n-2))) % mod

	// Calculate a as 2*b % mod
	a := (2 * b) % mod

	ans := 0

	// Iterate through each index i from 0 to n-1 in the list c
	for i := 0; i < n; i++ {
		// Add the product of the current element c[i] and the sum of a and i*b to ans
		ans = (ans + c[i]*(a+i*b)) % mod
	}

	// Print the value of ans as the output
	fmt.Println(ans)
}

// <END-OF-CODE>
