package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the user
	in := new(Scanner)

	// Read a long integer input from the user
	var number int64
	fmt.Scan(&number)

	// Initialize two variables, ans and value, to -1 and 0, respectively
	ans := int64(-1)
	value := int64(0)

	// Set a mask variable to 2
	mask := int64(2)

	// The code enters a while loop that continues as long as value is less than the input number
	for value < number {
		// Convert the mask value to a binary string, remove the first character, and store the result in the s variable
		s := strconv.FormatInt(mask, 2)[1:]

		// Count the number of zeros in the binary string and store it in the zeros variable
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		// If the number of zeros is not equal to the number of ones, skip the rest of the loop and increment the mask
		if zeros != len(s)-zeros {
			mask++
			continue
		}

		// Replace all zeros with 4 and all ones with 7 in the binary string and convert it back to a long integer
		s = s[:zeros] + "4" + s[zeros:]
		s = s[:len(s)-zeros] + "7" + s[len(s)-zeros:]
		value, _ = strconv.ParseInt(s, 2, 64)
	}

	// Print the value variable
	fmt.Println(value)
}

