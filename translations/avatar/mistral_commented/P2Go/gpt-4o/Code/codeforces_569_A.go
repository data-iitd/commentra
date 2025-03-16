package main

import (
	"fmt"
)

func main() {
	// Take three integers as input from the user and store them in variables t, s, and q respectively
	var t, s, q int
	fmt.Scan(&t, &s, &q)

	// Initialize an answer counter variable ans to 0
	ans := 0

	// Loop while the value of s is less than t
	for s < t {
		// Multiply the value of s by q and update the value of s
		s *= q

		// Increment the answer counter variable ans by 1
		ans++
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
