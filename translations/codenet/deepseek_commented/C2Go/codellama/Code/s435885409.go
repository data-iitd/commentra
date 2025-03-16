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

	// Read the number of outs and update the score and base accordingly
	for out < 3 {
		fmt.Scan(&str)
		if str == "OUT" {
			out++
		} else if str == "HIT" {
			if base == 3 {
				score++
			} else {
				base++
			}
		} else if str == "HOMERUN" {
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

	// Loop through each inning and calculate the score
	for inning < n {
		fmt.Println(calcScore())
		inning++
	}
}

