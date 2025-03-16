package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Start of the main function
	var n int // Declare an integer variable 'n' to store the size of the array
	var a [101]int // Declare an integer array 'a' of size 101

	fmt.Scan(&n) // Read the size of the array from the user input

	// Read each element of the array 'a' from the user input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read each element into the array
	}

	// Print the last element of the array
	fmt.Print(a[n-1])

	// Print the remaining elements of the array in reverse order
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1]) // Print the current element with a space before it
	}

	fmt.Println() // Print a newline character at the end
}

// <END-OF-CODE>
