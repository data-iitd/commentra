package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, x int
	var s string

	// Read the upper limit 'n' from user input
	fmt.Scan(&n)

	// Loop through numbers from 1 to n
	for i := 1; i <= n; i++ {
		x = i // Assign the current number to 'x'
		s = strconv.Itoa(x) // Convert 'x' to string for digit analysis

		// Check if 'x' is divisible by 3 or ends with the digit 3
		if x % 3 == 0 || s[len(s)-1] == '3' {
			fmt.Printf(" %d", i) // Print the number if condition is met
			continue // Skip to the next iteration
		} else {
			// Get the number of digits in 'x'
			k := len(s)
			// Loop through each digit of 'x' from the most significant to the least
			for k > 0 {
				k-- // Decrease the digit index
				j := int(pow(10, float64(k))) // Calculate the place value for the current digit
				// Check if the current digit is 3
				if int(s[len(s)-k-1]-'0') == 3 {
					fmt.Printf(" %d", i) // Print the number if it contains the digit 3
					break // Exit the loop as we found a 3
				}
			}
		}
	}

	fmt.Println() // Print a newline after all numbers are processed
}

func pow(x, y float64) float64 {
	return math.Pow(x, y)
}
