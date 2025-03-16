package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	in := new(Scanner)

	// Read a long integer from user input
	var number int64
	fmt.Scan(&number)

	// Initialize variables to store the result and the current value
	var ans int64 = -1
	var value int64 = 0

	// Initialize a mask variable starting from 2
	var mask int = 2

	// Loop until the current value is less than the input number
	for value < number {
		// Convert the current mask to a binary string and remove the leading '1'
		s := strconv.FormatInt(int64(mask), 2)
		s = s[1:]

		// Initialize a counter for zeros in the binary string
		zeros := 0

		// Count the number of '0's in the binary string
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		// If the number of zeros is not equal to the number of ones, skip to the next iteration
		if zeros != len(s)-zeros {
			mask++
			continue
		}

		// Replace '0's with '4's and '1's with '7's to form a new number
		s = s[:zeros] + "4" + s[zeros:]
		s = s[:len(s)-zeros] + "7" + s[len(s)-zeros:]

		// Parse the modified string as a long integer
		value, _ = strconv.ParseInt(s, 10, 64)
	}

	// Print the final value that meets the condition
	fmt.Println(value)
}

