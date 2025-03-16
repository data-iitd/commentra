package main

import (
	"fmt"
	"strings"
)

func solve() {
	// Initialize variables
	maxSize := 0
	maxCount := 0
	ansNum := -1
	ansNum2 := -1
	strV := []string{} // Slice to store strings read from input

	// Read strings from input
	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break // Exit on error (EOF)
		}
		// Append the string into the slice
		strV = append(strV, in)
		// Update maxSize if the current string is larger
		if maxSize < len(in) {
			maxSize = len(in)
			ansNum = len(strV) - 1
		}
	}

	// Find the string with maximum occurrences in the slice
	for i := 0; i < len(strV); i++ {
		cnt := 0
		// Count the occurrences of the current string in the slice
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++
			}
		}
		// Update maxCount and ansNum2 if the current string has more occurrences
		if maxCount < cnt {
			maxCount = cnt
			ansNum2 = i
		}
	}

	// Print the answer
	fmt.Println(strV[ansNum2], strV[ansNum])

	// Return true to indicate successful execution (not needed in Go)
}

func main() {
	// Call the solve function
	solve()
}

// <END-OF-CODE>
