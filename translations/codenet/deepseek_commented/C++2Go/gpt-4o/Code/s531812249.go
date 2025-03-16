package main

import (
	"fmt"
)

func main() {
	var n, m int

	// Read two integers n and m from the standard input
	fmt.Scan(&n, &m)

	// n represents the number of items, m represents the number of items

	ans := 0
	// Initialize a variable to store the result, which will be the sum of combinations

	// Calculate the number of ways to choose 2 items from n items (n choose 2)
	ans += n * (n - 1) / 2

	// The formula for n choose 2 is n * (n - 1) / 2
	// Add this value to the answer

	// Calculate the number of ways to choose 2 items from m items (m choose 2)
	ans += m * (m - 1) / 2

	// The formula for m choose 2 is m * (m - 1) / 2
	// Add this value to the answer

	// Output the final answer, which is the sum of combinations from n and m
	fmt.Println(ans)
}

// <END-OF-CODE>
