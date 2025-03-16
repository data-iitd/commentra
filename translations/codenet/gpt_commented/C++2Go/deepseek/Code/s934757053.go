package main

import (
	"fmt"
)

func main() {
	// Declare variables A and B to hold input values
	var A, B int
	// Initialize ans to count the number of iterations
	var ans int
	// Initialize out to 1, which will be used in the loop
	out := 1

	// Read input values for A and B from the user
	fmt.Scan(&A, &B)

	// Loop until out is less than B
	for out < B {
		// Decrement out by 1
		out--
		// Increment out by the value of A
		out += A
		// Increment the answer counter for each iteration
		ans++
	}

	// Output the final count of iterations
	fmt.Println(ans)
}

