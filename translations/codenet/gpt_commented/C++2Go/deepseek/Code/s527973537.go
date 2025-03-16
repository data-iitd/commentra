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
	var S int

	// Calculate the sum of the digits in the input string
	for _, char := range N {
		digit, _ := strconv.Atoi(string(char))
		S += digit
	}

	// Convert the original number from string to integer
	num, _ := strconv.Atoi(N)

	// Check if the original number is divisible by the sum of its digits
	if num%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

