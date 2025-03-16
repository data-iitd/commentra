package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Declare and initialize variables
	var N string // string to store the input number
	var S int    // sum of digits of the number

	// Read the input number from the standard input
	fmt.Print("Enter a number: ")
	fmt.Scan(&N)

	// Calculate the sum of digits of the number
	for i := 0; i < len(N); i++ {
		// Increment the sum by the actual digit value
		digit := int(N[i] - '0')
		S += digit
	}

	// Check if the number is divisible by the sum of its digits
	num, _ := strconv.Atoi(N) // Convert the string to an integer using strconv.Atoi()
	if num%S == 0 {
		fmt.Println("Yes") // Output "Yes" if the number is divisible
	} else {
		fmt.Println("No") // Output "No" otherwise
	}
}

// <END-OF-CODE>
