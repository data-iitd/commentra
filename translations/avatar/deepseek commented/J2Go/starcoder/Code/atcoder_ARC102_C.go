package main

import "fmt"

func main() {
	// Initialize the nchoosek array for binomial coefficients
	nchoosek := make([][]int, 4001)
	for i := range nchoosek {
		nchoosek[i] = make([]int, 4001)
		for j := range nchoosek[i] {
			nchoosek[i][j] = 1
		}
	}

	// Fill the nchoosek array using dynamic programming
	for i := 2; i < len(nchoosek); i++ {
		for j := 1; j < i; j++ {
			nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % 998244353
		}
	}

	// Read input values k and n
	var k, n int
	fmt.Scanf("%d %d\n", &k, &n)

	// Main loop to compute and print results for each i from 2 to 2*k
	for i := 2; i <= 2*k; i++ {
		var pairs int
		if i > k {
			pairs = k - i/2 // Calculate pairs based on i
		} else {
			pairs = (i-1)/2 // Calculate pairs based on i
		}
		active := k - 2*pairs // Calculate active elements
		if i%2 == 0 {
			active -= 1 // Adjust active if i is even
		}

		times2 := 1 // Initialize times2 for calculating powers of 2
		total := 0 // Initialize total for storing the result

		// Calculate total using binomial coefficients
		for j := 0; j <= pairs; j++ {
			choice := times2 * nchoosek[pairs][j] % 998244353 // Calculate choice
			times2 = times2 * 2 % 998244353 // Update times2
			if active+j-1 < 0 {
				continue
			} // Skip if invalid
			total += choice * nchoosek[n+active-1][active+j-1] // Add to total
			if i%2 == 0 {
				total += choice * nchoosek[n+active-2][active+j-1] // Add for even i
			}
			total %= 998244353 // Ensure total is within the modulo
		}
		fmt.Println(total) // Print the result
	}
}

