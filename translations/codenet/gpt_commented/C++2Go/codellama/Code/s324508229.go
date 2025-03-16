package main

import (
	"fmt"
)

func main() {
	var n, ii, a, b int // Declare variables for input and indices
	fmt.Scan(&n) // Read the upper limit of the range

	// Initialize a 2D array to count occurrences of digit pairs
	cnt := make([][]int, 100)
	for i := 0; i < 100; i++ {
		cnt[i] = make([]int, 100)
	}
	for i := 0; i < 100; i++ {
		for j := 0; j < 100; j++ {
			cnt[i][j] = 0 // Set all counts to zero
		}
	}

	// Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
	for i := 1; i <= n; i++ {
		b = i % 10 // Get the last digit of the number
		a = i // Store the original number
		for a >= 10 { // Extract the first digit
			a /= 10 // Divide by 10 until we get the first digit
		}
		cnt[a][b]++ // Increment the count for the pair (first digit, last digit)
	}

	ans := 0 // Initialize the answer variable to accumulate results

	// Calculate the total number of valid pairs by multiplying counts
	for i := 1; i <= 9; i++ { // Iterate over possible first digits
		for j := 1; j <= 9; j++ { // Iterate over possible last digits
			// Uncomment the following line for debugging to see counts
			// fmt.Println(i, j, cnt[i][j], cnt[j][i])
			ans += cnt[i][j] * cnt[j][i] // Add the product of counts for pairs (i, j) and (j, i)
		}
	}

	fmt.Println(ans) // Output the final result
}

