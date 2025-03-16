package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var i, a, b, s int // Declare variables i, a, b, s of integer type
	count := make([]int, 4) // Declare a slice count of size 4 to store the count of each number

	// Initialize the count slice with zeros
	for i = 0; i < 4; i++ {
		count[i] = 0
	}

	// Read three pairs of numbers from the user and update the count slice accordingly
	for i = 0; i < 3; i++ {
		fmt.Scan(&a, &b) // Read two numbers a and b from the user
		count[a-1]++ // Increment the count of number a in the count slice
		count[b-1]++ // Increment the count of number b in the count slice
	}

	// Calculate the product of all counts in the count slice
	s = 1
	for i = 0; i < 4; i++ {
		s *= count[i]
	}

	// Check if the product of all counts is equal to 4
	if s == 4 {
		fmt.Println("YES") // If yes, print "YES" to the console
	} else {
		fmt.Println("NO") // Else, print "NO" to the console
	}
}

// <END-OF-CODE>
