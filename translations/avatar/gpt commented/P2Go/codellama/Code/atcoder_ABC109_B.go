
package main

import "fmt"

func main() {
	// Read the number of strings to be processed
	var n int
	fmt.Scan(&n)

	// Initialize a map to count occurrences of each string
	s := make(map[string]int)

	// Read n strings into a list
	l := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize a flag to determine if the conditions are met
	f := "Yes"

	// Initialize an index variable to track the previous string
	i := -1

	// Iterate through each string in the list
	for _, v := range l {
		// Increment the count for the current string
		s[v]++

		// Check if the current string has appeared more than once
		if s[v] >= 2 {
			f = "No" // Set flag to 'No' if a duplicate is found
		}

		// Check if the previous string's last character does not match the current string's first character
		if i != -1 && l[i][len(l[i])-1] != v[0] {
			f = "No" // Set flag to 'No' if the character condition is violated
		}

		// Update the index to the current string's index
		i++
	}

	// Print the final result based on the checks
	fmt.Println(f)
}

