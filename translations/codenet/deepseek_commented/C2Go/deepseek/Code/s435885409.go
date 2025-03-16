package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func calcScore() int {
	out := 0
	var str string
	score := 0
	base := 0

	// Read the number of outs and update the score and base accordingly
	for out < 3 {
		reader := bufio.NewReader(os.Stdin)
		str, _ = reader.ReadString('\n')
		str = strings.TrimSpace(str)

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

