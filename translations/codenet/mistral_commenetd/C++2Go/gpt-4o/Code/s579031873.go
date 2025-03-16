package main

import (
	"fmt"
)

func main() {
	var N, X int64 // Declare two int64 variables named "N" and "X".

	fmt.Scan(&N, &X) // Read two integers from the standard input stream and assign them to "N" and "X" respectively.

	ans := int64(0) // Initialize an int64 variable named "ans" to zero.
	min := int64(1000000000) // Initialize an int64 variable named "min" to a large value.

	for i := int64(0); i < N; i++ { // Start of a for loop that iterates from 0 to N-1.
		var tmp int64 // Declare an int64 variable named "tmp".

		fmt.Scan(&tmp) // Read an integer from the standard input stream and assign it to "tmp".

		X -= tmp // Subtract "tmp" from "X".
		ans++ // Increment "ans" by 1.

		if tmp < min { // If "tmp" is smaller than the current minimum value, update the minimum value.
			min = tmp
		}
	}

	ans += X / min // Divide "X" by the minimum value and add the quotient to "ans".

	fmt.Println(ans) // Output the value of "ans" to the standard output stream.
}

// <END-OF-CODE>
