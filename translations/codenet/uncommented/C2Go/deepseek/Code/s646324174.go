package main

import (
	"fmt"
	"os"
	"strconv"
)

var top int
var S []int

func push(x int) {
	S = append(S, x)
	top++
}

func pop() int {
	top--
	return S[top]
}

func main() {
	var a, b int
	var s string
	S = make([]int, 10000)
	top = 0

	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			if err == os.ErrEOF {
				break
			}
		}

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
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}
	fmt.Println(pop())
}

