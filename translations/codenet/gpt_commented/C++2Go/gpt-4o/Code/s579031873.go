package main

import (
	"fmt"
)

func main() {
	// Read the number of items (N) and the total amount (X)
	var N, X int64
	fmt.Scan(&N, &X)

	// Initialize the answer and minimum value variables
	ans := int64(0) // Counter for the number of items processed
	min := int64(1000000000) // Initialize min to a large value

	// Process each item
	for i := int64(0); i < N; i++ {
		var tmp int64 // Temporary variable to hold the current item's value
		fmt.Scan(&tmp) // Read the current item's value
		X -= tmp // Subtract the item's value from total amount X
		ans++ // Increment the count of items processed
		if tmp < min {
			min = tmp // Update min if the current item is smaller
		}
	}

	// Calculate how many more items can be added using the remaining amount
	ans += X / min // Add the number of additional items that can be bought

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
