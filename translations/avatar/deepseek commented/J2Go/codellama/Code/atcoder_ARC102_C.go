package main

import (
	"fmt"
)

const mod = 998244353
var nchoosek [4001][4001]int

func main() {
	// Initialize the nchoosek array for binomial coefficients
	for i := 0; i < len(nchoosek); i++ {
		nchoosek[i][0] = nchoosek[i][i] = 1 // nchoosek[i][0] and nchoosek[i][i] are 1
	}

	// Fill the nchoosek array using dynamic programming
	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod
		}
	}

	// Read input values k and n
	var k, n int
	fmt.Scan(&k, &n)

	// Main loop to compute and print results for each i from 2 to 2*k
	for i := 2; i <= 2*k; i++ {
		pairs := k - i / 2 // Calculate pairs based on i
		active := k - 2 * pairs // Calculate active elements
		if i % 2 == 0 {
			active -= 1 // Adjust active if i is even
		}

		times2 := 1 // Initialize times2 for calculating powers of 2
		total := 0 // Initialize total for storing the result

		// Calculate total using binomial coefficients
		for j := 0; j <= pairs; j++ {
			choice := times2 * nchoosek[pairs][j] % mod // Calculate choice
			times2 = times2 * 2 % mod // Update times2
			if active + j - 1 < 0 {
				continue // Skip if invalid
			}
			total += choice * nchoosek[n + active - 1][active + j - 1] // Add to total
			if i % 2 == 0 {
				total += choice * nchoosek[n + active - 2][active + j - 1] // Add for even i
			}
			total %= mod // Ensure total is within the modulo
		}
		fmt.Println(total) // Print the result
	}
}

