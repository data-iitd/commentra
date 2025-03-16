package main

import (
	"fmt"
)

func main() {
	// Reading two integers from the user
	var a, b int
	fmt.Scan(&a, &b) // The initial amount and the divisor
	
	// Initializing the result with the value of 'a'
	res := a
	
	// Loop to perform the division and accumulate the result
	for a >= b {
		// Add the quotient of a divided by b to the result
		res += (a / b)
		
		// Update 'a' to be the sum of the quotient and the remainder
		a = (a / b) + (a % b)
	}
	
	// Output the final result
	fmt.Println(res)
}
