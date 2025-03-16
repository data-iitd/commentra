package main

import (
	"fmt"
)

// Define a function named 'generateString' that returns a slice of characters
// representing a string of numbers from 1 to 1000
func generateString() []rune {
	var sb []rune // Create a slice of runes

	// Use a for loop to append numbers from 1 to 1000 to the slice
	for i := 1; i <= 1000; i++ {
		sb = append(sb, []rune(fmt.Sprintf("%d", i))...) // Append the current number as a rune to the slice
	}

	// Return the slice of runes
	return sb
}

// Define the main function that reads user input and prints the result
func main() {
	var n int // Declare a variable to store user input

	// Read an integer value from the user input
	fmt.Scan(&n)

	// Print the character at the specified index of the generated string
	fmt.Print(string(generateString()[n-1]))
}

