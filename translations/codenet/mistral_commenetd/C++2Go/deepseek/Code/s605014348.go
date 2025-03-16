package main

import (
	"fmt"
	"math"
)

// Function to find the greatest divisor of a given number
func div(n int) int {
	// If the number is even, return 2 as the greatest divisor
	if n%2 == 0 {
		return 2
	}
	// Calculate the square root of the number
	s := int(math.Sqrt(float64(n)))
	// Check for divisibility by odd numbers from 3 to the square root
	for i := 3; i <= s; i += 2 {
		// If the number is divisible by the current odd number, return it as the greatest divisor
		if n%i == 0 {
			return i
		}
	}

	// If no divisor is found, return the number itself
	return n
}

func main() {
	// Declare and initialize a variable to store the input number
	var num int
	fmt.Scan(&num)
	// Print the input number
	fmt.Print(num, ":")

	// Continue the process until the number becomes 1
	for num != 1 {
		// Print the greatest divisor of the current number
		fmt.Print(" ", div(num))
		// Divide the current number by its greatest divisor
		num = num / div(num)
	}
	// Print a newline character to move the cursor to the next line
	fmt.Println()
}

