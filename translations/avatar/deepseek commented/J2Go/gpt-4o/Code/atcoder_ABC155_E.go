package main

import (
	"fmt"
	"math"
)

func main() {
	// Define a constant for infinity
	const INF = 1e15

	// Read the input number as a string
	var number string
	fmt.Scan(&number)

	// Create a slice to store the digits of the number
	digits := make([]int, len(number)+1)

	// Convert the number into a slice of digits
	for i := 0; i < len(number); i++ {
		digits[i] = int(number[len(number)-1-i] - '0')
	}

	// Initialize the total bill to 0
	bills := 0

	// Loop through each digit to calculate the total bill
	for i := 0; i <= len(number); i++ {
		// Handle the case where the digit is 10
		if digits[i] == 10 {
			digits[i+1]++
			digits[i] = 0
		}

		// Add the digit to the bill if it is less than 5
		if digits[i] < 5 {
			bills += digits[i]
		} else if digits[i] == 5 {
			if digits[i+1] >= 5 {
				digits[i+1]++
			}
			bills += 5
		} else {
			digits[i+1]++
			bills += 10 - digits[i]
		}
	}

	// Print the total bill
	fmt.Println(bills)
}

// <END-OF-CODE>
