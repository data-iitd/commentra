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
	for i := 0; i < len(N); i++ {
		S += int(N[i] - '0') // Convert character to integer and add to sum
	}

	// Check if the original number is divisible by the sum of its digits
	if stoi(N)%S == 0 {
		fmt.Println("Yes") // Output "Yes" if divisible
	} else {
		fmt.Println("No") // Output "No" if not divisible
	}
}

func stoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

