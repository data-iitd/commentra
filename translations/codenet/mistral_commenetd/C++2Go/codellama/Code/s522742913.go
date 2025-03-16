package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty string variable named 'source'
	var source string

	// Read a string input from the standard input stream (os.Stdin) and store it in the 'source' variable
	fmt.Scan(&source)

	// Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
	if len(source) > 10 || len(source) < 1 {
		// If the condition is true, return an error code (-1)
		fmt.Println(-1)
		return
	}

	// Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
	max_i := int(math.Pow(2, float64(len(source)-1)))

	// Initialize a variable named 'sum' with a value of 0
	var sum float64

	// Iterate through the range of 'i' from 0 to 'max_i' using a for loop
	for i := 0; i < max_i; i++ {
		// Create a bitset named 'plus' with the binary representation of 'i'
		plus := strconv.FormatInt(int64(i), 2)

		// Initialize a variable named 'number' with a value of 0
		var number float64

		// Initialize a string variable named 'working' with the value of the input string 'source'
		working := source

		// Iterate through the bits of the 'plus' bitset from the least significant bit to the most significant bit
		for len(plus) > 0 {
			// Find the index of the first '1' bit in the 'plus' bitset
			index := strings.Index(plus, "1")

			// Add the substring of the 'working' string starting from the first '1' bit index to the 'sum' variable
			sum += atof(working[:index+1])

			// Shift the 'plus' bitset to the right by the index of the first '1' bit
			plus = plus[index+1:]

			// Update the value of the 'working' string by removing the substring that has been added to the 'sum' variable
			working = working[index+1:]
		}

		// Add the remaining substring of the 'working' string to the 'sum' variable
		sum += atof(working)
	}

	// Set the precision of the output stream (os.Stdout) to 0 decimal places
	fmt.Printf("%.0f\n", sum)

	// Return 0 to indicate successful execution of the program
	return
}

// 