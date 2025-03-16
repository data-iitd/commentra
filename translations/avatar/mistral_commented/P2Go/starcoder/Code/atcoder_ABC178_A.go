package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve a single test case
func solve(tc int) {
	// Read the next test case and store it in a variable 'a'
	a := int(strings.TrimSpace(readLine()))

	// Print the solution for the current test case
	fmt.Printf("Case #%d: %d\n", tc, 1 if a == 0 else 0)
}

// Main function
func main() {
	// Read the number of test cases
	var tcs int
	fmt.Scanf("%d", &tcs)

	// Loop over all test cases
	for tc := 1; tc <= tcs; tc++ {
		// Solve the current test case
		solve(tc)
	}
}

// Function to read a single line from stdin
func readLine() string {
	var input string
	fmt.Scanln(&input)
	return input
}

