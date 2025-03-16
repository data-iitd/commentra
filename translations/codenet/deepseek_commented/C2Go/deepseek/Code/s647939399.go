package main

import (
	"fmt"
)

func main() {
	var a, b int
	var m byte
	var c [256]int
	var i, j int

	for {
		fmt.Scanf("%d %c %d", &a, &m, &b)
		if m == '?' {
			break
		}
		switch m {
		case '+':
			c[i] = a + b
		case '-':
			c[i] = a - b
		case '*':
			c[i] = a * b
		case '/':
			c[i] = a / b
		}
		i++
	}

	for j = 0; j < i; j++ {
		fmt.Println(c[j])
	}
}

