package main

import (
	"fmt" // Step 1: Include the standard input/output library.
)

func main() { // Step 2: Define the main function.
	var a, b int // Step 3: Declare two integer variables a and b.
	fmt.Scan(&a, &b) // Step 4: Read two integers from the user input.
	if 500*a >= b { // Step 5: Check if the product of 500 and a is greater than or equal to b.
		fmt.Println("Yes") // Step 6: Print "Yes" if the condition is true.
	} else {
		fmt.Println("No") // Step 7: Print "No" if the condition is false.
	}
}
