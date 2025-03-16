package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a variable to read input from the user
	var number int64
	fmt.Scan(&number)

	// Initialize two variables, ans and value, to -1 and 0, respectively
	var ans int64 = -1
	var value int64 = 0

	// Set a mask variable to 2
	mask := 2

	// The code enters a loop that continues as long as value is less than the input number
	for value < number {
		// Convert the mask value to a binary string and remove the first character
		s := strconv.FormatInt(int64(mask), 2)[1:]
		mask++

		// Count the number of zeros in the binary string
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		// If the number of zeros is not equal to the number of ones, skip the rest of the loop
		if zeros != len(s)-zeros {
			continue
		}

		// Replace all zeros with 4 and all ones with 7 in the binary string
		s = replace(s, '0', '4')
		s = replace(s, '1', '7')

		// Convert it back to a long integer
		value, _ = strconv.ParseInt(s, 10, 64)
	}

	// Print the value variable
	fmt.Println(value)
}

// Helper function to replace characters in a string
func replace(s string, old, new rune) string {
	result := []rune(s)
	for i, c := range result {
		if c == old {
			result[i] = new
		}
	}
	return string(result)
}
