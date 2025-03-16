package main

import (
	"fmt"
)

func main() {
	// Initialize a Scanner object to read input from the standard input stream
	var T, S, q int
	fmt.Scan(&T, &S, &q)

	// Initialize the variable `previous` with the value of `S`
	previous := S

	// Initialize the variable `answer` with the value of 0
	answer := 0

	// Start a while loop that continues as long as `previous` is less than `T`
	for previous < T {
		// Increment the value of `answer` by 1
		answer++

		// Multiply the value of `previous` by `q`
		previous *= q
	}

	// Print the value of `answer` to the standard output stream
	fmt.Println(answer)
}
