package main

import "fmt"

// Declare variables a, b, c, d, and e of type int
var a, b, c, d, e int

// Read input values for variables a, b, c, d, and e from the standard input
fmt.Scan(&a, &b, &c, &d, &e)

// Create a slice named al with the values of variables a, b, c, d, and e
al := []int{a, b, c, d, e}

// Iterate through each element i in the slice al starting from the index 0
for n, i := range al {
	// Assign the index number n and the current element i to the variables n and i respectively
	// Check if the current element i is equal to 0
	if i == 0 {
		// Print the index number n+1 as output
		fmt.Println(n + 1)
		// Break the loop as soon as the first zero element is found
		break
	}
}