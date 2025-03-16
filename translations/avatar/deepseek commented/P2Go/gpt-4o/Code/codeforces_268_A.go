package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input representing the number of elements
	q := make([][]string, 0) // Initialize an empty slice to store the elements
	count := 0 // Initialize a counter to keep track of valid pairs

	// Loop to take input and append to the slice `q`
	for i := 0; i < n; i++ {
		var a string
		fmt.Scan(&a) // Read a line of input
		q = append(q, split(a)) // Split the input and append to the slice `q`
	}

	// Nested loop to compare each element with every other element
	for _, j := range q {
		for _, k := range q {
			if k == j { // Skip if the same element is compared with itself
				continue
			} else if j[0] == k[len(k)-1] { // Check if the first character of `j` matches the last character of `k`
				count++ // Increment the counter if the condition is met
			}
		}
	}

	fmt.Println(count) // Print the total count of valid pairs
}

// Helper function to split a string into a slice of strings
func split(s string) []string {
	return []string{s} // In Go, you can use strings.Split(s, " ") for actual splitting
}

// Note: The split function here is a placeholder. You may need to implement actual splitting logic based on your input format.

