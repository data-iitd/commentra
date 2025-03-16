package main

import (
	"fmt"
)

func main() {
	// Setting the modulus value
	mod := 1000000007

	// Reading input values: N, A, and B
	var N, A, B int
	fmt.Scan(&N, &A, &B)

	// Initializing the answer variable to 0
	ans := 0

	// Calculating the number of repetitions
	rep := N / (A + B)

	// Adding the number of blocks that can be fully covered by A and B in one repetition
	ans += rep * A

	// Calculating the remaining number of blocks
	res := N - rep*(A+B)

	// Adding the number of blocks that can be covered by A in the remaining blocks
	if res < A {
		ans += res
	} else {
		ans += A
	}

	// Printing the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
