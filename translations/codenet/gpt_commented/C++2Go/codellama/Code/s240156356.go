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

	// Sort the first string in ascending order
	sort.Strings([]string{str1})

	// Sort the second string in descending order
	sort.Sort(sort.Reverse(sort.StringSlice([]string{str2})))

	// Determine the length of the shorter string for the loop
	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}

	// Initialize a flag to track if the condition is met
	flag := false

	// Loop through the characters of both strings up to the length of the shorter one
	for i := 0; loop > i; i++ {
		ch1 := str1[i] // Get the character from the first string
		ch2 := str2[i] // Get the character from the second string

		// Check if the characters are equal
		if ch1 == ch2 {
			// If we are at the last character of the shorter string and str1 is shorter
			if loop == i+1 && len(str1) < len(str2) {
				flag = true // Set the flag to true
				break // Exit the loop
			} else {
				continue // Continue to the next iteration
			}
		} else {
			// If the character from str2 is greater than that from str1
			if ch2 > ch1 {
				flag = true // Set the flag to true
				break // Exit the loop
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

