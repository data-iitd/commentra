package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the binomial coefficient C(n, m)
func C(n, m int) *big.Int {
	res := big.NewInt(1) // Initialize result as 1
	// Calculate the numerator part of the binomial coefficient
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(int64(i))) // Multiply by i from (m-n+1) to m
	}

	// Calculate the denominator part of the binomial coefficient
	for i := 1; i <= n; i++ {
		res.Div(res, big.NewInt(int64(i))) // Divide by i from 1 to n
	}

	return res // Return the computed binomial coefficient
}

func main() {
	var n, p int // Declare variables for number of elements and parity
	k0, k1 := 0, 0 // Counters for even and odd numbers

	// Read the number of elements and the parity value
	fmt.Scan(&n, &p)

	// Count the number of even and odd integers
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x) // Read the next integer
		if x%2 == 1 {
			k1++ // Increment odd counter
		} else {
			k0++ // Increment even counter
		}
	}

	ans := big.NewInt(1) // Initialize the answer as 1

	// Multiply the answer by 2 raised to the power of the number of even integers
	for i := 0; i < k0; i++ {
		ans.Mul(ans, big.NewInt(2)) // Each even number contributes a factor of 2
	}

	if p == 0 { // If p is 0, calculate combinations for even selections of odd integers
		add := big.NewInt(0) // Initialize the sum for combinations
		// Sum the combinations of choosing even numbers of odd integers
		for i := 0; i <= k1; i += 2 {
			add.Add(add, C(i, k1)) // Add C(i, k1) for even i
		}
		ans.Mul(ans, add) // Multiply the answer by the computed combinations
		fmt.Println(ans) // Output the final answer
	} else { // If p is 1, calculate combinations for odd selections of odd integers
		add := big.NewInt(0) // Initialize the sum for combinations
		// Sum the combinations of choosing odd numbers of odd integers
		for i := 1; i <= k1; i += 2 {
			add.Add(add, C(i, k1)) // Add C(i, k1) for odd i
		}
		ans.Mul(ans, add) // Multiply the answer by the computed combinations
		fmt.Println(ans) // Output the final answer
	}
}

// <END-OF-CODE>
