package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Define a constant for a large number (infinity) for potential use in calculations
	const INF = int64(1e15)

	// Create a Scanner object to read input from the console
	// Note: Go does not have a built-in Scanner like Java, so we use fmt.Scan
	var number string
	fmt.Scan(&number)

	// Initialize an array to hold the digits of the number in reverse order
	digits := make([]int, len(number)+1)

	// Convert the input string into an array of digits (in reverse order)
	for i := 0; i < len(number); i++ {
		digits[i] = int(number[len(number)-1-i] - '0')
	}

	// Initialize a variable to count the total number of bills
	bills := 0

	// Process each digit to calculate the total number of bills needed
	for i := 0; i <= len(number); i++ {
		// Handle carry over for digits equal to 10
		if digits[i] == 10 {
			digits[i+1]++
			digits[i] = 0
		}

		// If the digit is less than 5, add it directly to the bills
		if digits[i] < 5 {
			bills += digits[i]
		}
		// If the digit is exactly 5, check the next digit for rounding
		else if digits[i] == 5 {
			if i+1 < len(number) && digits[i+1] >= 5 {
				digits[i+1]++
			}
			bills += 5
		}
		// If the digit is greater than 5, round up to the next ten
		else {
			digits[i+1]++
			bills += 10 - digits[i]
		}
	}

	// Output the total number of bills calculated
	fmt.Println(bills)
}
