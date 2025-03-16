
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases from user input
	n, _ := strconv.Atoi(read(reader))

	// Loop through each test case
	for i := 0; i < n; i++ {
		// Read two integers a and b from user input
		a, _ := strconv.Atoi(read(reader))
		b, _ := strconv.Atoi(read(reader))

		// Call the sub method and print the result
		fmt.Println(sub(a, b))
	}
}

// Method to perform a specific subtraction-like operation
func sub(a int, b int) int {
	// Determine the minimum and maximum of the two numbers
	min := int(math.Min(float64(a), float64(b)))
	max := int(math.Max(float64(a), float64(b)))

	// Initialize the result variable to store the final output
	result := 0

	// Continue the process while min is greater than 0
	for min > 0 {
		// Add the quotient of max divided by min to the result
		result += max / min

		// Update max to be the remainder of max divided by min
		max = max % min

		// Update min and max for the next iteration
		curr_min := int(math.Min(float64(min), float64(max)))
		curr_max := int(math.Max(float64(min), float64(max)))
		min = curr_min
		max = curr_max
	}

	// Return the final result
	return result
}

// Function to read a single line of input from the console
func read(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

