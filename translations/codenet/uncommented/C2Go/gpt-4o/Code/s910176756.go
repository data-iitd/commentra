package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	var op rune

	for {
		_, err := fmt.Scanf("%d %c %d", &a, &op, &b)
		if err != nil {
			break
		}

		switch op {
		case '+':
			c = a + b
			fmt.Println(c)
		case '-':
			c = a - b
			fmt.Println(c)
		case '*':
			c = a * b
			fmt.Println(c)
		case '/':
			c = a / b
			fmt.Println(c)
		default:
			return
		}
	}
}

// <END-OF-CODE>
