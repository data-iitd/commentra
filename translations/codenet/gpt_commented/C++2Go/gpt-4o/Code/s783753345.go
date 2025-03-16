package main

import (
	"fmt"
)

func main() {
	var a, b int
	var S rune

	// Start an infinite loop to continuously accept user input
	for {
		// Read two integers and an operator from the user
		_, err := fmt.Scanf("%d %c %d", &a, &S, &b)
		if err != nil {
			fmt.Println("Invalid input. Please enter in the format: <int> <operator> <int>")
			continue
		}

		// Perform addition if the operator is '+'
		if S == '+' {
			fmt.Println(a + b)
		}

		// Perform subtraction if the operator is '-'
		if S == '-' {
			fmt.Println(a - b)
		}

		// Perform multiplication if the operator is '*'
		if S == '*' {
			fmt.Println(a * b)
		}

		// Perform division if the operator is '/'
		if S == '/' {
			if b != 0 {
				fmt.Println(a / b)
			} else {
				fmt.Println("Error: Division by zero")
			}
		}

		// Exit the loop if the operator is '?'
		if S == '?' {
			break
		}
	}
}

// <END-OF-CODE>
