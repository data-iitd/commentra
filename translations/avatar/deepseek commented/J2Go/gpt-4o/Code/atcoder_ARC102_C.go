package main

import (
	"fmt"
)

const mod = 998244353

var nchoosek [][]int64

func main() {
	// Initialize the nchoosek array for binomial coefficients
	nchoosek = make([][]int64, 4001)
	for i := range nchoosek {
		nchoosek[i] = make([]int64, 4001)
		nchoosek[i][0] = 1
		nchoosek[i][i] = 1
	}

	// Fill the nchoosek array using dynamic programming
	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % mod
		}
	}

	// Read input values k and n
	var k, n int
	fmt.Scan(&k, &n)

	// Main loop to compute and print results for each i from 2 to 2*k
	for i := 2; i <= 2*k; i++ {
		var pairs int
		if i > k {
			pairs = k - i/2 // Calculate pairs based on i
		} else {
			pairs = (i - 1) / 2 // Calculate pairs based on i
		}
		active := k - 2*pairs // Calculate active elements
		if i%2 == 0 {
			active -= 1 // Adjust active if i is even
		}

		times2 := int64(1) // Initialize times2 for calculating powers of 2
		total := int64(0)  // Initialize total for storing the result

		// Calculate total using binomial coefficients
		for j := 0; j <= pairs; j++ {
			choice := times2 * nchoosek[pairs][j] % mod // Calculate choice
			times2 = times2 * 2 % mod                   // Update times2
			if active+j-1 < 0 {
				continue // Skip if invalid
			}
			total = (total + choice*nchoosek[n+active-1][active+j-1]) % mod // Add to total
			if i%2 == 0 {
				total = (total + choice*nchoosek[n+active-2][active+j-1]) % mod // Add for even i
			}
		}
		fmt.Println(total) // Print the result
	}
}

// <END-OF-CODE>
