package main

import (
	"fmt"
	"math"
)

func main() {
	// Define input variables 's' and 'l'
	var s string
	var l = 2019
	fmt.Scan(&s)

	// Initialize slice 'm' with initial value 1 for index 0 and zeros for other indices
	m := make([]int, l+1)
	m[0] = 1

	// Initialize variables 'a' and 'r' with zero values
	a, r := 0, 0

	// Iterate through the string 's' in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		e := s[i] - '0' // Convert character to integer

		// Calculate the current digit's power and add it to 'a'
		a += int(e) * int(math.Pow(10, float64(len(s)-1-i))) % l

		// Increment the index 'a % l' in slice 'm'
		m[a%l]++

		// Update 'r' with the current sum
		r += m[a%l]
	}

	// Print the final result 'r'
	fmt.Println(r)
}

// <END-OF-CODE>
