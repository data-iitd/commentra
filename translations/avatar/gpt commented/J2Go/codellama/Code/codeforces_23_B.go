package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the console
	scanner := NewScanner(os.Stdin)

	// Read the number of test cases
	t, _ := strconv.Atoi(scanner.Next())

	// Loop through each test case
	for i := 0; i < t; i++ {
		// Read the integer n for the current test case
		n, _ := strconv.Atoi(scanner.Next())

		// Call the maxLeft function and print the result
		fmt.Println(maxLeft(n))
	}

	// Close the scanner to prevent resource leaks
	scanner.Close()
}

// Function to calculate the maximum value based on the input n
func maxLeft(n int) int {
	// Return n - 2 if n is greater than 2, otherwise return 0
	if n > 2 {
		return n - 2
	}
	return 0
}

// END-OF-CODE
