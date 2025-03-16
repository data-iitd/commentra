package main

import (
	"fmt"
	"strconv"
)

var top int
var kinbo []int

func push(chonda int) {
	top++
	kinbo[top] = chonda
}

func pop() int {
	top--
	return kinbo[top+1]
}

func main() {
	var chonda, yamagami int
	var null string

	kinbo = make([]int, 1000)
	top = 0

	for {
		fmt.Scan(&null)
		if null == "+" {
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if null == "-" {
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if null == "*" {
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else {
			chonda, _ = strconv.Atoi(null)
			push(chonda)
		}
		if null == "EOF" {
			break
		}
	}

	fmt.Println(pop())
}

