package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take an integer 'n' as input from the user
	var n int
	fmt.Scan(&n)

	// Take a list 'm' as input from the user, where each element is a single character
	var input string
	fmt.Scan(&input)
	m := strings.Fields(input)

	// Initialize a boolean variable 'possible' with a default value of true
	possible := true

	// Create a map to count occurrences of each character
	counts := make(map[string]int)

	// Count occurrences of each character in the list 'm'
	for _, char := range m {
		counts[char]++
	}

	// Iterate through each unique character in the map
	for _, count := range counts {
		// Check if the character appears more than 'n/2 + 1' times
		if count >= n/2+1 {
			// If the condition is true, set 'possible' to false and break the loop
			possible = false
			break
		}
	}

	// Print 'YES' if 'possible' is still true, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
