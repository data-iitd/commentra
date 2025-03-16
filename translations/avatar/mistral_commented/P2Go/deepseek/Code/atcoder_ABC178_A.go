package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to solve a single test case
func solve(tc int) {
	// Create a new reader from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the next test case and store it in a variable 'a'
	a, _ := reader.ReadString('\n')

	// Convert the string to an integer
	a = a[:len(a)-1] // Remove the newline character
	aInt := 0
	for _, char := range a {
		aInt = aInt*10 + int(char-'0')
	}

	// Print the solution for the current test case
	fmt.Println(1)
}

func main() {
	// Initialize the number of test cases and the test case counter
	tcs := 1
	tc := 1

	// Run the solution function for each test case
	for tc <= tcs {
		solve(tc)
		tc++
	}
}
