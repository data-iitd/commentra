package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define the solve function that takes a test case number as an argument
func solve(tc int) {
	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)
	// Read an integer input from standard input
	a, _ := reader.ReadString('\n')
	// Remove the newline character from the input
	a = a[:len(a)-1]
	// Convert the input to an integer
	aInt := int(a[0] - '0')
	// Print 1 if the input is 0, otherwise print 0
	if aInt == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	// Set the number of test cases to 1 and initialize the current test case number
	tcs := 1
	tc := 1

	// Enter a for loop that continues as long as the current test case number is less than or equal to the total number of test cases
	for tc <= tcs {
		// Call the solve function with the current test case number and increment the current test case number
		solve(tc)
		tc++
	}
}
