package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input from the standard input (user input)
	var s string
	fmt.Scanln(&s)

	// Check if both 'A' and 'B' are present in the input string
	// If both are found, set result to "Yes", otherwise set it to "No"
	result := "No"
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		result = "Yes"
	}

	// Print the result indicating whether both 'A' and 'B' were found
	fmt.Println(result)
}

// <END-OF-CODE>
