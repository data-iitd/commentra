// Package main is the entry point of the program
package main

// Import the fmt package for input and output operations
import "fmt"

// Main function is the entry point of the program
func main() {
	// Declare variables for test cases, two integers, and a flag
	var tc, n, m, fl int

	// Read the number of test cases, and two integers n and m
	fmt.Scan(&tc, &n, &m)

	// Ensure n is the smaller of the two integers
	if n > m {
		n, m = m, n
	}

	// Loop through the range from 1 to m
	for i := 1; i <= m; i++ {
		// Check if the current value multiplied by tc is within the range [n, m]
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK") // Print "OK" if the condition is satisfied
			fl = 1             // Set the flag to indicate success
			break              // Exit the loop as we found a valid case
		}
	}

	// If no valid case was found, print "NG"
	if fl == 0 {
		fmt.Println("NG")
	}
}

