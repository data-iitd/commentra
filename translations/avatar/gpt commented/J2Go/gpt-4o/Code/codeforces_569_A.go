package main

import (
	"fmt"
)

func main() {
	// Read three integers from the input: T, S, and q
	var T, S, q int
	fmt.Scan(&T, &S, &q) // The upper limit, the starting value, and the multiplier

	previous := S // Initialize 'previous' with the starting value S
	answer := 0   // Initialize the answer counter

	// Loop until 'previous' is less than 'T'
	for previous < T {
		answer++      // Increment the answer counter
		previous *= q // Multiply 'previous' by 'q' for the next iteration
	}

	// Output the final count of how many times 'previous' was multiplied before reaching 'T'
	fmt.Println(answer)
}

// <END-OF-CODE>
