package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Initialize scanner to read input from standard input
	var number int64
	fmt.Scan(&number)

	// Initialize variables for answer and current value
	var ans int64 = -1
	var value int64 = 0

	// Initialize mask variable for binary number manipulation
	var mask int = 2

	// Main loop to find the answer
	for value < number {
		// Convert mask to binary string and remove leading '1'
		s := strconv.FormatInt(int64(mask), 2)[1:]
		mask++

		// Count the number of zeros in the binary string
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		// If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
		if zeros != len(s)-zeros {
			continue
		}

		// Replace all zeros with '4' and all ones with '7' in the binary string
		s = strings.ReplaceAll(s, "0", "4")
		s = strings.ReplaceAll(s, "1", "7")

		// Convert the modified binary string back to a long number and update the value variable
		value, _ = strconv.ParseInt(s, 10, 64)
	}

	// Print the answer
	fmt.Println(value)
}
