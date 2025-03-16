package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	var op byte

	for {
		fmt.Scanf("%d %c %d", &a, &op, &b)
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
			break
		}
	}
}

