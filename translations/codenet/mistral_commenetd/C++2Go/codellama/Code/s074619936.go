package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Initialize variables
	var str string
	var tmp string
	var sum int

	// Start an infinite loop
	for {
		// Read a string from the user input
		fmt.Scan(&str)

		// Check if the user wants to exit by entering "0"
		if str == "0" {
			// Exit the loop if user enters "0"
			break
		}

		// Initialize sum variable to zero
		sum = 0

		// Iterate through each character in the string
		for i := 0; i < len(str); i++ {
			// Get the character as a string
			tmp = str[i : i+1]

			// Convert the character to an integer and add it to the sum
			num, _ := strconv.Atoi(tmp)
			sum += num
		}

		// Print the sum of the digits in the string
		fmt.Println(sum)
	}

	// Return 0 to indicate successful execution
	return 0
}

