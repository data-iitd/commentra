package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	numbers := strings.Split(input, " ")
	var a, b int
	for i, num := range numbers {
		val, _ := strconv.Atoi(num)
		if i == 0 {
			a = val
		} else {
			b = val
		}
	}

	minValue := min(a, b)
	maxValue := max(a, b)

	diff := maxValue - minValue
	averageDiff := diff / 2

	fmt.Println(minValue, averageDiff)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

