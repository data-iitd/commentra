package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve() bool {
	// Initialize variables to track the longest string and its count
	maxsize := 0
	maxcnt := 0
	ansNum := 0 // Index of the longest string
	ansNum2 := 0 // Index of the most frequent string
	strV := make([]string, 0) // Vector to store input strings

	// Variable to read input strings
	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break
		}
		strV = append(strV, in) // Store the input string in the vector
		if maxsize < len(in) { // Check if the current string is the longest so far
			maxsize = len(in) // Update the length of the longest string
			ansNum = len(strV) - 1 // Store the index of the longest string
		}
	}

	// Count occurrences of each string and find the most frequent string
	for i := 0; i < len(strV); i++ {
		cnt := 0
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] { // Count occurrences of the current string
				cnt++
			}
		}
		if maxcnt < cnt { // Check if the current string is the most frequent so far
			maxcnt = cnt // Update the count of the most frequent string
			ansNum2 = i // Store the index of the most frequent string
		}
	}

	// Output the most frequent and the longest string
	fmt.Println(strV[ansNum2], strV[ansNum])

	return true // Return true indicating success
}

// Main function to set precision and call the solve function
func main() {
	fmt.Printf("%.10f", math.Pi)
	solve()
}

