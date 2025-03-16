package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	var str string
	var com string
	T := make(map[string]bool) // A map to store strings as keys and boolean values

	// Read the number of input pairs from the standard input
	fmt.Scan(&n)

	// Iterate through each input pair
	for i := 0; i < n; i++ {
		// Read the command and the string from the standard input
		fmt.Scan(&com, &str)

		// If the command is 'i', add the string to the map with a value of true
		if com[0] == 'i' {
			T[str] = true // Set the value of the string as a key in the map to true
		} else {
			// If the command is not 'i', check if the string is present in the map and print the result accordingly
			if _, exists := T[str]; exists { // Check if the string is present in the map
				fmt.Println("yes") // If present, print 'yes'
			} else {
				fmt.Println("no") // If not present, print 'no'
			}
		}
	}
}

// <END-OF-CODE>
