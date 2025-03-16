
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	top = 0
	S = make([]int, 10000)

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s = scanner.Text()
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
	fmt.Println(pop())
	// 