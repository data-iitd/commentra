
package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}

	for r := a % b; r > 0; {
		a, b = b, r
		r = a % b
	}

	return b
}

func main() {
	var n int // Read the number of integers 'n' from the standard input

	fmt.Scan(&n) // Read the number of integers 'n' from the standard input and store it in the variable 'n'

	var ans int // Initialize an integer variable 'ans' to store the answer

	fmt.Scan(&ans) // Read the first integer 'ans' from the standard input and store it in the variable 'ans'

	// Read and process the remaining integers
	for i := 1; i < n; i++ {
		var a int // Initialize an integer variable 'a' to read the next integer from the standard input

		fmt.Scan(&a) // Read the next integer 'a' from the standard input and store it in the variable 'a'

		// Update the answer by finding the GCD of the current answer and the new integer 'a'
		ans = gcd(ans, a)
	}

	// Print the final answer to the standard output
	fmt.Println(ans)
}

