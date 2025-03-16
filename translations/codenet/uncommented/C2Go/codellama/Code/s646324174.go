package main

import (
	"fmt"
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
		fmt.Scan(&s)
		if s == "+" {
			b = pop()
			a = pop()
			push(a + b)
		} else if s == "-" {
			b = pop()
			a = pop()
			push(a - b)
		} else if s == "*" {
			b = pop()
			a = pop()
			push(a * b)
		} else {
			push(strconv.Atoi(s))
		}
	}
	fmt.Println(pop())
}

