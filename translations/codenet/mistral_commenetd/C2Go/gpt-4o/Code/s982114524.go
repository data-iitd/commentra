package main

import (
	"fmt"
)

func main() {
	var i, N, x int // Declare and initialize three integer variables: i, N, and x
	x = 0          // Initialize x to 0

	// Prompt the user to enter a number
	fmt.Print("Enter a number: ")
	fmt.Scan(&N)

	// Use a for loop to iterate from 1 to N and sum up the numbers
	for i = 1; i <= N; i++ {
		x += i // Add the current value of i to x
	}

	// Print the sum of the numbers to the console
	fmt.Printf("The sum of numbers from 1 to %d is: %d\n", N, x)

	// Return 0 upon successful execution
}

// <END-OF-CODE>
