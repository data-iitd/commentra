package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// calcScore calculates the score based on user input
func calcScore() int {
	var out int
	var str string
	var score int
	var base int

	// Loop until there are 3 outs
	for out < 3 {
		str = readInput()

		// Check if the input is "OUT"
		if str == "OUT" {
			out++
		} else if str == "HIT" {
			// If all bases are occupied, score a point
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

// readInput reads user input
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func main() {
	var n int
	var inning int

	n, _ = strconv.Atoi(readInput())

	// Loop through the number of innings
	for inning < n {
		fmt.Println(calcScore())
		inning++
	}
}

