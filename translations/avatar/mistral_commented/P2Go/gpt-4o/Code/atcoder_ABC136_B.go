package main

import (
	"fmt"
)

func main() {
	// Read the number of test cases from the standard input
	var N int
	fmt.Scan(&N)

	// Initialize variables
	i := 1
	ans := 0

	// Calculate the answer using a while loop
	for pow10 := 10; pow10 <= N; pow10 *= 100 {
		// Add the difference between the current power of 10 and the previous power of 10 to the answer
		ans += pow10 - (pow10 / 10)
		// Increment the index i by 2 (handled by multiplying by 100)
		i += 2
	}

	// Add the remaining digits of the number N to the answer
	if N >= pow10/10 {
		ans += N - (pow10 / 10) + 1
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
