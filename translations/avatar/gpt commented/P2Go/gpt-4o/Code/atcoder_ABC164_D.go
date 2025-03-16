package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	const l = 2019

	// Read input string
	fmt.Scan(&s)

	// Initialize a slice to count occurrences of remainders, and variables for accumulated value and result
	m := make([]int, l)
	m[0] = 1
	a, r := 0, 0

	// Iterate over the input string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		e := s[i] - '0' // Convert character to integer
		a += int(e) * int(math.Pow(10, float64(len(s)-1-i))) % l

		// Update the result 'r' by adding the count of occurrences of the current remainder
		r += m[a%l]

		// Increment the count of the current remainder in the slice 'm'
		m[a%l]++
	}

	// Print the final result
	fmt.Println(r)
}

// <END-OF-CODE>
