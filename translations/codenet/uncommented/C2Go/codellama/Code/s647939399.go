package main

import "fmt"

func main() {
	var m rune
	var a, b, c [256]int
	var i, j int
	for i = 0; i > -1; i++ {
		fmt.Scanf("%d %c %d", &a[i], &m, &b[i])
		if m == '?' {
			break
		}
		if m == '+' {
			c[i] = a[i] + b[i]
		}
		if m == '-' {
			c[i] = a[i] - b[i]
		}
		if m == '*' {
			c[i] = a[i] * b[i]
		}
		if m == '/' {
			c[i] = a[i] / b[i]
		}
	}
	for j = 0; j < i; j++ {
		fmt.Println(c[j])
	}
}

