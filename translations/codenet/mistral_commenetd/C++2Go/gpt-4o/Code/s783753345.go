package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var a, b int // Declare two integer variables 'a' and 'b'
	var S byte   // Declare a byte variable 'S' for the operator

	// A for loop that runs indefinitely until the user enters '?' to exit
	for {
		_, err := fmt.Scanf("%d %c %d", &a, &S, &b) // Read an integer 'a', a character 'S', and an integer 'b' from the standard input
		if err != nil { // Check for input errors
			break // Exit the loop if there's an error
		}

		// Perform arithmetic operations based on the operator 'S'
		switch S {
		case '+':
			fmt.Println(a + b) // If 'S' is '+', print the sum of 'a' and 'b'
		case '-':
			fmt.Println(a - b) // If 'S' is '-', print the difference of 'a' and 'b'
		case '*':
			fmt.Println(a * b) // If 'S' is '*', print the product of 'a' and 'b'
		case '/':
			if b != 0 { // Check for division by zero
				fmt.Println(a / b) // If 'S' is '/', print the quotient of 'a' and 'b'
			} else {
				fmt.Println("Error: Division by zero") // Handle division by zero
			}
		case '?':
			return // If 'S' is '?', exit the program
		default:
			fmt.Println("Error: Invalid operator") // Handle invalid operator
		}
	}
}
