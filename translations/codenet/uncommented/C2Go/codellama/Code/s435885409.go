package main

import (
	"fmt"
	"strings"
)

func calcScore() int {
	var out int
	var str string
	var score int
	var base int

	for out < 3 {
		fmt.Scan(&str)
		if strings.Compare(str, "OUT") == 0 {
			out++
		} else if strings.Compare(str, "HIT") == 0 {
			if base == 3 {
				score++
			} else {
				base++
			}
		} else if strings.Compare(str, "HOMERUN") == 0 {
			score += (base + 1)
			base = 0
		}
	}

	return score
}

func main() {
	var n int
	var inning int

	fmt.Scan(&n)

	for inning < n {
		fmt.Println(calcScore())
		inning++
	}
}

