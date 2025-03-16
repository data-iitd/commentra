package main

import (
	"fmt"
)

func main() {
	var N int
	// Read the integer N from input
	fmt.Scan(&N)

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Loop through each integer from 1 to N (inclusive)
	for i := 1; i <= N; i++ {
		// Calculate the contribution of the current integer i to the answer
		ans += i * (N / i) * (N/i + 1) / 2
	}

	// Print the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
