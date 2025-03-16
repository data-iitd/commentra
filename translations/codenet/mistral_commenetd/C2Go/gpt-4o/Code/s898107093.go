package main

import (
	"fmt"
)

func main() {
	var n int // number of strings to be compared
	var taro, hanako int // scores for Taro and Hanako

	// Read the number of strings to be compared from the standard input
	fmt.Scan(&n)

	// Declare slices for t and h
	t := make([]string, n)
	h := make([]string, n)

	// Initialize the loops for t and h slices
	for i := 0; i < n; i++ {
		// Read strings from the standard input and store them in t and h slices
		fmt.Scan(&t[i])
		fmt.Scan(&h[i])

		// Compare the strings and update the scores accordingly
		if t[i] < h[i] {
			hanako += 3 // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
		} else if t[i] > h[i] {
			taro += 3 // Taro gets 3 points if the current string in t is larger than the corresponding string in h
		} else { // If the strings are equal
			taro += 1 // Taro gets 1 point if the strings are equal
			hanako += 1 // Hanako gets 1 point if the strings are equal
		}
	}

	// Print the scores for Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)

	// No need to free memory in Go, as it has garbage collection
}

// <END-OF-CODE>
