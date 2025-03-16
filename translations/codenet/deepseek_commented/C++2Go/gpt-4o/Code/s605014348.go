package main

import (
	"fmt"
	"math"
)

// Function to find the smallest divisor of a number
func div(n int) int {
	if n%2 == 0 {
		return 2 // Check if the number is even and return 2
	}
	s := int(math.Sqrt(float64(n)))
	for i := 3; i <= s; i += 2 { // Check for divisors starting from 3 up to the square root
		if n%i == 0 {
			return i // Return the first divisor found
		}
	}
	return n // If no divisor is found, return the number itself
}

func main() {
	var num int
	fmt.Scan(&num) // Read an integer from the user
	fmt.Print(num, ":")

	for num != 1 {
		smallestDivisor := div(num)
		fmt.Print(" ", smallestDivisor) // Print the smallest divisor
		num = num / smallestDivisor      // Divide the number by its smallest divisor
	}
	fmt.Println()
}

// <END-OF-CODE>
