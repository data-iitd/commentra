package main // Step 1: Define the main package.

import ( // Step 2: Import the necessary packages.
	"fmt" // For formatted I/O.
)

func main() { // Step 3: Define the main function.
	var a, b int // Step 4: Declare two integer variables a and b.
	fmt.Scanf("%d %d", &a, &b) // Step 5: Read two integers from the user input.
	if 500*a >= b { // Step 6: Check if the product of 500 and a is greater than or equal to b.
		fmt.Println("Yes") // Step 7: Print "Yes" if the condition is true.
	} else {
		fmt.Println("No") // Step 8: Print "No" if the condition is false.
	}
} // Step 9: End the main function.
