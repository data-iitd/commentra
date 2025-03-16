package main

import (
	"fmt"
)

func main() {
	var A, B, flag int

	// Read two integers from the standard input and store them in variables A and B
	fmt.Scan(&A, &B)

	// Iterate from 1 to 3 using a for loop
	for i := 1; i <= 3; i++ {
		// Check if the product of A, B, and the loop counter i is odd
		if (A*B*i)%2 == 1 {
			// Set the flag variable to 1 if the condition is true
			flag = 1
			// Break out of the loop if the condition is true
			break
		}
	}

	// Check the value of the flag variable
	if flag != 0 {
		// Print "Yes" to the standard output if the flag variable is 1
		fmt.Println("Yes")
	} else {
		// Print "No" to the standard output if the flag variable is 0
		fmt.Println("No")
	}
}

