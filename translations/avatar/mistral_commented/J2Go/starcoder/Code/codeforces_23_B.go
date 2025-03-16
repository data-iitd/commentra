
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the maximum sum of elements to the left of a given index
func maxLeft(n int) int {
	// Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
	if n > 2 {
		return n - 2
	}
	return 0
}

// Main function
func main() {
	// Read the number of test cases from the input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of test cases: ")
	input, _ := reader.ReadString('\n')
	t, _ := strconv.Atoi(strings.TrimSpace(input))

	// Iterate through each test case
	for i := 0; i < t; i++ {
		fmt.Print("Enter the number of elements in the array: ")
		input, _ := reader.ReadString('\n')
		n, _ := strconv.Atoi(strings.TrimSpace(input))

		// Print the maximum left sum
		fmt.Printf("Maximum left sum: %d\n", maxLeft(n))
	}
}

