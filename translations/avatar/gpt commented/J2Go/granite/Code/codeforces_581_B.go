
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize an array to hold the input values
	a := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	// Initialize a dp array to store the maximum values
	dp := make([]int, n+1)

	// Fill the dp array with -1 to indicate uninitialized values
	for i := 0; i < n+1; i++ {
		dp[i] = -1
	}

	// Set the last element of dp to the last element of a
	dp[n-1] = a[n-1]

	// Fill the dp array with the maximum values from the end to the beginning
	for i := n - 1; i >= 0; i-- {
		if dp[i+1] > a[i] {
			dp[i] = dp[i+1]
		} else {
			dp[i] = a[i]
		}
	}

	// Iterate through the original array to calculate the output
	for i := 0; i < n; i++ {
		// If the current element is greater than the next maximum, print 0
		if a[i] > dp[i+1] {
			fmt.Print(0 + " ")
		} else {
			// Otherwise, calculate and print the difference to the next maximum
			fmt.Print((dp[i+1] - a[i] + 1) + " ")
		}
	}

	// Print a new line after all outputs
	fmt.Println()
}

// Debugging utility to print objects
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// End of code