package main

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	var n int // Declaring an integer variable to store the first number

	// Reading the first number from the user input
	fmt.Scan(&n)

	fmt.Println(n) // Printing the first number to the standard output stream

	m := n // Initializing an integer variable 'm' with the value of 'n'

	// Finding the factors of the number 'n' using a for loop
	for i := n - 1; i > 0; i-- {
		if m%i == 0 { // Checking if 'i' is a factor of 'm'
			fmt.Println(i) // Printing the factor to the standard output stream
			m = i // Updating the value of 'm' with the current factor
		}
	}
}

// <END-OF-CODE>
