package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
	"strings" // Import the strings package for string manipulation
)

func main() {
	var s, t string // Declare two string variables, s and t
	fmt.Scan(&s, &t) // Read input strings s and t from the user

	s += s // Concatenate string s with itself, effectively doubling it

	// Check if string t can be found within the doubled string s
	// If found, print "Yes", otherwise print "No"
	if strings.Contains(s, t) {
		fmt.Println("Yes") // Print "Yes" if t is found in s
	} else {
		fmt.Println("No") // Print "No" if t is not found in s
	}
}

// <END-OF-CODE>
