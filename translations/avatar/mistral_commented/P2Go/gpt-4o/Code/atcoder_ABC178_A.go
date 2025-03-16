package main

import (
	"fmt"
)

func solve(tc int) {
	var a int
	// Read the next test case and store it in a variable 'a'
	fmt.Scan(&a)

	// Print the solution for the current test case
	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	// Initialize the number of test cases and the test case counter
	tcs := 1
	tc := 1

	// Run the solution function for each test case
	for tc <= tcs {
		// Solve the current test case
		solve(tc)

		// Increment the test case counter
		tc++
	}
}

// <END-OF-CODE>
