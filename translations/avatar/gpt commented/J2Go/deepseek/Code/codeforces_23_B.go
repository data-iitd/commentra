package main

import (
	"fmt"
)

func main() {
	// Read the number of test cases
	var t int
	fmt.Scan(&t)
	
	// Loop through each test case
	for i := 0; i < t; i++ {
		// Read the integer n for the current test case
		var n int
		fmt.Scan(&n)
		
		// Call the maxLeft function and print the result
		fmt.Println(maxLeft(n))
	}
}

// Function to calculate the maximum value based on the input n
func maxLeft(n int) int {
	// Return n - 2 if n is greater than 2, otherwise return 0
	if n > 2 {
		return n - 2
	}
	return 0
}
