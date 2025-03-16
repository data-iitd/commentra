package main

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var a, b int // Declare variables a and b

	fmt.Scan(&a) // Read the first integer value from user input
	fmt.Scan(&b) // Read the second integer value from user input

	res := a // Initialize the result variable with the value of 'a'

	for a >= b { // Start a for loop that continues as long as 'a' is greater than or equal to 'b'
		res += a / b // Increment the result variable by the result of dividing 'a' by 'b'
		a = (a / b) + (a % b) // Update the value of 'a' with the result of the division and the remainder
	}

	fmt.Println(res) // Print the value of the result variable to the standard output stream
}

// <END-OF-CODE>
