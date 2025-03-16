package main

import (
	"fmt"
)

func main() {
	var x int // Step 3: Declare an integer variable x.
	fmt.Scanf("%d", &x) // Step 4: Read an integer value from the user and store it in x.
	x = x * x * x // Step 5: Calculate the cube of the value stored in x.
	fmt.Println(x) // Step 6: Print the result.

	// Step 7: End the main function and return 0 (implicit in Go).
}

// <END-OF-CODE>
