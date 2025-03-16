
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a boolean variable 'first' to check if it's the first iteration of the loop
	first := true

	// Main loop to read the input money and calculate the change
	for scanner.Scan() {
		// If it's not the first iteration, print a newline character to separate the outputs
		if!first {
			fmt.Println()
		}

		// Set 'first' to false
		first = false

		// Initialize variables'sum' and 'num'
		sum := 0
		num := make([]int, 4)

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		line := scanner.Text()
		for i, s := range strings.Fields(line) {
			n, _ := strconv.Atoi(s) // Convert the string to an integer
			sum += n * m[i] // Calculate the product and add it to the sum
			num[i] = n // Store the number in the 'num' array
		}

		// Calculate the change
		change := sum - money

		// Adjust the numbers to get the exact change
		for i := 3; i >= 0; i-- {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change/m[i] > 0 {
				num[i] = num[i] - change/m[i]
				change = change % m[i]
			}
		}

		// Print the numbers that still have a positive value
		for i, n := range num {
			if n > 0 {
				fmt.Printf("%d %d\n", m[i], n)
			}
		}
	}

	// Return EXIT_SUCCESS to indicate successful execution
	os.Exit(0)
}

