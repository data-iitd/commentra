package main

import (
	"fmt"
)

func main() {
	var a, b int
	var S byte

	for {
		fmt.Scanf("%d %c %d", &a, &S, &b)

		switch S {
		case '+':
			fmt.Println(a + b)
		case '-':
			fmt.Println(a - b)
		case '*':
			fmt.Println(a * b)
		case '/':
			fmt.Println(a / b)
		case '?':
			return
		}
	}
}

