package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem of finding the longest and most frequent string
func solve() bool {
	// Initialize variables to track the maximum size of strings and their counts
	maxsize := 0 // To store the length of the longest string
	maxcnt := 0  // To store the count of the most frequent string
	ans_num := 0 // Index of the longest string
	ans_num2 := 0 // Index of the most frequent string
	str_v := make([]string, 0) // Vector to store input strings

	in := "" // Variable to hold each input string
	// Read strings from standard input until EOF
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break
		}
		str_v = append(str_v, in) // Add the string to the vector
		// Check if the current string is longer than the previously recorded maximum
		if maxsize < len(in) {
			maxsize = len(in) // Update the maximum size
			ans_num = len(str_v) - 1 // Update index of the longest string
		}
	}

	// Loop through the vector to find the most frequent string
	for i := 0; i < len(str_v); i++ {
		cnt := 0 // Counter for occurrences of the current string
		// Count how many times the current string appears in the vector
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++ // Increment count if a match is found
			}
		}
		// Check if the current count is greater than the previously recorded maximum count
		if maxcnt < cnt {
			maxcnt = cnt // Update the maximum count
			ans_num2 = i // Update index of the most frequent string
		}
	}

	// Output the most frequent string and the longest string
	fmt.Println(str_v[ans_num2], str_v[ans_num])

	return true // Indicate successful execution
}

func main() {
	// Set output format to fixed-point notation with 10 decimal places
	fmt.Printf("%.10f", math.Pi)
	// Call the solve function to process input and output results
	solve()

	// Indicate successful program termination
	os.Exit(0)
}

