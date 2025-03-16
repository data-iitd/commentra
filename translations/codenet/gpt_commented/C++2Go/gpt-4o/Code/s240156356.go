package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare two strings to hold the input
	var str1, str2 string

	// Read two strings from the standard input
	fmt.Scan(&str1, &str2)

	// Convert strings to slices of runes for sorting
	runes1 := []rune(str1)
	runes2 := []rune(str2)

	// Sort the first string in ascending order
	sort.Slice(runes1, func(i, j int) bool {
		return runes1[i] < runes1[j]
	})

	// Sort the second string in descending order
	sort.Slice(runes2, func(i, j int) bool {
		return runes2[i] > runes2[j]
	})

	// Determine the length of the shorter string for the loop
	loop := len(runes1)
	if len(runes2) < loop {
		loop = len(runes2)
	}

	// Initialize a flag to track if the condition is met
	flag := false

	// Loop through the characters of both strings up to the length of the shorter one
	for i := 0; i < loop; i++ {
		ch1 := runes1[i] // Get the character from the first string
		ch2 := runes2[i] // Get the character from the second string

		// Check if the characters are equal
		if ch1 == ch2 {
			// If we are at the last character of the shorter string and str1 is shorter
			if loop == i+1 && len(runes1) < len(runes2) {
				flag = true // Set the flag to true
				break       // Exit the loop
			} else {
				continue // Continue to the next iteration
			}
		} else {
			// If the character from str2 is greater than that from str1
			if ch2 > ch1 {
				flag = true // Set the flag to true
				break       // Exit the loop
			} else {
				break // Exit the loop if ch1 is greater
			}
		}
	}

	// Output the result based on the flag's value
	if flag {
		fmt.Println("Yes") // Condition met
	} else {
		fmt.Println("No") // Condition not met
	}
}

// <END-OF-CODE>
