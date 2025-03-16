package main

import (
	"fmt"
)

func main() {
	// Initialize an empty slice 'm' to store the multipliers
	m := []int{10, 50, 100, 500}

	first := true // Initialize a boolean variable 'first' to check if it's the first iteration of the loop

	// Main loop to read the input money and calculate the change
	for {
		var money int
		if _, err := fmt.Scan(&money); err != nil || money == 0 {
			break // Exit the loop if there's an error or if money is 0
		}

		// If it's not the first iteration, print a newline character to separate the outputs
		if !first {
			fmt.Println()
		}
		first = false

		// Initialize variables 'sum' and 'num'
		sum := 0
		num := make([]int, 4)

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for i := 0; i < 4; i++ {
			fmt.Scan(&num[i]) // Read the number
			sum += num[i] * m[i] // Calculate the product and add it to the sum
		}

		// Calculate the change
		change := sum - money

		// Adjust the numbers to get the exact change
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 {
				num[i] -= change / m[i]
				change %= m[i]
			}
		}

		// Print the numbers that still have a positive value
		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Printf("%d %d\n", m[i], num[i])
			}
		}
	}
}

// <END-OF-CODE>
