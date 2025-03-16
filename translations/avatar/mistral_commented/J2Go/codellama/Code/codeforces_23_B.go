
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of test cases from the input
	t, _ := strconv.Atoi(scan.Text())

	// Iterate through each test case
	for i := 0; i < t; i++ {
		// Read the number of elements in the array
		n, _ := strconv.Atoi(scan.Text())

		// Print the maximum left sum
		fmt.Println(maxLeft(n))
	}

	// Close the Scanner object to free up system resources
	scan.Close()
}

// Function to calculate the maximum sum of elements to the left of a given index
func maxLeft(n int) int {
	// Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
	if n > 2 {
		return n - 2
	}
	return 0
}

