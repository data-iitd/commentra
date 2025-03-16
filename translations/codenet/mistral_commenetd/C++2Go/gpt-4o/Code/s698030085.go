package main // We declare the main package

import (
	"fmt" // We import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var a, b int64 // We declare two int64 variables named a and b to store user input

	// We use fmt.Scan to read user input and store it in variables a and b
	fmt.Scan(&a, &b)

	if (a+b)%2 == 0 { // We check if the sum of a and b is even
		// If the sum is even, we print the result by dividing it by 2
		fmt.Println((a + b) / 2)
	} else { // If the sum is odd, we print "IMPOSSIBLE"
		fmt.Println("IMPOSSIBLE")
	}
}

// <END-OF-CODE>
