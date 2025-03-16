package main

import (
	"fmt"
)

func main() {
	var str string // Declare a string variable named 'str' to store the input string

	// Read the input string from the standard input
	fmt.Scan(&str)

	max, cnt := 0, 0 // Initialize two integer variables 'max' and 'cnt' with zero values

	// Iterate through each character in the input string
	for _, sc := range str {
		// Check if the current character is a valid nucleotide (A, C, G or T)
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			cnt++ // Increment the count if the character is a valid nucleotide
		} else { // Otherwise, reset the count to zero
			cnt = 0
		}

		// Update the maximum count if the current count is greater than the previous maximum
		if cnt > max {
			max = cnt
		}
	}

	// Print the maximum count of valid nucleotides found in the input string
	fmt.Println(max)
}

// <END-OF-CODE>
