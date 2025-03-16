package main

import (
	"fmt"
	"strconv"
)

func main() {
	var str string // Declare a string variable to store user input
	var tmp string // Declare a temporary string variable for character conversion
	var sum int = 0 // Declare an integer variable to store the sum of digits

	// Infinite loop that continues until the user inputs "0"
	for {
		fmt.Scan(&str) // Read a string from the user
		if str == "0" {
			break
		}
		sum = 0 // Initialize sum to 0
		for i := 0; i < len(str); i++ { // Loop through each character in the string
			tmp = str[i : i+1] // Convert the character to a string
			num, _ := strconv.Atoi(tmp) // Convert the string to an integer
			sum += num // Add the integer to the sum
		}

		fmt.Println(sum) // Print the sum
	}
}

