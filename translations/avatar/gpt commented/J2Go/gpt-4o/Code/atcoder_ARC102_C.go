package main

import (
	"fmt"
)

const mod = 998244353

var nchoosek [][]int64

func main() {
	// Initialize the nchoosek array to store binomial coefficients up to 4000
	nchoosek = make([][]int64, 4001)
	for i := range nchoosek {
		nchoosek[i] = make([]int64, 4001)
	}

	// Set base cases for binomial coefficients: C(n, 0) = C(n, n) = 1
	for i := 0; i < len(nchoosek); i++ {
		nchoosek[i][0] = 1
		nchoosek[i][i] = 1
	}

	// Compute binomial coefficients using dynamic programming
	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			// C(i, j) = C(i-1, j) + C(i-1, j-1)
			nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % mod
		}
	}

	var k, n int
	fmt.Scan(&k, &n)

	// Iterate through the range of 2 to 2*k
	for i := 2; i <= 2*k; i++ {
		var pairs int
		// Calculate the number of pairs based on the current index i
		if i > k {
			pairs = k - i/2 // More pairs than k
		} else {
			pairs = (i - 1) / 2 // Fewer pairs than k
		}

		// Calculate the number of active elements remaining
		active := k - 2*pairs
		if i%2 == 0 {
			active -= 1 // Adjust active count for even i
		}

		times2 := int64(1) // Initialize multiplier for choices
		total := int64(0)  // Initialize total count

		// Calculate total combinations for the current number of pairs
		for j := 0; j <= pairs; j++ {
			// Calculate the number of ways to choose j pairs
			choice := times2 * nchoosek[pairs][j] % mod
			times2 = times2 * 2 % mod // Update multiplier for the next iteration

			// Skip if there are not enough active elements
			if active+j-1 < 0 {
				continue
			}

			// Add combinations to the total based on active elements
			total = (total + choice*nchoosek[n+active-1][active+j-1]) % mod

			// If i is even, add additional combinations
			if i%2 == 0 {
				total = (total + choice*nchoosek[n+active-2][active+j-1]) % mod
			}
		}

		// Output the total combinations for the current i
		fmt.Println(total)
	}
}

// <END-OF-CODE>
