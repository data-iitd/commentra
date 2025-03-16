package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	var op byte
	for {
		fmt.Scanf("%d %c %d", &a, &op, &b)
		if op == '+' {
			c = a + b
			fmt.Println(c)
		} else if op == '-' {
			c = a - b
			fmt.Println(c)
		} else if op == '*' {
			c = a * b
			fmt.Println(c)
		} else if op == '/' {
			c = a / b
			fmt.Println(c)
		} else {
			break
		}
	}
}

