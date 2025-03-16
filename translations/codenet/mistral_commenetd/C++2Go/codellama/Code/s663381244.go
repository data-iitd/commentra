package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a boolean variable 'first' to check if it's the first iteration of the loop
	first := true

	// Initialize a vector 'm' to store the multipliers
	m := []int{10, 50, 100, 500}

	// Initialize a scanner to read the input money and calculate the change
	scanner := bufio.NewScanner(os.Stdin)

	// Main loop to read the input money and calculate the change
	for scanner.Scan() {
		// If it's not the first iteration, print a newline character to separate the outputs
		if !first {
			fmt.Println()
		}

		// Set 'first' to false
		first = false

		// Initialize variables 'sum' and 'num'
		sum := 0
		num := []int{0, 0, 0, 0}

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for i := 0; i < 4; i++ {
			// Read the number
			n, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))

			// Calculate the product and add it to the sum
			sum += n * m[i]
		}

		// Calculate the change
		change := sum - money

		// Adjust the numbers to get the exact change
		for i := 3; i >= 0; i-- {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change/m[i] > 0 {
				num[i] = num[i] - change/m[i]
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

	// Return EXIT_SUCCESS to indicate successful execution
	os.Exit(0)
}

