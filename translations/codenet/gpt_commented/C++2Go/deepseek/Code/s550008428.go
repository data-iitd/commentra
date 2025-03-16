package main

import (
	"fmt"
	"sort"
)

func main() {
	var s int
	fmt.Scan(&s) // Read an integer input from the user
	a := []int{s} // Create a slice to store unique values of s
	depth := 2   // Initialize depth to 2

	// Start an infinite loop to process the value of s
	for {
		// Check if s is even
		if s%2 == 0 {
			x := s / 2 // If even, calculate the next value as half of s
			// Check if the new value x already exists in the slice
			if contains(a, x) {
				fmt.Println(depth) // If it exists, print the depth and exit
				return
			}
			a = append(a, x) // Append the new value x to the slice
		} else {
			// If s is odd, calculate the next value using the formula 3*s + 1
			x := 3*s + 1
			// Check if the new value x already exists in the slice
			if contains(a, x) {
				fmt.Println(depth) // If it exists, print the depth and exit
				return
			}
			a = append(a, x) // Append the new value x to the slice
		}
		s = x // Update s to the new value x for the next iteration
		depth++ // Increment the depth counter
	}

	// This line will never be reached due to the infinite loop
	fmt.Println(depth) // Print the depth (not reached)
}

// Helper function to check if a slice contains a specific value
func contains(s []int, e int) bool {
	sort.Ints(s) // Sort the slice
	i := sort.SearchInts(s, e) // Use binary search to find the element
	return i < len(s) && s[i] == e // Check if the element is found and equal to e
}

