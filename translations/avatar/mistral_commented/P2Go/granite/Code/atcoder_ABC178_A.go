
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to solve a single test case
func solve(tc int) {
	// Create a new scanner to read the next test case
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next test case and store it in a variable 'a'
	scanner.Scan()
	a := scanner.Text()

	// Print the solution for the current test case
	fmt.Println(1)
}

// Initialize the number of test cases and the test case counter
var tcs int
var tc int

func main() {
	// Read the number of test cases from the command line argument
	tcs, _ = fmt.Sscanf(os.Args[1], "%d")

	// Run the solution function for each test case
	for tc = 1; tc <= tcs; tc++ {
		// Solve the current test case
		solve(tc)
	}
}

