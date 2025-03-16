package main

import (
	"fmt"
)

func main() {
	var a, b int
	var S rune

	// Infinite loop to continuously take input and perform operations
	for {
		// Take input in the format a S b
		_, err := fmt.Scanf("%d %c %d", &a, &S, &b)
		if err != nil {
			break
		}

		// Perform operations based on the value of S
		switch S {
		case '+':
			fmt.Println(a + b)
		case '-':
			fmt.Println(a - b)
		case '*':
			fmt.Println(a * b)
		case '/':
			if b != 0 {
				fmt.Println(a / b)
			} else {
				fmt.Println("Division by zero")
			}
		case '?':
			return
		}
	}
}

// <END-OF-CODE>
