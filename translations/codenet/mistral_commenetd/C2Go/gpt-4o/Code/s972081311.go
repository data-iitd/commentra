package main

import (
	"fmt"
)

func main() {
	// Declare variable n and sum
	var n, sum int

	fmt.Scanf("%d", &n)
	// Read an integer value from the user and store it in the variable n

	sum = (n * (n + 1)) / 2
	// Calculate the sum of the first n natural numbers
	// The formula for the sum of the first n natural numbers is n*(n+1)/2

	fmt.Printf("%d\n", sum)
	// Print the calculated sum to the standard output
}

// Indicate successful termination of the program
