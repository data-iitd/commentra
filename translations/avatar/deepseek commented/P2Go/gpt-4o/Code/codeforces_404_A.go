package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Take the size of the square matrix as input
	s := make([]string, n) // Initialize a slice to store the matrix elements

	// Take n inputs, each representing a row of the matrix, and append these to the slice s
	for i := 0; i < n; i++ {
		var k string
		fmt.Scan(&k)
		s[i] = k
	}

	d1 := []string{} // Initialize a slice to store the diagonal elements from top-left to bottom-right
	d2 := []string{} // Initialize a slice to store the diagonal elements from top-right to bottom-left
	rem := make(map[string]struct{}) // Initialize a map to store the non-diagonal elements

	// Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j { // Check if the element is on the diagonal from top-left to bottom-right
				d1 = append(d1, string(s[i][j]))
			}
			if i == n-j-1 { // Check if the element is on the diagonal from top-right to bottom-left
				d2 = append(d2, string(s[i][j]))
			}
			if i != j && i != n-j-1 { // Check if the element is not on the diagonals
				rem[string(s[i][j])] = struct{}{}
			}
		}
	}

	// Check the conditions and print 'NO' or 'YES' based on the conditions
	if len(rem) != 1 {
		fmt.Println("NO") // Print 'NO' if the map of non-diagonal elements does not have a single unique element
	} else if !equalSlices(d1, d2) {
		fmt.Println("NO") // Print 'NO' if the two diagonals are not equal
	} else if !allEqual(d1) {
		fmt.Println("NO") // Print 'NO' if the diagonal elements do not all have the same value
	} else if setsEqual(rem, d1) {
		fmt.Println("NO") // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
	} else {
		fmt.Println("YES") // Print 'YES' if all conditions are met
	}
}

// Function to check if two slices are equal
func equalSlices(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

// Function to check if all elements in a slice are equal
func allEqual(slice []string) bool {
	if len(slice) == 0 {
		return true
	}
	first := slice[0]
	for _, v := range slice {
		if v != first {
			return false
		}
	}
	return true
}

// Function to check if the set of non-diagonal elements is equal to the set of diagonal elements
func setsEqual(rem map[string]struct{}, d1 []string) bool {
	if len(rem) != len(d1) {
		return false
	}
	for _, v := range d1 {
		if _, exists := rem[v]; !exists {
			return false
		}
	}
	return true
}
