package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the list from user input
	var n int
	fmt.Scan(&n)

	// Initialize a map to count occurrences of each element
	s := make(map[string]int)

	// Create a slice to hold the elements
	l := make([]string, n)

	// Read elements from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize a flag 'f' with value 'Yes'
	f := "Yes"

	// Iterate through each element 'v' in the list 'l'
	for i, v := range l {
		// Increment the count of 'v' in map 's'
		s[v]++

		// Check if the count of 'v' in map 's' is greater than or equal to 2
		if s[v] >= 2 {
			// If yes, set the flag 'f' to 'No'
			f = "No"
		}

		// Check if the index 'i' is not 0 and the last character of previous element is not equal to the current element
		if i != 0 && l[i-1][len(l[i-1])-1] != v[0] {
			// If yes, set the flag 'f' to 'No'
			f = "No"
		}
	}

	// Print the final value of flag 'f'
	fmt.Println(f)
}

// <END-OF-CODE>
