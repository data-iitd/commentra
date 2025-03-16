package main

import (
	"fmt"
)

func main() {
	// Declare a variable to hold the input string
	var s string
	
	// Read input from the user and store it in the variable 's'
	fmt.Scan(&s)
	
	// Initialize a counter to keep track of the number of '1's in the string
	ans := 0
	
	// Iterate over each character in the input string
	for _, c := range s {
		// Check if the current character is '1'
		if c == '1' {
			// Increment the counter if '1' is found
			ans++
		}
	}
	
	// Print the total count of '1's found in the input string
	fmt.Println(ans)
}
