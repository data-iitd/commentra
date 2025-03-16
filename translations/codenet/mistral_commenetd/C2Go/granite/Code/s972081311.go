
package main

import "fmt"
// Import the standard input/output library

func main() {
	// Declare variables n and sum
	var n, sum int

	fmt.Scan(&n)
	// Read an integer value from the user and store it in the variable n

	sum = n * (n + 1) / 2
	// Calculate the sum of the first n natural numbers
	// The formula for the sum of the first n natural numbers is n*(n+1)/2

	fmt.Println(sum)
	// Print the calculated sum to the standard output

	return
	// Indicate successful termination of the program
}

// 