package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a variable to store the input number
	var x int64
	fmt.Scan(&x)

	// Create a slice to store the digits of the number
	var list []int64

	// Loop through each digit of the number from right to left
	for x > 0 {
		// Get the last digit of the number
		r := x % 10

		// Check if the digit is greater than 4 and if 9 - digit is less than digit
		if 9-r < r {
			// If it's the last digit and 9 - r is 0, add the digit as is
			if x/10 == 0 && 9-r == 0 {
				list = append(list, r)
			} else {
				// Otherwise, add 9 - digit to the list
				list = append(list, 9-r)
			}
		} else {
			// Otherwise, add the digit to the list
			list = append(list, r)
		}

		// Remove the last digit from the number
		x = x / 10
	}

	// Initialize variables to construct the new number
	pow := 0
	var newNumber int64 = 0

	// Loop through the slice of digits to construct the new number
	for i := 0; i < len(list); i++ {
		// Add the digit to the new number at the appropriate place value
		newNumber += list[i] * int64(math.Pow(10, float64(pow)))
		pow++
	}

	// Print the new number
	fmt.Println(newNumber)
}

// <END-OF-CODE>
