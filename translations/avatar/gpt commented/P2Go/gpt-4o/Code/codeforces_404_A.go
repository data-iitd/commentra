package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the number of rows/columns for the square matrix
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input strings
	s := make([]string, n)

	// Read n strings from input and append them to the slice s
	for i := 0; i < n; i++ {
		var k string
		fmt.Scan(&k)
		s[i] = k
	}

	// Initialize slices to store diagonal elements
	d1 := []rune{} // Primary diagonal
	d2 := []rune{} // Secondary diagonal

	// Initialize a map to store non-diagonal elements
	rem := make(map[rune]struct{})

	// Iterate through the matrix to populate the diagonals and non-diagonal elements
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If it's a primary diagonal element
			if i == j {
				d1 = append(d1, rune(s[i][j]))
			}
			// If it's a secondary diagonal element
			if i == n-j-1 {
				d2 = append(d2, rune(s[i][j]))
			}
			// If it's a non-diagonal element
			if i != j && i != n-j-1 {
				rem[rune(s[i][j])] = struct{}{}
			}
		}
	}

	// Check conditions to determine the output
	// If the number of unique non-diagonal elements is not 1
	if len(rem) != 1 {
		fmt.Println("NO")
		return
	}

	// If the primary and secondary diagonals are not equal
	if string(d1) != string(d2) {
		fmt.Println("NO")
		return
	}

	// If the primary diagonal does not consist of the same element
	if len(d1) > 0 && len(d1) != len(strings.Split(string(d1), string(d1[0]))) {
		fmt.Println("NO")
		return
	}

	// If the unique element in the primary diagonal is also in the non-diagonal set
	if _, exists := rem[d1[0]]; exists {
		fmt.Println("NO")
		return
	}

	// If all conditions are satisfied, print 'YES'
	fmt.Println("YES")
}

// <END-OF-CODE>
