package main

import (
	"fmt"
)

func main() {
	// Read the first integer `T` from the input
	var T int
	fmt.Scan(&T)

	// Read the second integer `S` from the input
	var S int
	fmt.Scan(&S)

	// Read the third integer `q` from the input
	var q int
	fmt.Scan(&q)

	// Initialize the variable `previous` with the value of `S`
	previous := int64(S)

	// Initialize the variable `answer` with the value of 0
	answer := 0

	// Start a while loop that continues as long as `previous` is less than `T`
	for previous < int64(T) {
		// Increment the value of `answer` by 1
		answer++

		// Multiply the value of `previous` by `q`
		previous *= int64(q)
	}

	// Print the value of `answer` to the standard output stream
	fmt.Println(answer)
}

// <END-OF-CODE>
