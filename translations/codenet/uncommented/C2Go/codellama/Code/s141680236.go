package main

import (
	"fmt"
	"os"
	"strconv"
)

var top int
var kinbo [1000]int

func push(chonda int) {
	kinbo[top] = chonda
	top++
}

func pop() int {
	top--
	return kinbo[top]
}

func main() {
	top = 0
	var chonda, yamagami int
	var null string

	for {
		_, err := fmt.Scan(&null)
		if err != nil {
			if err == os.EOF {
				break
			}
			fmt.Println(err)
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
			push(strconv.Atoi(null))
		}
	}

	fmt.Println(pop())
}

