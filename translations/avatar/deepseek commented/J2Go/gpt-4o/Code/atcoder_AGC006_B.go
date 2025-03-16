package main

import (
	"fmt"
)

func main() {
	var n, x int
	fmt.Scan(&n) // Read the first integer input
	fmt.Scan(&x) // Read the second integer input
	printResult(x, n) // Call the printResult function with x and n as arguments
}

// Function to print based on the value of x and n
func printResult(x, n int) {
	max := n*2 - 1 // Calculate the maximum value based on n
	if x == 1 || x == max { // Check if x is at the edges
		fmt.Println("No") // Print "No" if x is 1 or max
		return // Exit the function
	}
	fmt.Println("Yes") // Print "Yes" if x is within the valid range

	// Generate and print the required sequence
	for i := x + n - 1; i < x+n+max-1; i++ {
		fmt.Print((i%max + 1), "\n") // Print each number in the required format
	}
}

// <END-OF-CODE>
