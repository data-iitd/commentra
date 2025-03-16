package main

import (
	"fmt"
	"strings"
)

func calcScore() int {
	out := 0
	var str string
	score := 0
	base := 0

	// Read the number of outs and update the score and base accordingly
	for out < 3 {
		fmt.Scan(&str)
		if strings.EqualFold(str, "OUT") {
			out++
		} else if strings.EqualFold(str, "HIT") {
			if base == 3 {
				score++
			} else {
				base++
			}
		} else if strings.EqualFold(str, "HOMERUN") {
			score += (base + 1)
			base = 0
		}
	}

	return score
}

func main() {
	var n int
	inning := 0

	fmt.Scan(&n)

	// Loop through each inning and calculate the score
	for inning < n {
		fmt.Println(calcScore())
		inning++
	}
}

// <END-OF-CODE>
