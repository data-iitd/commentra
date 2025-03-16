package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a function to solve the problem for a given test case
func solve(tc int) {
	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)
	
	// Read a line from standard input, strip any extra whitespace, and convert to an integer
	a, _ := reader.ReadString('\n')
	a = a[:len(a)-1] // Remove the newline character
	aInt := int(a[0] - '0')
	
	// Print 1 if the integer is 0, otherwise print 0
	if aInt == 0 {
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
		solve(tc)
		// Increment the test case counter
		tc++
	}
}
