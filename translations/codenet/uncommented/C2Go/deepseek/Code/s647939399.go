package main

import (
	"fmt"
)

func main() {
	var a, b int
	var m byte
	var c []int
	for {
		fmt.Scanf("%d %c %d", &a, &m, &b)
		if m == '?' {
			break
		}
		switch m {
		case '+':
			c = append(c, a+b)
		case '-':
			c = append(c, a-b)
		case '*':
			c = append(c, a*b)
		case '/':
			c = append(c, a/b)
		}
	}
	for _, v := range c {
		fmt.Println(v)
	}
}

