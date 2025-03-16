package main

import (
	"fmt"
	"os"
	"strconv"
)

var top int
var S [10000]int

func push(x int) {
	S[top] = x
	top++
}

func pop() int {
	top--
	return S[top]
}

func main() {
	var a, b int
	var s string
	top = 0

	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break
		}
		switch s[0] {
		case '+':
			b = pop()
			a = pop()
			push(a + b)
		case '-':
			b = pop()
			a = pop()
			push(a - b)
		case '*':
			b = pop()
			a = pop()
			push(a * b)
		default:
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}
	fmt.Println(pop())
}

// <END-OF-CODE>
