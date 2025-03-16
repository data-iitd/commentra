package main

import (
	"fmt"
)

func main() {
	var a, b int
	var S rune

	for {
		_, err := fmt.Scanf("%d %c %d", &a, &S, &b)
		if err != nil {
			break
		}

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
		default:
			fmt.Println("Invalid operation")
		}
	}
}

// <END-OF-CODE>
