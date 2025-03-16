package main

import (
	"fmt"
)

func main() {
	// Define the modulo constant
	const mod = 1000000007

	// Read input values: N (total items), A (items of type A), B (items of type B)
	var N, A, B int
	fmt.Scan(&N, &A, &B)

	// Initialize the answer variable
	ans := 0

	// Calculate how many complete cycles of (A + B) fit into N
	rep := N / (A + B)

	// Add the total items of type A from the complete cycles to the answer
	ans += rep * A

	// Calculate the remaining items after complete cycles
	res := N - rep*(A+B)

	// Add the minimum of remaining items or A to the answer
	if res < A {
		ans += res
	} else {
		ans += A
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
