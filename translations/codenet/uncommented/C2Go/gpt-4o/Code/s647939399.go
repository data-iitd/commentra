package main

import (
	"fmt"
)

func main() {
	var m rune
	var a, b int
	var c [256]int
	i := 0

	for {
		_, err := fmt.Scanf("%d %c %d", &a, &m, &b)
		if err != nil || m == '?' {
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

	for j := 0; j < i; j++ {
		fmt.Println(c[j])
	}
}

// <END-OF-CODE>
