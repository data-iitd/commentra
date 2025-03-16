package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable to store the length of the string
	var n int
	// Read the length of the string from user input
	fmt.Scan(&n)

	// Declare a string variable to store the input string
	var s string
	// Read the string from user input
	fmt.Scan(&s)

	// Initialize a counter to count the number of distinct segments
	cnt := 0

	// Iterate through each character in the string
	for i := 0; i < n; i++ {
		// Increment the counter for each new segment found
		cnt++

		// Initialize a variable j to find the end of the current segment
		j := i + 1

		// Continue moving j forward as long as the characters are the same
		for j < n {
			// If the current character is different from the next character, break the loop
			if s[i] != s[j] {
				break
			}
			j++
		}

		// Move i to the end of the current segment
		i = j - 1
	}

	// Output the total count of distinct segments
	fmt.Println(cnt)
}

// <END-OF-CODE>
