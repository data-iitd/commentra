package main

import (
	"fmt"
)

func main() {
	// Read three integers from the input: T, S, and q
	var T, S, q int
	fmt.Scan(&T, &S, &q)
	
	previous := S
	answer := 0
	
	// Loop until 'previous' is less than 'T'
	for previous < T {
		answer++ // Increment the answer counter
		previous *= q // Multiply 'previous' by 'q' for the next iteration
	}
	
	// Output the final count of how many times 'previous' was multiplied before reaching 'T'
	fmt.Println(answer)
}
