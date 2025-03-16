package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1000000007

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of integers
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}

	// Sort the list in descending order
	sort.Slice(c, func(i, j int) bool {
		return c[i] > c[j]
	})

	// Calculate the value of b as 2^(2*n - 2) modulo mod
	b := pow(2, 2*n-2, mod)

	// Calculate the value of a as 2 * b modulo mod
	a := (2 * b) % mod

	// Initialize the answer variable
	ans := 0

	// Iterate through the sorted list and calculate the answer
	for i := 0; i < n; i++ {
		// Update the answer by adding the product of the current element and (a + i * b)
		ans = (ans + c[i]*(a+(i*b)%mod)) % mod
	}

	// Print the final result
	fmt.Println(ans)
}

// pow function to calculate (base^exp) % mod
func pow(base, exp, mod int) int {
	result := 1
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}

// <END-OF-CODE>
