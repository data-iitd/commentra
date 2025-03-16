package main

import (
	"fmt"
)

func main() {
	// Input the value of h
	var h int64
	fmt.Scan(&h)

	// Define constants and variables
	var ans, cnt int64 = 0, 1

	// Loop to calculate the answer
	for h != 1 {
		if h%2 != 0 {
			h-- // Decrement h if it is odd
		}
		h /= 2 // Divide h by 2
		cnt *= 2 // Double the count
		ans += cnt // Increment the sum by the current count
	}

	// Output the final result
	fmt.Println(ans + 1)
}

// <END-OF-CODE>
