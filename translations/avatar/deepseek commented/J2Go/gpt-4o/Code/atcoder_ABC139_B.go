package main

import (
	"fmt"
)

func main() {
	// Step 1: Create a variable to store input.
	var A, B int

	// Step 2: Read the first integer A from the input.
	fmt.Scan(&A)

	// Step 3: Read the second integer B from the input.
	fmt.Scan(&B)

	// Step 4: Initialize variables to store the quotient and remainder.
	var amari, result int

	// Step 5: Calculate the quotient (result) by dividing (B-1) by (A-1).
	result = (B - 1) / (A - 1)

	// Step 6: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
	amari = (B - 1) % (A - 1)

	// Step 7: If the remainder is not zero, increment the result by 1.
	if amari != 0 {
		result++
	}

	// Step 8: Print the result to the standard output.
	fmt.Println(result)
}

// <END-OF-CODE>
