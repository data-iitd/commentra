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
	for _, char := range N {
		// Increment the sum by the ASCII value of the current digit
		// (subtracting the ASCII value of '0' to get the actual digit value)
		S += int(char - '0')
	}

	// Check if the number is divisible by the sum of its digits
	if num, _ := strconv.Atoi(N); num%S == 0 {
		// Convert the string to an integer using strconv.Atoi()
		fmt.Println("Yes") // Output "Yes" if the number is divisible
	} else {
		fmt.Println("No") // Output "No" otherwise
	}
}

