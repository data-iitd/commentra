package main

import (
	"fmt"
)

func main() {
	var a, b, c int // Declare three integer variables named a, b, and c.
	fmt.Scan(&a, &b, &c) // Read three integers from the standard input and assign them to the variables a, b, and c.

	// The following if statement checks if any of the following conditions are true:
	// (a + b) == c // If the sum of a and b is equal to c
	// (b + c) == a // If the sum of b and c is equal to a
	// (a + c) == b // If the sum of a and c is equal to b
	if (a+b == c) || (b+c == a) || (a+c == b) { // If any of the above conditions are true, the following code is executed.
		fmt.Println("Yes") // Output the string "Yes" to the standard output.
	} else { // If none of the above conditions are true, the following code is executed.
		fmt.Println("No") // Output the string "No" to the standard output.
	}
}

// <END-OF-CODE>
