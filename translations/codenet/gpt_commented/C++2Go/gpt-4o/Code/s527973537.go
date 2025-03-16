package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read input number as a string
	var N string
	fmt.Scan(&N)

	// Initialize a variable to hold the sum of the digits
	S := 0

	// Calculate the sum of the digits in the input string
	for _, char := range N {
		digit, _ := strconv.Atoi(string(char)) // Convert character to integer and add to sum
		S += digit
	}

	// Check if the original number is divisible by the sum of its digits
	num, _ := strconv.Atoi(N)
	if num%S == 0 {
		fmt.Println("Yes") // Output "Yes" if divisible
	} else {
		fmt.Println("No") // Output "No" if not divisible
	}
}

// <END-OF-CODE>
