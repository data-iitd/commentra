package main

import (
	"fmt"
	"os"
	"strconv"
)

var top int
var kinbo [1000]int

func push(chonda int) {
	top++
	kinbo[top] = chonda
}

func pop() int {
	top--
	return kinbo[top+1]
}

func main() {
	top = 0
	var null string

	for {
		_, err := fmt.Scan(&null)
		if err != nil {
			break
		}

		switch null[0] {
		case '+':
			chonda := pop()
			yamagami := pop()
			push(chonda + yamagami)
		case '-':
			yamagami := pop()
			chonda := pop()
			push(chonda - yamagami)
		case '*':
			chonda := pop()
			yamagami := pop()
			push(chonda * yamagami)
		default:
			num, _ := strconv.Atoi(null)
			push(num)
		}
	}

	fmt.Println(pop())
}

// <END-OF-CODE>
