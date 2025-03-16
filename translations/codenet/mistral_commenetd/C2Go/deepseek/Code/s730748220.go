package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var i, j, k, n int

	fmt.Print("Enter the value of n: ")
	fmt.Scan(&n) // Read an integer value from the user and store it in variable n

	// Calculate and print the result
	fmt.Printf("The result is: %d\n", 24+(24-n))
}

