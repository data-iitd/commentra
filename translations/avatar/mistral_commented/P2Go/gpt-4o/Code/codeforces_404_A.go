package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take the number of rows as input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 's' to store the rows
	s := make([][]string, n)

	// Read each row and append it to the slice 's'
	for i := 0; i < n; i++ {
		var input string
		fmt.Scan(&input)
		s[i] = strings.Split(input, " ")
	}

	// Initialize flags and empty slices 'd1' and 'd2'
	var d1, d2 []string
	rem := make(map[string]struct{})

	// Iterate through each element in the slice 's'
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If the current indices are the same, append the element to 'd1'
			if i == j {
				d1 = append(d1, s[i][j])
			}
			// If the current indices are reverse of each other, append the element to 'd2'
			if i == n-j-1 {
				d2 = append(d2, s[i][j])
			}
			// If the current indices are not the same and not reverse, add the element to 'rem' map
			if i != j && i != n-j-1 {
				rem[s[i][j]] = struct{}{}
			}
		}
	}

	// Check if the size of 'rem' map is not equal to 1
	if len(rem) != 1 {
		fmt.Println("NO")
		return
	}

	// Check if 'd1' and 'd2' slices are equal
	if !equalSlices(d1, d2) {
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are the same
	if len(unique(d1)) != 1 {
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are present in 'rem' map
	if !containsAll(rem, d1) {
		fmt.Println("NO")
		return
	}

	// If all the above conditions are false, print 'YES'
	fmt.Println("YES")
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

// Function to get unique elements from a slice
func unique(slice []string) []string {
	uniqueMap := make(map[string]struct{})
	for _, item := range slice {
		uniqueMap[item] = struct{}{}
	}
	var uniqueSlice []string
	for key := range uniqueMap {
		uniqueSlice = append(uniqueSlice, key)
	}
	return uniqueSlice
}

// Function to check if all elements in 'd1' are present in 'rem' map
func containsAll(rem map[string]struct{}, d1 []string) bool {
	for _, item := range d1 {
		if _, exists := rem[item]; !exists {
			return false
		}
	}
	return true
}
