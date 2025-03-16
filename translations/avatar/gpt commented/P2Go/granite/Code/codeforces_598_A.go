
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of test cases from the standard input
	reader := bufio.NewReader(os.Stdin)
	t, _ := fmt.Fscanf(reader, "%d\n", &t)

	// Define a function to solve the problem for a given n
	solve := func(n int) int {
		// Calculate the sum of the first n natural numbers using the formula n(n + 1) / 2
		s := (1 + n) * n / 2

		// Initialize a variable to track the power of 2
		t := 1

		// Subtract twice the value of powers of 2 from the sum until t exceeds n
		for t <= n {
			s -= 2 * t  // Subtract 2 times the current power of 2 from the sum
			t *= 2      // Move to the next power of 2
		}

		// Return the final computed sum
		return s
	}

	// Loop over each test case
	for i := 0; i < t; i++ {
		// Read the input value for n from the standard input
		var n int
		fmt.Fscanf(reader, "%d\n", &n)

		// Print the result of the solve function for the current n
		fmt.Println(solve(n))
	}
}
