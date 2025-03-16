package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a) // Read the first integer input
	fmt.Scan(&b) // Read the second integer input
	res := a     // Initialize result variable with the value of a

	// Enter a while loop that continues as long as a is greater than or equal to b
	for a >= b {
		res += a / b // Update result by adding the integer division of a by b
		a = (a / b) + (a % b) // Update a to be the sum of the integer division and remainder
	}

	fmt.Println(res) // Print the final value of res
}

// <END-OF-CODE>
