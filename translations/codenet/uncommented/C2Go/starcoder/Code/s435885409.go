package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func calc_score() int {
	var out int
	var str string
	var score int
	var base int

	for out < 3 {
		fmt.Scanf("%s", &str)
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

	fmt.Scanf("%d", &n)

	for inning < n {
		fmt.Printf("%d\n", calc_score())
		inning++
	}
}

