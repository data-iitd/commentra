package main

import "fmt"

func main() {
	var m rune
	var a, b, i, j int
	c := make([]int, 256)

	for {
		fmt.Scanf("%d %c %d", &a, &m, &b)
		if m == '?' {
			break
		}
		if m == '+' {
			c[i] = a + b
		}
		if m == '-' {
			c[i] = a - b
		}
		if m == '*' {
			c[i] = a * b
		}
		if m == '/' {
			c[i] = a / b
		}
		i++
	}

	for j = 0; j < i; j++ {
		fmt.Println(c[j])
	}
}

