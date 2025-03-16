package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases from stdin
	tc, err := strconv.Atoi(readLine(reader))
	check(err)

	// Loop through each test case
	for i := 0; i < tc; i++ {
		// Read two integers a and b from stdin
		a, err := strconv.Atoi(readLine(reader))
		check(err)
		b, err := strconv.Atoi(readLine(reader))
		check(err)

		// Call the sub method and print the result
		fmt.Printf("%d\n", sub(a, b))
	}
}

// Method to perform a specific subtraction-like operation
func sub(a, b int) int {
	// Determine the minimum and maximum of the two numbers
	min := a
	if b < a {
		min = b
	}
	max := a
	if b > a {
		max = b
	}

	// Initialize the result variable to store the final output
	result := 0

	// Continue the process while min is greater than 0
	for min > 0 {
		// Add the quotient of max divided by min to the result
		result += max / min

		// Update max to be the remainder of max divided by min
		max = max % min

		// Update min and max for the next iteration
		curr_min := min
		curr_max := max
		if curr_min > curr_max {
			curr_min = curr_max
		}
		min = curr_min
		max = curr_max
	}

	// Return the final result
	return result
}

// Helper method to read input from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

// Helper method to check for errors
func check(err error) {
	if err!= nil {
		panic(err)
	}
}

