package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var chonda, yamagami int
	var null string
	top := 0
	kinbo := make([]int, 1000)

	for {
		_, err := fmt.Scanf("%s", &null)
		if err == os.EOF {
			break
		}
		if null[0] == '+' {
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if null[0] == '-' {
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if null[0] == '*' {
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else {
			push(atoi(null))
		}
	}
	fmt.Printf("%d\n", pop())
}

func push(chonda int) {
	top++
	kinbo[top] = chonda
}

func pop() int {
	top--
	return kinbo[top+1]
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

