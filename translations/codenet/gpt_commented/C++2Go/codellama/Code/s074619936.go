package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Declare variables to hold input string, temporary string for individual characters, and the sum of digits
	var str string
	var tmp string
	var sum int

	// Infinite loop to continuously accept input until "0" is entered
	for {
		// Read input from the user
		fmt.Scan(&str)

		// Check if the input is "0", if so, exit the loop
		if str == "0" {
			break
		}

		// Initialize sum to 0 for the new input string
		sum = 0

		// Loop through each character in the input string
		for i := 0; i < len(str); i++ {
			// Convert the character to a string
			tmp = str[i : i+1]

			// Convert the string character to an integer
			num, _ := strconv.Atoi(tmp)

			// Add the integer value to the sum
			sum += num
		}

		// Output the sum of the digits for the current input string
		fmt.Println(sum)
	}

	// Return 0 to indicate successful completion of the program
	return 0
}

