package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var str string // Declare a string variable named 'str'

	fmt.Scan(&str) // Read a string input from the standard input and assign it to the 'str' variable

	// Check if the third and fourth characters of the string are identical
	if str[2] == str[3] {
		// If the condition is true, proceed to the next check
		if str[4] == str[5] { // Check if the fifth and sixth characters are identical
			fmt.Println("Yes") // If both conditions are true, print 'Yes' to the standard output
		} else {
			fmt.Println("No") // If not, print 'No' instead
		}
	}
}

// <END-OF-CODE>
