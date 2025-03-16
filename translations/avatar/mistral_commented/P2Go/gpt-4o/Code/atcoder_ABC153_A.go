package main

import (
	"fmt"
)

func main() {
	var h, a int
	fmt.Scan(&h, &a)
	// Assign the first and second elements of the input string to variables h and a, respectively

	sho := h / a
	// Calculate the quotient of h by a and assign the result to the variable sho

	am := h % a
	// Calculate the remainder of the division of h by a and assign the result to the variable am

	if am != 0 {
		// Check if the remainder is equal to zero
		// If not, execute the following block of code
		sho++
		// Increment the value of the variable sho by one
	}

	fmt.Println(sho)
	// Print the value of the variable sho
}

// <END-OF-CODE>
