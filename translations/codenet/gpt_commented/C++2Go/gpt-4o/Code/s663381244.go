package main

import (
	"fmt"
)

func main() {
	// Initialize a slice to hold the denominations of money
	m := []int{10, 50, 100, 500}

	first := true // Flag to handle formatting of output

	// Read money input until EOF or invalid input
	for {
		var money int
		if _, err := fmt.Scan(&money); err != nil {
			break // Exit the loop on EOF or invalid input
		}

		// Print a newline before the output of subsequent transactions
		if !first {
			fmt.Println()
		}
		first = false // Set the flag to false after the first input

		sum := 0 // Initialize sum to calculate total value of coins
		num := make([]int, 4) // Slice to hold the number of each denomination

		// Read the number of coins for each denomination and calculate the total sum
		for i := 0; i < 4; i++ {
			fmt.Scan(&num[i]) // Input the number of coins for the current denomination
			sum += num[i] * m[i] // Update the total sum
		}

		// Calculate the change to be returned
		change := sum - money

		// Calculate how many coins of each denomination to return as change
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 { // Check if the current denomination can be used for change
				num[i] -= change / m[i] // Reduce the number of coins of this denomination
				change %= m[i] // Update the remaining change to be returned
			}
		}

		// Output the remaining coins of each denomination that are greater than zero
		for i := 0; i < 4; i++ {
			if num[i] > 0 { // Only print denominations that still have coins left
				fmt.Println(m[i], num[i]) // Print denomination and count
			}
		}
	}
}

// <END-OF-CODE>
