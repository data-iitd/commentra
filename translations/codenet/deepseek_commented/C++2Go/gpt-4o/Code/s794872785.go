package main

import (
	"fmt"
	"strings"
)

func solve() {
	// Initialize variables to track the longest string and its count
	var maxsize int
	var maxcnt int
	var ansNum int // Index of the longest string
	var ansNum2 int // Index of the most frequent string
	strV := []string{} // Slice to store input strings

	// Variable to read input strings
	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break // Exit on error (EOF)
		}
		strV = append(strV, in) // Store the input string in the slice
		if maxsize < len(in) { // Check if the current string is the longest so far
			maxsize = len(in) // Update the length of the longest string
			ansNum = len(strV) - 1 // Store the index of the longest string
		}
	}

	// Count occurrences of each string and find the most frequent string
	for i := 0; i < len(strV); i++ {
		cnt := 0
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++ // Count occurrences of the current string
			}
		}
		if maxcnt < cnt { // Check if the current string is the most frequent so far
			maxcnt = cnt // Update the count of the most frequent string
			ansNum2 = i // Store the index of the most frequent string
		}
	}

	// Output the most frequent and the longest string
	fmt.Println(strV[ansNum2], strV[ansNum])
}

// Main function to call the solve function
func main() {
	solve()
}

// <END-OF-CODE>
