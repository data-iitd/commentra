// Import necessary modules
package main

import (
	"fmt"
	"os"
)

// Function to solve a single test case
func solve(tc int) {
	// Read the next test case and store it in a variable 'a'
	var a int
	fmt.Scan(&a)

	// Print the solution for the current test case
	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

// Initialize the number of test cases and the test case counter
var tcs int = 1
var tc int = 1

// Run the solution function for each test case
for tc <= tcs {
	// Solve the current test case
	solve(tc)

	// Increment the test case counter
	tc += 1
}

// End of code
