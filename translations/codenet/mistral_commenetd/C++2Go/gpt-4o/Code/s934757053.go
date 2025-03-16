package main

import (
	"fmt"
)

func main() {
	var A, B int // Declare variables A and B to store input values
	ans := 0    // Initialize answer variable ans to 0
	out := 1    // Initialize counter variable out to 1

	// Read values of A and B from standard input
	fmt.Scan(&A, &B)

	// Use a while loop to find the number of times A can be added to get a value greater than or equal to B
	for out < B {
		out--    // Decrement out by 1
		out += A // Increment out by A
		ans++    // Increment ans by 1 each time the loop runs
	}

	// Display the answer
	fmt.Printf("The answer is: %d\n", ans)

	// Return 0 to indicate successful execution
}
