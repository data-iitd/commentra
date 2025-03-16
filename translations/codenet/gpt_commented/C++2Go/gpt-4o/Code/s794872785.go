package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() {
	// Initialize variables to track the maximum size of strings and their counts
	maxsize := 0 // To store the length of the longest string
	maxcnt := 0  // To store the count of the most frequent string
	var ansNum, ansNum2 int // Indices of the longest and most frequent strings
	strV := []string{}      // Slice to store input strings

	// Read strings from standard input
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		in := scanner.Text() // Get the input string
		strV = append(strV, in) // Add the string to the slice

		// Check if the current string is longer than the previously recorded maximum
		if maxsize < len(in) {
			maxsize = len(in) // Update the maximum size
			ansNum = len(strV) - 1 // Update index of the longest string
		}
	}

	// Loop through the slice to find the most frequent string
	for i := 0; i < len(strV); i++ {
		cnt := 0 // Counter for occurrences of the current string
		// Count how many times the current string appears in the slice
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++ // Increment count if a match is found
			}
		}
		// Check if the current count is greater than the previously recorded maximum count
		if maxcnt < cnt {
			maxcnt = cnt // Update the maximum count
			ansNum2 = i // Update index of the most frequent string
		}
	}

	// Output the most frequent string and the longest string
	fmt.Println(strV[ansNum2], strV[ansNum])
}

func main() {
	solve() // Call the solve function to process input and output results
}

// <END-OF-CODE>
