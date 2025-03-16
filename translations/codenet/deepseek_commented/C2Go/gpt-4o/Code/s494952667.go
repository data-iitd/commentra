package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
	"strings" // Import the strings package for string manipulation
)

func main() {
	var str string // Declare a variable to store the input string

	fmt.Scan(&str) // Read a string from the user

	// Reverse the string and print it
	for i := len(str) - 1; i >= 0; i-- {
		fmt.Print(string(str[i])) // Print each character in reverse order
	}
	fmt.Println() // Print a newline character at the end
}

// <END-OF-CODE>
