package main // Step 1: Define the main package

import (
	"fmt" // Step 2: Import the fmt package for formatted I/O
)

func main() { // Step 3: Define the main function
	var x int // Step 4: Declare an integer variable
	fmt.Scanf("%d", &x) // Step 5: Read an integer value from the user

	if x == 1 { // Step 6: Implement a simple if-else statement
		fmt.Println("0") // Print 0 if the input is 1
	} else {
		fmt.Println("1") // Print 1 if the input is not 1
	}
} // Step 7: End of the main function

// <END-OF-CODE>
