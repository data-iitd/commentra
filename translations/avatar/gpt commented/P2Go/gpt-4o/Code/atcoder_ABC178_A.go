package main

import (
	"fmt"
)

func solve() {
	var a int
	// Read an integer from standard input
	fmt.Scan(&a)

	// Print 1 if the integer is 0, otherwise print 0
	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	// Initialize the number of test cases
	tcs := 1
	// Start with the first test case
	tc := 1

	// Loop through each test case until the specified number of test cases is reached
	for tc <= tcs {
		// Call the solve function for the current test case
		solve()
		// Increment the test case counter
		tc++
	}
}

// <END-OF-CODE>
