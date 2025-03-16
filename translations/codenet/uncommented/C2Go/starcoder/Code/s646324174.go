package main

import "fmt"

func main() {
	var a, b int
	var s string
	top := 0
	for {
		_, err := fmt.Scanf("%s", &s)
		if err!= nil {
			break
		}
		if s[0] == '+' {
			b = pop()
			a = pop()
			push(a + b)
		} else if s[0] == '-' {
			b = pop()
			a = pop()
			push(a - b)
		} else if s[0] == '*' {
			b = pop()
			a = pop()
			push(a * b)
		} else {
			push(atoi(s))
		}
	}
	fmt.Printf("%d\n", pop())
}

func push(x int) {
	S[top] = x
	top++
}

func pop() int {
	top--
	return S[top]
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

