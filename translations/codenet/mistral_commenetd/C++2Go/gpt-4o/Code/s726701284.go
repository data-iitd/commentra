package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)

	// Start a loop that iterates through all the lowercase letters from 'a' to 'z'.
	for i := 'a'; i <= 'z'; i++ {
		a := 0 // Initialize an integer variable 'a' to 0.

		// Start another loop that iterates through all the characters in the string 's'.
		for j := 0; j < len(s); j++ {
			// Check if the current character 'i' matches the character at the current position 'j' in the string 's'.
			if i == rune(s[j]) {
				a++
			}
		}

		// After the inner loop, check if the value of 'a' is 0.
		if a == 0 {
			fmt.Println(string(i)) // Print the character 'i' and break out of the outer loop.
			break
		}

		// If the character 'i' is 'z', print "None" and break out of the outer loop.
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

// <END-OF-CODE>
