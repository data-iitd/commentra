package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read a line from the standard input
	var s string
	fmt.Scanln(&s)

	// Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
	result := "No"
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		result = "Yes"
	}

	// Print the value of the variable result
	fmt.Println(result)
}

// <END-OF-CODE>
